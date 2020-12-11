#ifndef _THIS_IS_SEMANTICS_HPP
#define _THIS_IS_SEMANTICS_HPP
#include "../parser/parser.cpp"
void setOrigin(ExprNode *originXPtr, ExprNode *originYPtr);

void setScale(ExprNode *scaleXPtr, ExprNode *scaleYPtr);

void setRotate(ExprNode *anglePtr);

void drawLoop(ExprNode *startPtr, ExprNode *endPtr, ExprNode *stepPtr, ExprNode *dotXPtr, ExprNode *dotYPtr);

#endif