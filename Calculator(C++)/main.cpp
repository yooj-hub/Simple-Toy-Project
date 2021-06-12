/*
 * Calculator
 * Description:
 *				Inorder replace to postorder, print postfix and calcuate the postfix.
 * Using : Visutal Studio 2019
 * Programmer: yooj
 * Date: 21.05.29
 */
#include"Calculator.h"
#include<iostream>
using namespace std;
int main(void) {
	char expr[1000];
	Calculator c;
	cout << "수식을 입력하시오(중위 연산식)" << endl;
	cin.getline(expr, 1000);
	int echeck=c.setExpression(expr);
	if (echeck == 0)
	{
		String postfix = c.getPostFix();
		int answer = c.getValue();
		cout << "Postfix : " << postfix << endl;
		cout << "Answer : " << answer;
		return 0;
	}
}