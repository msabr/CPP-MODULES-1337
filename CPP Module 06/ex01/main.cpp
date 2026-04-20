#include "Serializer.hpp"


int main(void)
{
    Data data = {73, 3.14f, 'A'};

    std::cout << "Original pointer : " << &data << "\n";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t) : " << raw << "\n";

    Data *back = Serializer::deserialize(raw);
    std::cout << "Deserialized ptr : " << back << "\n";

    std::cout << "Pointers match   : " << (back == &data ? "YES" : "NO") << "\n";
    std::cout << "Data id=" << back->i
              << " name=" << back->c
              << " value=" << back->f<< "\n";
    return 0;
}
