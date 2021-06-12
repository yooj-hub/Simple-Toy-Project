#include "Calculator.h"
#include <iostream>
#include <stack>

using namespace std;
Calculator::Calculator()
{
	errCode = 0;
	postfix = " ";
	value = 0;
}
int Calculator::makePostFix()
{
	String temp = "";
	int n = tokens.getItemCount();
	stack<String> stack;
	int j = 0;
	int pos = 0;
	bool check = true;
	while (j < n) 
	{
		{
			if (tokens.getItem(j) == (String)'(')
			{
				stack.push("(");
			}
			else if (tokens.getItem(j) == (String)')') {
					while (!stack.empty())
					{
						if (!(stack.top() == '(')) {
							temp = temp + (String)' ';
							temp = temp + (String)stack.top();
								stack.pop();
						}
						else {
							break;

						}
					}
				stack.pop();
			}

			else if (tokens.getItem(j) == (String)'*') {

				while (!stack.empty()) {
					if (stack.top() == '/' || stack.top() == '*') {
						temp = temp + (String)' ';
						temp = temp + (String)stack.top();
							stack.pop();
					}
					else
						break;
				}
				stack.push('*');
			}
			else if (tokens.getItem(j) == (String)'/') {
				
					while(!stack.empty())
					{
						if (stack.top() == '/' || stack.top() == '*')
						{
							temp = temp + (String)' ';
							temp = temp + (String)stack.top();
							stack.pop();
						}
						else 
							break;
					}
				stack.push('/');
			}
			else if (tokens.getItem(j) == (String)'+') {
				
					while (!stack.empty()) {
						if (stack.top() == '/' || stack.top() == '*' || stack.top() == '+'
							|| stack.top() == '-') {
							temp = temp + (String)' ';
							temp = temp + (String)stack.top();
							stack.pop();
						}
						else
							break;
					}
				stack.push('+');
			}

			else if (tokens.getItem(j) == (String)'-') {
				
					while (!stack.empty()) {
						if (stack.top() == '/' || stack.top() == '*' || stack.top() == '+'
							|| stack.top() == '-') {
							temp = temp + (String)' ';
							temp = temp + (String)stack.top();
							if (!stack.empty())
								stack.pop();
						}
						else
							break;
					}
				stack.push('-');
			}
			else
			{
				temp = temp + (String)' ';
				temp = temp + tokens.getItem(j);
			}
			j++;
		}

	}
	

	while (!stack.empty()) 
	{
		temp = temp + (String)' ';
		temp=temp + (String)stack.top();
		stack.pop();
	}

	this->postfix = temp;
	return 0;
};

int Calculator::evalutation()
{
	stack<int> stack;
	int check = 0;
	int check2 = 0;
	int j = 1;
	int n = strlen(postfix);
	while (j < n) {
		String temp = "";
		while (j < n) {
			if (postfix[j] != ' ' && postfix[j] != '+' && postfix[j] != '-'
				&& postfix[j] != '*' && postfix[j] != '/')
			{
				temp = temp + (String)postfix[j++];
			}
			else
			{
				break;
			}
		}
		if (postfix[j] == '+' || postfix[j] == '-'
			|| postfix[j] == '*' || postfix[j] == '/')
		{
			check2++;
			if (stack.empty())
				return 1;

			int a = stack.top();
			stack.pop();

			if (stack.empty())
				return 1;

			int b = stack.top();
			stack.pop();
			if (postfix[j] == '+')
			{
				
				stack.push(a + b);
			}

			else if (postfix[j] == '-')
			{
				stack.push(b - a);
			}

			else if (postfix[j] == '*')
			{
				stack.push(a * b);
				
			}
			else if (postfix[j] == '/')
			{
				if (a == 0)
					return 2;

				stack.push(b / a);
			}
			j++;
		}
		else if (temp != (String)"")
		{
			stack.push(atoi(temp));
			
			check++;
		}
		j++;
	}
	if ((check - check2) == 1)
		this->value = stack.top();
	else
	{
		this->value = -999999;
			return 3;
	}
	return 0;
};

int Calculator::getErrorCode()
{
	return errCode;
}
;
int Calculator::setExpression(const char* expr) 
{
	int n = strlen(expr);
	int j = 0;
	while (j < n) 
	{
		String temp = "";
		while (j<n) 
		{
			if (expr[j] != ' ')
				temp = temp + (String)expr[j++];
			else
				break;
		}
		tokens.addItem(temp);
		j++;
	}

	errCode=makePostFix();
	errCode = evalutation();
	if (errCode == 1) 
	{
		cout << "피연산자 부족으로 인한 에러 발생" << endl;
		value = -99999;
		return 1;
	}
	if (errCode == 2) 
	{
		cout << "0으로 나눔으로 인한 에러 발생" << endl;
		value = -99999;
		return 1;
	}
	if (errCode == 3) 
	{
		cout << "연산자 수 부족으로 인한 에러 발생"<<endl;
		value = -99999;
		return 1;
	}
	return 0;
}

String Calculator::getPostFix()
{
	return postfix;
}
int Calculator::getValue()
{
	if (errCode == 0)
	{
		return value;
	}
	else
	{
		cout << "에러 발생" << endl;
		return -99999;
		
	}
}

