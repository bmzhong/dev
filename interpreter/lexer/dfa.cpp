#ifndef _THIS_IS_DFA_CPP
#define _THIS_IS_DFA_CPP
#include "lexer.hpp"
#include <map>
using namespace std;
struct From
{
    int state;
    char character;
    From() {
	}
    From(int _state, char _character)
    {
        state = _state;
        character = _character;
    }
    bool operator<(const From &from) const
    {
        if (state == from.state)
        {
            return character < from.character;
        }
        return state < from.state;
    }
};
struct NextState
{
    int state = -1;
    NextState(int _state = -1)
    {
        state = _state;
    }
};

struct StateType{
    Token_Type token=ERRTOKEN;
    StateType(Token_Type _token=ERRTOKEN){
        token=_token;
    }
};

map<From, NextState> moveTable;

typedef int finalState;
map<finalState,StateType> finalStateTable;

void initMoveTable()
{
    moveTable[From(0, 'a')] = NextState(1);
    moveTable[From(0, '0')] = NextState(2);
    moveTable[From(0, '*')] = NextState(4);
    moveTable[From(0, '/')] = NextState(6);
    moveTable[From(0, '-')] = NextState(7);
    moveTable[From(0, '+')] = NextState(8);
    moveTable[From(0, ',')] = NextState(9);
    moveTable[From(0, ';')] = NextState(10);
    moveTable[From(0, '(')] = NextState(11);
    moveTable[From(0, ')')] = NextState(12);
    moveTable[From(1, 'a')] = NextState(1);
    moveTable[From(1, '0')] = NextState(1);
    moveTable[From(2, '0')] = NextState(2);
    moveTable[From(2, '.')] = NextState(3);
    moveTable[From(3, '0')] = NextState(3);
    moveTable[From(4, '*')] = NextState(5);
    moveTable[From(6, '/')] = NextState(13);
    moveTable[From(7, '-')] = NextState(13);
}


void initFinalStateTable(){
    finalStateTable[1]=StateType(ID);
    finalStateTable[2]=StateType(CONST_ID);
    finalStateTable[3]=StateType(CONST_ID);

    finalStateTable[4]=StateType(MUL);
    finalStateTable[5]=StateType(POWER);
    finalStateTable[6]=StateType(DIV);
    finalStateTable[7]=StateType(MINUS);
    finalStateTable[8]=StateType(PLUS);
    finalStateTable[9]=StateType(COMMA);
    finalStateTable[10]=StateType(SEMICO);
    finalStateTable[11]=StateType(L_BRACKET);
    finalStateTable[12]=StateType(R_BRACKET);
    finalStateTable[13]=StateType(COMMENT);
}

struct DFA{
    int start_state;
    map<From, NextState> *moveTable;
    map<finalState,StateType> *finalStateTable;
};

DFA dfa={0,&moveTable,&finalStateTable};

void initDfa(){
    initFinalStateTable();
    initMoveTable();
}


int getStartState(){
    return dfa.start_state;
} 

Token_Type stateIsFinal(const int &state){
    return finalStateTable[state].token;
}

int move(const int &fromState,char character){
    if(character>='0'&&character<='9'){
        character='0';
    }else if(character>='a'&&character<='z'){
        character='a';
    }else if(character>='A'&&character<='Z'){
        character='a';
    }
    return  moveTable[From(fromState,character)].state;
}
#endif