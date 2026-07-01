# CPP Module 07 - Templates

## 📌 42/1337 Piscine C++ - Module 07

## About

This module is part of the C++ Modules series at 1337/42 School. It introduces **function templates and class templates**, showing how to write generic, type-independent code while keeping type safety.

## Project Structure

```
CPP Module 07/
├── en.subject.pdf
├── readme.md
├── ex00/
│   ├── whatever.hpp
│   ├── ex00.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Iter.hpp
│   ├── ex01.cpp
│   ├── main.cpp
│   └── Makefile
└── ex02/
    ├── Array.hpp
    ├── Array.tpp
    ├── main.cpp
    └── Makefile
```

## Objectives

- Understand function templates and how the compiler generates code for each type used
- Understand class templates
- Learn why template implementations are usually kept in headers (or `.tpp` files included by the header)
- Write generic, reusable, type-safe containers and algorithms

## Exercises

### ex00 - Whatever
`whatever.hpp` defines generic function templates:
- `void swap(T &a, T &b)` — swaps two values of any type
- `T const & min(T const &a, T const &b)` — returns the smaller of two values
- `T const & max(T const &a, T const &b)` — returns the larger of two values
- If both values are equal, `min` and `max` return the first parameter (`a`)
- `ex00.cpp` / `main.cpp` demonstrate usage with different types (e.g. `int`, `std::string`)

### ex01 - Iter
`Iter.hpp` defines a generic function template:
- `void iter(T *array, size_t length, F functor)` — applies a given function (or function object) to each element of an array
- Works with any array type and any callable, including `const` arrays and functions that only read elements
- `ex01.cpp` / `main.cpp` demonstrate `iter` on arrays of different types (e.g. `int`, `std::string`) with different functors (e.g. print, increment)

### ex02 - Array
`Array.hpp` (with implementation in `Array.tpp`) defines a generic `Array<T>` class template:
- Default constructor creates an empty array
- Constructor taking an `unsigned int n` creates an array of `n` elements, default-initialized (e.g. `0` for scalar types)
- Copy constructor and copy assignment operator perform deep copies
- `operator[]` provides bounds-checked access, throwing `std::exception` when the index is out of range
- `size()` returns the number of elements in the array
- Respects the Orthodox Canonical Form

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
./whatever   # ex00
./iter       # ex01
./array      # ex02
```

## Key Concepts Learned

- Function templates and template argument deduction
- Class templates and separating declaration (`.hpp`) from implementation (`.tpp`)
- Generic programming and type-independent algorithms
- Bounds checking and exception safety in a templated container
- Orthodox Canonical Form applied to a template class

## Norm

This project respects the 42 Norm coding style.

## Author

Project completed as part of the 1337/42 Network C++ Piscine curriculum.