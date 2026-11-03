#include <iostream>
#include <string>

bool isOperation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int opPrec(char c)
{
    if (c == '+' || c == '-')   return 1;
    if (c == '*' || c == '/')   return 2;
    return 0;
}

int doOperation(int temp2, int temp1, char c)
{
    if (c == '+') return temp2 + temp1;
    if (c == '-') return temp2 - temp1;
    if (c == '*') return temp2 * temp1;
    if (c == '/')
    {
        if (temp1 == 0) throw std::runtime_error("cannot divide by zero");
        return temp2 / temp1;
    }
    throw std::runtime_error("unknown operation");
}

///ZAD2
int calRVP(const std::string& s)
{
    std::stack<int> stack;

    for (char c: s)
    {
        if (isOperation(c))
        {
            int temp1 = stack.top();
            stack.pop();
            int temp2 = stack.top();
            stack.pop();
            int res = doOperation(temp2,temp1,c);
            stack.push(res);
        }
        else
            stack.push(c - '0');
    }

    return stack.top();
}

///ZAD3
std::string intoPostFix(const std::string& input)
{
    std::string output;
    std::stack<char> op;
    for (char c : input)
    {
        if (isOperation(c))
        {
            while (!op.empty() && opPrec(c) <= opPrec(op.top()))
            {
                output.push_back(op.top());
                op.pop();
            }
            op.push(c);
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(' )
            {
                output.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
        else
            output.push_back(c);
    }

    while (!op.empty())
    {
        output.push_back(op.top());
        op.pop();
    }

    return output;
}

void pushResult(std::stack<int>& nums, std::stack<char>& ops)
{
    if (nums.size() < 2) throw std::runtime_error("missing operand");
    int temp1 = nums.top();
    nums.pop();

    int temp2 = nums.top();
    nums.pop();

    int result = doOperation(temp2,temp1,ops.top());
    nums.push(result);
    ops.pop();
}

///presmqtane prez infix + obraboteni greshki
int calc(const std::string& input)
{
    std::stack<int> res;
    std::stack<char> op;
    for (char c : input)
    {
        if (c == ' ' || c == '\t') continue;
        if (isOperation(c))
        {
            while (!op.empty() && opPrec(c) <= opPrec(op.top()))
                pushResult(res,op);

            op.push(c);
        }

        else if (c == '(')
            op.push(c);

        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(' )
                pushResult(res,op);

            if (op.empty())
                throw std::runtime_error("invalid parentheses");
            op.pop();
        }
        else if (c >= '0' && c <= '9')
            res.push(c - '0');
        
        else throw std::runtime_error("invalid symbol");
    }

    while (!op.empty())
    {
        if (op.top() == '(')    throw std::runtime_error("unclosed parentheses");
        pushResult(res,op);
    }

    if (res.empty())   throw std::runtime_error("no input");
    if (res.size() != 1) throw std::runtime_error("missing operation");
    return res.top();
}

///ot infix kum rpn s vuzmojnost za po-golemi chisla + obraboteni greshki
std::string betterInfixToRPN(const std::string& input)
{
    std::string output;
    std::stack<char> stack;
    for (size_t i = 0; input[i] != '\0';i++)
    {
        if (input[i] == ' ')    continue;
        if (isOperation(input[i]))
        {
            while (!stack.empty() && opPrec(input[i]) <= opPrec(stack.top()))
            {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.push(input[i]);
        }
        else if (input[i] == '(')
        {
            stack.push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (!stack.empty() && stack.top() != '(' )
            {
                output.push_back(stack.top());
                output.push_back(' ');
                stack.pop();
            }
            stack.pop();
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            while (input[i] >= '0' && input[i] <= '9' && input[i] != '\0')
            {
                output.push_back(input[i]);
                i++;
            }
            output.push_back(' ');
            i--;
        }
        else throw std::runtime_error("invalid symbol");
    }

    while (!stack.empty())
    {
        if (stack.top() == '(') throw std::runtime_error("unclosed parentheses");

        output.push_back(stack.top());
        output.push_back(' ');
        stack.pop();
    }

    return output;
}

int main()
{
    try
    {
        std::cout << betterInfixToRPN("1+2");
    }
    catch (...)
    {
        throw;
    }
}