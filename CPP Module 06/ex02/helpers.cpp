#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void) { 

    int n = -1;
    std::srand(time(0));
    n = std::rand() % 3;

    Base *ret;
    if (n == 0)
        ret = new A();
    else if (n == 1)
        ret = new B();
    else
        ret = new C();

    return ret;
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Error" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::exception& ex) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(std::exception& ex) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(std::exception& ex) {}

    std::cout << "Error" << std::endl;
    return;
}