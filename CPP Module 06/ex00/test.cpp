#include <iostream>
#include <sstream>

int main(int ac, char** av)
{
    if ( ac != 2)return 2;
    std::stringstream ss;
    ss << av[1];
    int a ;
    ss >> a;
    if ( ss.fail() || !ss.eof() )std::cout << "int failed" << std::endl;
    
    float d;
    ss.clear();
    ss << av[1];
    ss >> d;
    if ( ss.fail() || !ss.eof() )std::cout << "float failed" << std::endl;
    std::cout << a << std::endl << d ;
}