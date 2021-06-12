/*
 * Calculator
 * Description:
 *				Inorder replace to postorder, print postfix and calcuate the postfix.
 * Using : Visutal Studio 2019
 * Programmer: Yooj
 * Date: 21.05.29
 */
#pragma once
#include "List.cpp"
#include "String.h"
using namespace std;

class Calculator
{
private:
	List<String> tokens;
	int errCode;
	int value;
	String postfix;

	int makePostFix();
	int evalutation();
public:
	Calculator();
	int getErrorCode();
	int setExpression(const char* expr);
	String getPostFix();
	int getValue();

};

