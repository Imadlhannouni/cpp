#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
    private:
        T* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array& operator=(const Array<T>& other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

#include "Array.tpp"

#endif