#include <iostream>
#include <stack>

static const unsigned ASCII_ROUND_SUM = 81;
static const unsigned ASCII_SQUARE_SUM = 184;
static const unsigned ASCII_CURLY_SUM = 248;

bool isOpeningBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isClosingBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool areRoundPair(char c1, char c2)
{
    return (c1 + c2) == ASCII_ROUND_SUM;
}

bool areSquarePair(char c1, char c2)
{
    return (c1 + c2) == ASCII_SQUARE_SUM;
}

bool areCurlyPair(char c1, char c2)
{
    return (c1 + c2) == ASCII_CURLY_SUM;
}

bool correctParentheses(const std::string& str)
{
    std::stack<char> stack;

    for (char c : str)
    {
        if (isOpeningBracket(c))
        {
            stack.push(c);
            continue;
        }

        if (isClosingBracket(c))
        {
            if (stack.empty())  return false;

            if (areRoundPair(c,stack.top()))
            {
                stack.pop();
                continue;
            }

            if (areSquarePair(c,stack.top()))
            {
                stack.pop();
                continue;
            }

            if (areCurlyPair(c,stack.top()))
            {
                stack.pop();
                continue;
            }

            return false;

        }
    }

    if (stack.empty()) return true;

    return false;
}

int main()
{
    std::cout << std::boolalpha << correctParentheses("([)]");
}