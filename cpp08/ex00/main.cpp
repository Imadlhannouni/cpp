#include "easyfind.hpp"

int main()
{
    try {
        int arr[] = {2, 6, 9, 4};
        std::vector<int> b(arr, arr + 4);
    
        int to_find = 10;
        std::vector<int>::iterator c = easyfind(b, to_find);
        std::cout << *c << std::endl;
    } catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}