# CPP Module 06 - C++ Casts

## 📌 42/1337 Piscine C++ - Module 06

## About

This module is part of the C++ Modules series at 1337/42 School. It focuses on **type casting** in C++ — moving away from C-style casts and understanding the named C++ casts, when to use each, and their safety guarantees.

## Project Structure

```
CPP Module 06/
├── readme.md
├── ex00/
│   ├── ScalarConverter.hpp / .cpp
│   ├── convert.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Data.hpp
│   ├── Serializer.hpp / .cpp
│   ├── main.cpp
│   └── Makefile
└── ex02/
    ├── Base.hpp / .cpp
    ├── main.cpp
    └── Makefile
```

## Objectives

- Understand the differences between `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast`
- Learn why C-style casts should be avoided in C++
- Practice runtime type identification (RTTI) with `dynamic_cast`
- Implement serialization/deserialization of pointers
- Work with `Base`/derived class hierarchies and polymorphism

## Exercises

### ex00 - ScalarConverter
The `ScalarConverter` class exposes a single static method:
- `ScalarConverter::convert(std::string const & literal)` takes a scalar literal (`char`, `int`, `float`, or `double`) and displays the result of converting it to each of the other three types
- Handles edge cases: special values (`nan`, `inf`, `-inf`), out-of-range values, and non-displayable/non-printable chars (`impossible` where a conversion cannot be performed)
- Uses `static_cast` for all conversions
- `convert.cpp` / `main.cpp` drive the program from the command-line argument

### ex01 - Serializer
`Data.hpp` defines a simple `Data` struct used for the exercise.

The `Serializer` class has only static member functions:
- `static uintptr_t serialize(Data* ptr)` — converts a pointer to `Data` into an integer
- `static Data* deserialize(uintptr_t raw)` — converts that integer back into a pointer to `Data`
- Uses `reinterpret_cast`
- `main.cpp` verifies that deserializing a serialized pointer returns the exact original pointer

### ex02 - Identify real type
`Base.hpp` / `Base.cpp` define a `Base` class along with three derived classes (`A`, `B`, `C`):
- `Base* generate(void)` — randomly instantiates one of `A`, `B`, or `C` and returns it as a `Base*`
- `void identify(Base* p)` — identifies the real type using `dynamic_cast` on the pointer
- `void identify(Base& p)` — identifies the real type using `dynamic_cast` on the reference (via `try`/`catch`)
- Relies solely on RTTI (`dynamic_cast`), no manual type flags or other workarounds

## Building

Each exercise is built independently:

```bash
cd ex00   # or ex01, ex02
make        # compiles the project
make clean  # removes object files
make fclean # removes object files and binary
make re     # recompiles from scratch
```

## Usage

```bash
./convert 42       # ex00
./convert 42.0f
./convert nan
./convert 'c'

./serializer        # ex01

./identify          # ex02
```

## Key Concepts Learned

- `static_cast`: compile-time, well-defined conversions
- `dynamic_cast`: runtime-checked conversions across polymorphic hierarchies (RTTI)
- `reinterpret_cast`: low-level reinterpretation of bit patterns (e.g., pointer ↔ integer)
- `const_cast`: adding/removing `const` (and `volatile`) qualifiers
- Why C++ named casts are safer and more explicit than C-style casts
- Handling numeric edge cases (NaN, infinity, overflow) cleanly

## Norm

This project respects the 42 Norm coding style.

## Author

Project completed as part of the 1337/42 Network C++ Piscine curriculum.