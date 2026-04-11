#include "serializer.hpp"

int main() {
    Data d;
    d.x = 22;
    d.c = 'i';
    d.str = "Forza Napoli";


    Data* ptr = &d;

    uintptr_t raw = Serializer::serialize(ptr);

    Data* p = Serializer::deserialize(raw);

    std::cout << "data values serialized and deserialized : "<< std::endl 
    << p->x << std::endl
    << p->c << std::endl
    << p->str << std::endl;
}