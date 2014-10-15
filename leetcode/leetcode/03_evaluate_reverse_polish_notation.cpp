/*
https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate Reverse Polish Notation


Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include "03_evaluate_reverse_polish_notation.h"
using namespace std;

bool is_numeric(const string&s){
	return s!="+" && s!="-" && s!="*" && s!="/";
}

int caculate (int args_1, int args_2, char op){
	switch(op)
	{
	case '+':
		return args_1 + args_2;
	case '-':
		return args_1 - args_2;
	case '*':
		return args_1 * args_2;
	case '/':
		return args_1 / args_2;
	}
	return 0;
}

// int value = atoi(myString.c_str()); 
int evalRPN(vector<string> &tokens)
{
	stack<int> temp;

	for (int i = 0; i < tokens.size(); i++)
	{
		string item = tokens[i];
		if(is_numeric(item)){
			temp.push(stoi(item));
		}
		else{
			char op = item[0];
			int args_2 = temp.top();
			temp.pop();
			int args_1 = temp.top();
			temp.pop();
			int result = caculate(args_1,args_2, op);
			temp.push(result);
		}
	}
	return temp.top();
}

void evalRPN_Test(){
	string arr[] = {"4", "13", "5", "/", "+"};
	int length = sizeof(arr)/sizeof(arr[0]);
	vector<string> tokens (arr, arr+5);
	int result = evalRPN(tokens);
}