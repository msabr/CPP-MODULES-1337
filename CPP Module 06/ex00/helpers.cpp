#include "ScalarConverter.hpp"

int is_pseudo_d(std::string literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return 1;
    return 0;
}

int is_pseudo_f(std::string literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return 1;
    return 0;
}

type define_num_type(std::string literal) {
    int i = 0;
    bool pointed = false;
    bool integer_part = false;
    bool decimal_part = false;
    bool f = false;

    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (literal[i] && isdigit(literal[i])) {
        integer_part = true;
        i++;
    }
    if (literal[i] && literal[i] == '.') {
        pointed = true;
        i++;
    }
    while (literal[i] && isdigit(literal[i])) {
        decimal_part = true;
        i++;
    }
    if (literal[i] && literal[i] == 'f') {
        f = true;
        i++;
    }
    if (literal[i] == '\0') {
        if (pointed && decimal_part) {
            if (!f)
                return DOUBLE;
            return FLOAT;
        }
        if (integer_part)
            return INT;
    }
    return OTHER;
}


int parsing(type& literal_type, std::string literal) {
    if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
        literal_type = CHAR;
    else if (is_pseudo_f(literal)) {
        literal_type = PSEUDO_FLOAT;
    }
    else if (is_pseudo_d(literal)) {
        literal_type = PSEUDO_DOUBLE;
    }
    else
        literal_type = define_num_type(literal);
    
    if (literal_type == OTHER) {
        return 0;
    }
    return 1;
}

void convert_char(std::string& literal) {
    char c = literal[0];

    std::cout << "char: " << c << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
 
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

int get_precision(std::string literal) {
    int ret = 0;
    bool isdecimal = false;

    for (size_t i = 0; i < literal.size(); i++) {
        if (isdecimal)
            ret++;
        if (literal[i] == '.')
            isdecimal = true;
    }
    return ret;
}

void convert_num(std::string& literal) {

    int precision = get_precision(literal);

    std::stringstream ss;

    ss << literal;

    double d;

    ss >> d;

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "char: ";

        char c = static_cast<char>(d);
        // printf("char value = %d\n", c);
            
        if (d < 0 || d > 255)
            std::cout << "impossible" << std::endl;
        else if (!isprint(c)) {
            std::cout << "Non Displayable" << std::endl;
        }
        else {
            std::cout << "'" << c << "'" << std::endl;
        }
        
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }

    if (precision == 0)
        precision = 1;

    if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(d) << "f" << std::endl;

    if (ss.fail()) {
        std::cout << "double: impossible" << std::endl;
    }
    else 
        std::cout << "double: " << d << std::endl;
}

void convert_pseudo(std::string literal) {
    
    std::cout << "char: impossible" << std::endl;

    std::cout << "int: impossible" << std::endl;
    
    if (literal[0] == '+') {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal[0] == '-') {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}