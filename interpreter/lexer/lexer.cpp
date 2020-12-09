#ifndef _THIS_IS_LEXER_CPP
#define _THIS_IS_LEXER_CPP
#include "lexer.hpp"
#include "dfa.cpp"
#include "../error/error.cpp"
#include <ctype.h>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
Token tokenTable[] = {
	{CONST_ID, "PI", 3.1415926, NULL},
	{CONST_ID, "E", 2.71828, NULL},
	{T, "T", 0.0, NULL},
	{FUNC, "SIN", 0.0, sin},
	{FUNC, "COS", 0.0, cos},
	{FUNC, "TAN", 0.0, tan},
	{FUNC, "LN", 0.0, log},
	{FUNC, "EXP", 0.0, exp},
	{FUNC, "SQRT", 0.0, sqrt},
	{ORIGIN, "ORIGIN", 0.0, NULL},
	{SCALE, "SCALE", 0.0, NULL},
	{ROT, "ROT", 0.0, NULL},
	{IS, "IS", 0.0, NULL},
	{FOR, "FOR", 0.0, NULL},
	{FROM, "FROM", 0.0, NULL},
	{TO, "TO", 0.0, NULL},
	{STEP, "STEP", 0.0, NULL},
	{DRAW, "DRAW", 0.0, NULL}};

ifstream in;

position currentPos;

bool initLexer(string filename)
{
	initDfa();
	currentPos.row = 1;
	currentPos.col = 0;
	in.open(filename.c_str());
	if (!in.is_open())
		return false;
	if (!initError())
		return false;
	return true;
}
void closeLexer()
{
	if (in.is_open())
		in.close();
	closeError();
}

char getChar()
{
	if (in.eof())
		return -1;
	int nextChar = in.get();
	if ('\n' == nextChar)
	{
		++(currentPos.row);
		currentPos.col = 0;
		return nextChar;
	}
	else
	{
		++(currentPos.col);
		return toupper(nextChar);
	}
}

void backChar(char nextChar)
{
	if (nextChar == EOF || nextChar == '\n')
		return;
	in.putback(nextChar);
	--(currentPos.col);
}

Token judegeTokenTable(const char *c_str)
{
	int length = sizeof(tokenTable) / sizeof(tokenTable[0]);
	for (int i = 0; i < length; ++i)
	{
		if (strcmp(tokenTable[i].lexeme, c_str) == 0)
			return tokenTable[i];
	}
	Token errorToken;
	//	memset(&errorToken, 0, sizeof(errorToken));
	errorToken.type = ERRTOKEN;
	return errorToken;
}

int appendTokenLexeme(Token *token, char nextChar)
{
	int len = strlen(token->lexeme);
	if (len + 1 >= sizeof(token->lexeme))
		return -1;
	token->lexeme[len] = nextChar;
	token->lexeme[len + 1] = '\0';
	return 0;
}

int preProcess(Token *currToken)
{
	currToken->type = ERRTOKEN;
	currToken->lexeme[0] = '\0';
	currToken->value = 0.0;
	currToken->funcptr = NULL;
	currToken->where = {0, 0};
	int currentChar;
	while (true)
	{
		currentChar = getChar();
		if (currentChar == -1)
			return -1;
		if (!isspace(currentChar))
			break;
	}
	return currentChar;
}

int scanMove(Token *currToken, char firstChar)
{
	int currentChar = firstChar;
	int currentState = getStartState();
	int nextState;
	while (true)
	{
		nextState = move(currentState, currentChar);
		if (nextState < 0)
		{
			if (currToken->lexeme[0] == '\0')
			{
				lexerError(currentChar, currentPos.row, currentPos.col);
			}
			else
			{
				backChar(currentChar);
			}
			break;
		}
		appendTokenLexeme(currToken, currentChar);
		currentState = nextState;
		currentChar = getChar();
		if (currentChar == -1)
			break;
	}
	return currentState;
}

bool postProcess(Token *currToken, int lastState)
{
	bool toBeContinue = false;
	Token_Type tokenType = stateIsFinal(lastState);
	switch (tokenType)
	{
	case ID:
	{
		Token theToken = judegeTokenTable(currToken->lexeme);
		if (theToken.type == ERRTOKEN)
			currToken->type = ERRTOKEN;
		else
		{
			//                    *currToken = theToken;
			currToken->type = theToken.type;
			currToken->value = theToken.value;
			currToken->funcptr = theToken.funcptr;
			int len = strlen(theToken.lexeme);
			for (int i = 0; i < len; ++i)
			{
				currToken->lexeme[i] = theToken.lexeme[i];
			}
			currToken->lexeme[len] = '\0';
		}
	}
	break;
	case CONST_ID:
		currToken->type = tokenType;
		currToken->value = atof(currToken->lexeme);
		break;
	case COMMENT:
		int ch;
		while (true)
		{
			ch = getChar();
			if (ch == '\n' || ch == -1)
				break;
		}
		toBeContinue = true;
		break;
	default:
		currToken->type = tokenType;
		break;
	}
	return toBeContinue;
}

Token getToken()
{
	int firstChar;
	int lastState;
	//	position where;
	Token currToken;
	bool toBeContinue;
	do
	{
		firstChar = preProcess(&currToken);
		if (firstChar == -1)
		{
			currToken.type = NONTOKEN;
			return currToken;
		}
		currToken.where = currentPos;
		lastState = scanMove(&currToken, firstChar);
		toBeContinue = postProcess(&currToken, lastState);
	} while (toBeContinue);
	//	currToken.where=where;
	return currToken;
}
#endif