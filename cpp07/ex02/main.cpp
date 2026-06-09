#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "--- Test 1: Int Array ---" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
    {
        a[i] = i * 2;
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::cout << "--- Test 2: Copy Constructor (Deep Copy) ---" << std::endl;
    Array<int> b(a);
    b[0] = 42;
    std::cout << "a[0] (should be 0): " << a[0] << std::endl;
    std::cout << "b[0] (should be 42): " << b[0] << std::endl;

    std::cout << "--- Test 3: Assignment Operator (Deep Copy) ---" << std::endl;
    Array<int> c;
    c = a;
    c[0] = 99;
    std::cout << "a[0] (should be 0): " << a[0] << std::endl;
    std::cout << "c[0] (should be 99): " << c[0] << std::endl;

    std::cout << "--- Test 4: String Array ---" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "42";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

    std::cout << "--- Test 5: Out of Bounds ---" << std::endl;
    try
    {
        std::cout << a[5] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "--- Test 6: Default Constructor ---" << std::endl;
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    return 0;
}