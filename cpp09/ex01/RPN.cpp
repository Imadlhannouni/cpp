#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

void RPN::applyOperator(char op)
{
    if (this->stack.size() < 2)
        throw std::runtime_error("Error");

    int b = this->stack.top();
    this->stack.pop();
    int a = this->stack.top();
    this->stack.pop();

    switch(op)
    {
        case '+':
            this->stack.push(a + b);
            break;\
        case '-':
            this->stack.push(a - b);
            break;
        case '*':
            this->stack.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            this->stack.push(a / b);
            break;
    }
}

void RPN::evaluate(const std::string& expression)
{
    std::istringstream tokens(expression);
    std::string value;

    while (tokens >> value)
    {
        if (std::isdigit(value[0]) && value.size() == 1)
        {
            this->stack.push(value[0] - '0');
        }
        else if (value.size() == 1 && (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/'))
            applyOperator(value[0]);
        else
        {
            std::cerr << "Error: Invalid token => " << value << std::endl;
            throw std::runtime_error("Error");
        }
    }
    if (this->stack.size() != 1)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        throw std::runtime_error("Error");
    }

    std::cout << (long long)this->stack.top() << std::endl;
}