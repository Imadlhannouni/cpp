#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>

class Span {
    private:
        unsigned int elements;
        std::vector<int> num;
    public:
        Span(unsigned int elements);
        ~Span();
        Span(const Span &other);
        Span& operator=(const Span &other);
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        void printS();
};


#endif