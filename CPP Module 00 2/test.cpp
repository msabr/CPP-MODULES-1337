#include <iostream>

void f(){
    std::cout << "Hello from f!" << std::endl;
}
namespace test 
{
    int i = 5;
    int j = 5;
    void f()
    {
        std::cout << "Hello from test namespace!" << std::endl;
    }
}

// using namespace test;

int main() 
{
    test::f(); // Calls the function from the test namespace
    f(); // Calls the function from the global scope
    return 0;
}