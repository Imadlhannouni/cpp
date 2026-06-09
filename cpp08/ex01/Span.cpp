#include "Span.hpp"

Span::Span(unsigned int n) : elements(n) {}

Span::~Span() {}

Span::Span(const Span &other)
{
    this->elements = other.elements;
}

Span& Span::operator=(const Span &other)
{
    this->elements = other.elements;
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->num.size() == this->elements)
        throw std::out_of_range("Span is full");
    this->num.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->num.size() + std::distance(begin, end) > this->elements)
        throw std::out_of_range("Span is full");
    this->num.insert(this->num.end(), begin, end);
}

int Span::longestSpan()
{
    if (this->num.size() < 2)
        throw std::logic_error("Need at least 2 numbers");
    int longestSpan = *std::max_element(this->num.begin(), this->num.end()) - *std::min_element(this->num.begin(), this->num.end());

   return longestSpan;
}

int Span::shortestSpan()
{
    if (this->num.size() < 2)
        throw std::logic_error("Need at least 2 numbers");
    std::sort(this->num.begin(), this->num.end());
    int min = INT_MAX;
    for (size_t i = 0; i < this->num.size() - 1; i++)
    {
        if (this->num[i + 1] - this->num[i] < min)
            min = this->num[i + 1] - this->num[i];
    }
    return (min);
}

void Span::printS()
{
    for(unsigned long int i = 0; i < this->num.size(); i++)
    {
        std::cout << num[i] << std::endl;
    }
}
