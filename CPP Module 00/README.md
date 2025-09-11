# C++ Module 00 - README

**Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff**

## 📚 Overview

This is the first module in the C++ curriculum at 42 School. It introduces fundamental Object-Oriented Programming (OOP) concepts and serves as a transition from C to C++. The module follows the C++98 standard to keep things simple and focused on core concepts.

## 🎯 Learning Objectives

- Understand the basics of Object-Oriented Programming
- Learn C++ syntax and conventions
- Master fundamental C++ concepts
- Build a solid foundation for advanced C++ modules

## 🔑 Key Concepts Explained

### 1. **Namespaces**
Namespaces prevent name collisions by grouping related code together.

```cpp
namespace MyNamespace {
    int value = 42;
    void myFunction() { /* ... */ }
}

// Usage
MyNamespace::value;
MyNamespace::myFunction();

// Standard namespace
std::cout << "Hello World!" << std::endl;
```

**Important:** `using namespace` is forbidden in 42 projects!

### 2. **Classes**
Classes are user-defined types that encapsulate data and functions.

```cpp
class MyClass {
private:
    int _privateData;           // Private members (convention: underscore prefix)
    
public:
    MyClass();                  // Constructor
    ~MyClass();                 // Destructor
    
    void setData(int data);     // Setter (mutator)
    int getData() const;        // Getter (accessor) - const method
    
    void publicMethod();        // Public member function
};
```

**Naming Convention:** Classes use `UpperCamelCase` (PascalCase)

### 3. **Member Functions**
Functions that belong to a class and operate on class data.

```cpp
// Declaration in header (.hpp)
class Calculator {
private:
    int _result;
    
public:
    Calculator();
    int add(int a, int b);
    int getResult() const;      // const: doesn't modify object
};

// Implementation in source (.cpp)
Calculator::Calculator() : _result(0) {}  // Constructor with initialization list

int Calculator::add(int a, int b) {
    _result = a + b;
    return _result;
}

int Calculator::getResult() const {
    return _result;             // const method cannot modify _result
}
```

### 4. **stdio streams**
C++ I/O streams for input/output operations.

```cpp
#include <iostream>
#include <iomanip>
#include <string>

// Output stream
std::cout << "Hello" << " World!" << std::endl;

// Input stream
std::string name;
int age;
std::cin >> name >> age;

// Formatting
std::cout << std::setw(10) << std::right << "Name" << "|" << std::endl;
std::cout << std::setw(10) << std::right << name << "|" << std::endl;
```

**Key streams:**
- `std::cout` - standard output
- `std::cin` - standard input  
- `std::cerr` - standard error
- `std::endl` - end line and flush buffer

### 5. **Initialization Lists**
Efficient way to initialize class members in constructors.

```cpp
class Student {
private:
    std::string _name;
    int _age;
    const int _id;              // const members must be initialized
    
public:
    // Initialization list (preferred method)
    Student(std::string name, int age, int id) 
        : _name(name), _age(age), _id(id) {
        // Constructor body (if needed)
    }
    
    // Without initialization list (less efficient)
    Student(std::string name, int age, int id) {
        _name = name;           // Assignment, not initialization
        _age = age;
        // _id = id;            // ERROR! const members can't be assigned
    }
};
```

### 6. **static**
Static members belong to the class, not to any specific instance.

```cpp
class Counter {
private:
    static int _count;          // Static member declaration
    int _id;
    
public:
    Counter();
    ~Counter();
    static int getCount();      // Static method
};

// Static member definition (in .cpp file)
int Counter::_count = 0;        // Initialize static member

Counter::Counter() {
    _id = ++_count;             // Increment for each new instance
}

Counter::~Counter() {
    --_count;                   // Decrement when instance destroyed
}

int Counter::getCount() {
    return _count;              // Can only access static members
}

// Usage
int totalCount = Counter::getCount();  // Call without instance
```

### 7. **const**
Keyword for immutable data and methods that don't modify object state.

```cpp
class Rectangle {
private:
    double _width;
    double _height;
    
public:
    Rectangle(double w, double h);
    
    // const method - promises not to modify object
    double getArea() const {
        return _width * _height;
    }
    
    // const parameter - cannot modify the passed value
    void setWidth(const double width) {
        _width = width;
    }
    
    // const return - returned value cannot be modified
    const double& getWidthRef() const {
        return _width;
    }
};

// const object - cannot be modified after creation
const Rectangle rect(10.0, 5.0);
double area = rect.getArea();       // OK - const method
// rect.setWidth(15.0);             // ERROR - non-const method on const object
```

## 📋 Exercise Breakdown

### Exercise 00: Megaphone
- **Goal:** Convert command line arguments to uppercase
- **Concepts:** Basic I/O, string manipulation, program arguments
- **Key Skills:** C++ streams, character manipulation

### Exercise 01: My Awesome PhoneBook
- **Goal:** Create a phonebook application with Contact and PhoneBook classes
- **Concepts:** Classes, member functions, arrays, formatted output
- **Key Skills:** Class design, data encapsulation, user interaction

### Exercise 02: The Job Of Your Dreams
- **Goal:** Recreate missing Account.cpp file based on header and log output
- **Concepts:** Static members, class implementation, reverse engineering
- **Key Skills:** Understanding existing code, static variables, output matching

## 🛠️ Development Guidelines

### File Structure
```
ex00/
├── Makefile
└── megaphone.cpp

ex01/
├── Makefile
├── main.cpp
├── PhoneBook.hpp
├── PhoneBook.cpp
├── Contact.hpp
└── Contact.cpp

ex02/
├── Makefile
├── Account.hpp (provided)
├── Account.cpp (to implement)
└── tests.cpp (provided)
```

### Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

### Naming Conventions
- **Files:** `ClassName.hpp`, `ClassName.cpp`
- **Classes:** `UpperCamelCase` (PascalCase)
- **Functions/Variables:** `camelCase` or `snake_case`
- **Private Members:** Often prefixed with `_` (underscore)

## ⚠️ Important Rules

### Forbidden
- `using namespace` keyword
- External libraries (C++11+, Boost)
- STL containers until Module 08-09
- `printf()` family functions
- `malloc()`, `free()` functions
- `friend` keyword

### Required
- Include guards in headers
- Orthodox Canonical Form (from Module 02+)
- Independent headers (include all dependencies)
- Memory leak prevention
- C++98 standard compliance

## 💡 Tips for Success

1. **Read the entire module first** - Don't jump straight into coding
2. **Plan your classes** - Think about encapsulation and interface design
3. **Test incrementally** - Build and test small pieces at a time
4. **Use const correctly** - Make methods const when they don't modify state
5. **Follow naming conventions** - Consistent style improves readability
6. **Handle edge cases** - Empty inputs, invalid indices, etc.
7. **Memory management** - No leaks, proper initialization

## 🔍 Common Mistakes

- Forgetting const correctness
- Using forbidden functions or keywords
- Not handling edge cases (empty inputs, out of bounds)
- Poor class design (everything public or everything private)
- Memory leaks with dynamic allocation
- Not following naming conventions
- Missing include guards

## 📖 Useful Resources

- [cplusplus.com](http://www.cplusplus.com/) - C++ reference
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ documentation
- String class: `std::string`
- I/O manipulation: `<iomanip>` header
- Input/Output: `<iostream>` header

## 🚀 Next Steps

After completing Module 00, you'll have a solid foundation in:
- Basic C++ syntax and OOP concepts
- Class design and implementation
- Proper const usage
- C++ I/O streams

This prepares you for Module 01, which will introduce more advanced OOP concepts like dynamic memory allocation, references, and pointers to members.

---

**Remember:** The goal is to learn, not just to complete. Take time to understand each concept thoroughly. The foundation you build here will be crucial for all future C++ modules!