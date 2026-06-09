#include "iter.hpp"

void print(int &a) {
    std::cout << a << std::endl;
}

int main( void ) {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    return 0;
}