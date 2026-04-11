#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& otherObj) {
    if (this == &otherObj)
        return *this;
    return *this;
}

void ScalarConverter::convert(std::string literal) {
    type literal_type = OTHER;

    if (parsing(literal_type, literal)) {
        if (literal_type == CHAR){
            convert_char(literal);
        }
        else if (literal_type == INT || literal_type == FLOAT || literal_type == DOUBLE) {
            convert_num(literal);
        }
        else if (literal_type == PSEUDO_DOUBLE || literal_type == PSEUDO_FLOAT)
            convert_pseudo(literal);
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }       
}