# CPP Module 08 - Templated Containers, STL

## 📌 42/1337 Piscine C++ - Module 08

## About

This module is part of the C++ Modules series at 1337/42 School. It introduces the **STL (Standard Template Library)** — containers, iterators, and algorithms — and shows how to write generic code that works with any STL container.

## Project Structure

```
CPP Module 08/
├── en.subject.pdf
├── readme.md
├── ex00/
│   ├── easyfind.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Span.hpp / .cpp
│   ├── main.cpp
│   └── Makefile
└── ex02/
    ├── MutantStack.hpp
    ├── main.cpp
    └── Makefile
```

## Objectives

- Get familiar with STL containers (`vector`, `list`, `stack`, etc.) and their iterators
- Write generic function templates that work with any container type
- Understand how to adapt/extend an existing STL container
- Practice algorithm usage from `<algorithm>` (e.g. `std::find`, `std::sort`)

## Exercises

### ex00 - easyfind
`easyfind.hpp` defines a generic function template:
- `int easyfind(T &container, int value)` — finds the first occurrence of an integer in a container of integers (works with any container providing iterators, e.g. `std::vector<int>`, `std::list<int>`) and returns an iterator to it
- Throws an exception if the value is not found
- Uses `std::find` from `<algorithm>`

### ex01 - Span
`Span.hpp` / `Span.cpp` implement a `Span` class:
- Constructed with a maximum number `N` of integers it can store
- `addNumber(int n)` adds a single number, throwing an exception once the span is full
- A range-based `addNumber(InputIterator first, InputIterator last)` (template) adds multiple numbers at once
- `shortestSpan()` returns the shortest distance between any two numbers in the span
- `longestSpan()` returns the maximum distance between the smallest and the largest numbers
- Both throw an exception if there are fewer than two numbers
- `main.cpp` demonstrates filling a `Span` of 10,000+ numbers efficiently

### ex02 - MutantStack
`MutantStack.hpp` implements a `MutantStack<T>` class template:
- Publicly inherits from `std::stack<T>`
- Adds iterator support (`begin()`, `end()`), since `std::stack` doesn't provide iterators by default
- Behaves exactly like `std::stack` otherwise (`push`, `pop`, `top`, `size`, `empty`)
- `main.cpp` demonstrates iterating over a `MutantStack` with a standard iterator and comparing behavior with `std::list`

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
./easyfind   # ex00
./span       # ex01
./mutantstack # ex02
```

## Key Concepts Learned

- STL container usage and iterator-based generic programming
- Extending/adapting existing STL containers (container adapters)
- Algorithm functions from `<algorithm>` (`std::find`, `std::min_element`, `std::max_element`, `std::sort`)
- Exception handling in generic, reusable classes
- Efficient bulk insertion using iterator ranges

## Norm

This project respects the 42 Norm coding style.

## Author

Project completed as part of the 1337/42 Network C++ Piscine curriculum.