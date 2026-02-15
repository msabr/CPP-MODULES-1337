#include <iostream>
#include <stdexcept>

int main() 
{
    // out of range exception
    // try
    // {
    //     int grade = 0;
    //     std::cout << "Enter a grade (0-100): ";
    //     std::cin >> grade;
    //     if (grade < 0 || grade > 100) 
    //     {
    //         throw std::out_of_range("Grade must be between 0 and 100.");
    //     }
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // invalid argument exception
    // try
    // {
    //     int age = -5;
    //     if (age < 0) 
    //     {
    //         throw std::invalid_argument("Age cannot be negative.");
    //     }
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // logic error exception
    // try
    // {
    //     int a = 10;
    //     int b = 0;
    //     if (b == 0) 
    //     {
    //         throw std::logic_error("Division by zero is not allowed.");
    //     }
    //     int result = a / b;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // runtime error exception
    // try
    // {
    //     int* ptr = new int[10000000000000000]; // Attempt to allocate a huge array
    //     delete[] ptr;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }


    // range error exception
    // try
    // {
    //     int n = -1;
    //     if (n < 0) 
    //     {
    //         throw std::range_error("Negative value is not allowed.");
    //     }
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    // overflow error exception
    try
    {
        int a = 1000000;
        int b = 1000000;
        if (a > INT_MAX / b) 
        {
            throw std::overflow_error("Integer overflow occurred.");
        }
        int result = a * b;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Fin" << std::endl;
    return 0;
}
