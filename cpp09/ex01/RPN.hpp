#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN {
    private:
        std::stack<int> stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        void evaluate(const std::string& expression);
        void applyOperator(char op);
};