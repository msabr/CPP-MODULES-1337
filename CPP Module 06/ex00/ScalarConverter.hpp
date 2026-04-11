#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

enum type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_FLOAT,
    PSEUDO_DOUBLE,
    OTHER
};

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& otherObj);
        ScalarConverter& operator=(const ScalarConverter& otherObj);
    
    public:
        static void convert(std::string literal);
};

int is_pseudo_d(std::string literal);
int is_pseudo_f(std::string literal);
void convert_num(std::string& literal);
void convert_char(std::string& literal);
void convert_pseudo(std::string literal);
type define_num_type(std::string literal);
int parsing(type& literal_type, std::string literal);

#endif