#include "Serializer.hpp"

int main() {
    Data data;
    data.data = 42;
    data.c = 'a';
    data.f = 42.42f;
    data.d = 42.42;

    std::cout << "Original address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "SUCCESS: ptr == &data" << std::endl;
    else
        std::cout << "FAILURE: ptr != &data" << std::endl;
    std::cout << "--- Data through original ---" << std::endl;
    std::cout << "data.data: " << data.data << std::endl;
    std::cout << "data.c: " << data.c << std::endl;
    std::cout << "data.f: " << data.f << std::endl;
    std::cout << "data.d: " << data.d << std::endl;

    std::cout << "--- Data through deserialized ptr ---" << std::endl;
    std::cout << "ptr->data: " << ptr->data << std::endl;
    std::cout << "ptr->c: " << ptr->c << std::endl;
    std::cout << "ptr->f: " << ptr->f << std::endl;
    std::cout << "ptr->d: " << ptr->d << std::endl;

    return 0;
}
