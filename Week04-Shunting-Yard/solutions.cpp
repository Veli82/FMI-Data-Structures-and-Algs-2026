#include <iostream>
#include <string>
#include <stack>

bool isOpeningBr(char c)
{
	return (c == '(' || c == '{' || c == '[');
}

bool isValid(char c1, char c2)
{
	switch (c1)
	{
	case '(':
		return c2 == ')';
	case '{':
		return c2 == '}';
	case '[':
		return c2 == ']';
	}
}

//task1
bool validParentheses(const std::string& str)
{
	std::stack<char> stack;

	for (char c : str)
	{
		if (isOpeningBr(c))
		{
			stack.push(c);
		}
		else
		{
			if (stack.empty()) return false;
			if (isValid(stack.top(), c)) stack.pop();
			else return false;
		}
	}
	return stack.empty();
}


bool isOP(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int execOp(int lhs, int rhs, char op)
{
	if (op == '+') return lhs + rhs;
	if (op == '-') return lhs - rhs;
	if (op == '*') return lhs * rhs;
	if (op == '/') return lhs / rhs;
	else throw std::runtime_error("invalid input");
}

//task2
int calcRVP(const std::string& s)
{
	std::stack<int> st;
	for (char c : s)
	{
		if (isOP(c))
		{
			int temp1 = st.top();
			st.pop();
			int temp2 = st.top();
			st.pop();
			int res = execOp(temp2, temp1, c);
			st.push(res);

		}
		else
		{
			st.push(c - '0');
		}
	}
	return st.top();
}


int getPrec(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

//task3
std::string InfixToPostfix(const std::string& input)
{
	std::stack<char> st;
	std::string output;
	for (char c : input)
	{
		if (isOP(c))
		{
			while (!st.empty() && getPrec(c) <= getPrec(st.top()))
			{
				output.push_back(st.top());
				st.pop();
			}
			st.push(c);
		}
		else if (c == '(')
		{
			st.push(c);
		}
		else if (c == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				output.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else
		{
			output.push_back(c);
		}
	}

	while (!st.empty())
	{
		output.push_back(st.top());
		st.pop();
	}
	return output;
}


int main()
{
	std::string s;
	std::cin >> s;
	std::cout << calcRVP(InfixToPostfix(s));
}
