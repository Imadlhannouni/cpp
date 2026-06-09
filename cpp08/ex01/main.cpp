#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
