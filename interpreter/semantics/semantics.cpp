#include "semantics.hpp"
#include "../parser/parser.cpp"
#include <cmath>


double originX = 0, originY = 0, scaleX = 1, scaleY = 1, angle = 0;

double getExprNode(ExprNode *root) {
    if (NULL == root)
        return 0.0;
    switch (root->tokenType) {
        case PLUS:
            return getExprNode(root->left) + getExprNode(root->right);
        case MINUS:
            return getExprNode(root->left) - getExprNode(root->right);
        case MUL:
            return getExprNode(root->left) * getExprNode(root->right);
        case DIV:
            return getExprNode(root->left) / getExprNode(root->right);
        case POWER:
            return pow(getExprNode(root->left), getExprNode(root->right));
        case FUNC:
            return (*(root->funcPtr))(getExprNode(root->child));
        case CONST_ID:
            return root->constNumber;
        case T:
            return *(root->constParamPtr);
        default:
            return 0.0;
    }
}

void calcCoord(ExprNode *dotXPtr, ExprNode *dotYPtr, double &dotX, double &dotY) {
    dotX = getExprNode(dotXPtr);
    dotY = getExprNode(dotYPtr);
    dotX *= scaleX;
    dotY *= scaleY;
    double temp = dotX * cos(angle) + dotY * sin(angle);
    dotY = dotY * cos(angle) - dotX * sin(angle);
    dotX = temp;
    dotX += originX;
    dotY += originY;
}

void setOrigin(ExprNode *originXPtr, ExprNode *originYPtr) {
    originX = getExprNode(originXPtr);
    originY = getExprNode(originYPtr);
}

void setScale(ExprNode *scaleXPtr, ExprNode *scaleYPtr) {
    scaleX = getExprNode(scaleXPtr);
    scaleY = getExprNode(scaleYPtr);
}

void setRotate(ExprNode *anglePtr) {
    angle = getExprNode(anglePtr);
}

void drawLoop(ExprNode *startPtr, ExprNode *endPtr, ExprNode *stepPtr, ExprNode *dotXPtr, ExprNode *dotYPtr)
{
    double *T = getTAddress();
    double start = getExprNode(startPtr);
    double end = getExprNode(endPtr);
    double step = getExprNode(stepPtr);
    double dotX, dotY;
    for (*T = start; *T <= end; *T = *T + step) {
        calcCoord(dotXPtr, dotYPtr, dotX, dotY);
        drawPixel((unsigned long) dotX, (unsigned long) dotY,0);
    }
}