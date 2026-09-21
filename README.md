# CPP-MODULES-1337

<div align="center">
  <img src="CPP%20Modules.png" alt="42 C++ Modules"/>
</div>

Global repository README for the 42 School **C++ Modules** curriculum (Modules 00–09), covering the transition from C to C++ and core object-oriented programming concepts, from basic classes all the way to STL containers and algorithms.

## Overview

This repository contains all ten C++ modules of the 42 common core. Each `CPP Module NN` folder holds a module-level `README.md` / `readme.md` and one `exNN` folder per exercise with its own sources, headers, and `Makefile`. Modules 00–04 also include the official subject PDF (`en.subject.pdf`).

## Repository layout

```text
CPP-MODULES-1337/
├── CPP Module 00/   # Namespaces, classes, member functions, stdio streams, init lists
│   ├── ex00 - megaphone.cpp
│   ├── ex01 - PhoneBook / Contact
│   └── ex02 - Account
├── CPP Module 01/   # Memory allocation, pointers to members, references, switch
│   ├── ex00 - Zombie (newZombie / randomChump)
│   ├── ex01 - Zombie horde
│   ├── ex02 - pointers vs references
│   ├── ex03 - Weapon / HumanA / HumanB
│   ├── ex04 - file to string replace
│   └── ex05-06 - Harl (switch statement)
├── CPP Module 02/   # Ad-hoc polymorphism, operator overloading, Orthodox Canonical form
│   └── ex00-02 - Fixed (fixed-point numbers)
├── CPP Module 03/   # Inheritance
│   ├── ex00 - ClapTrap
│   ├── ex01 - ScavTrap
│   ├── ex02 - FragTrap
│   └── ex03 - DiamondTrap (multiple/virtual inheritance)
├── CPP Module 04/   # Subtype polymorphism, abstract classes, interfaces
│   ├── ex00 - Animal / Cat / Dog / WrongAnimal / WrongCat
│   ├── ex01 - same, with dynamic allocation
│   ├── ex02 - abstract Animal class
│   └── ex03 - Materia / Character (interfaces, deep copy)
├── CPP Module 05/   # Repetition and exceptions
│   ├── ex00 - Bureaucrat
│   ├── ex01 - Bureaucrat / Form
│   ├── ex02 - AForm + concrete forms (Shrubbery/Robotomy/PresidentialPardon)
│   └── ex03 - Intern (form factory)
├── CPP Module 06/   # Casts (static, dynamic, const, reinterpret)
│   ├── ex00 - ScalarConverter
│   ├── ex01 - Serializer
│   └── ex02 - Base / generate & identify (dynamic cast)
├── CPP Module 07/   # Templates
│   ├── ex00 - function templates (whatever)
│   ├── ex01 - Iter (template function over an array)
│   └── ex02 - Array (template class)
├── CPP Module 08/   # Templated containers, iterators, algorithms
│   ├── ex00 - easyfind
│   ├── ex01 - Span
│   └── ex02 - MutantStack
├── CPP Module 09/   # STL containers
│   ├── ex00 - BitcoinExchange
│   ├── ex01 - RPN (Reverse Polish Notation)
│   └── ex02 - PmergeMe (merge-insertion sort)
├── .gitignore
└── README.md
```

## Module documentation

Each module has its own README with exercise-specific details:

- [CPP Module 00](CPP%20Module%2000/README.md)
- [CPP Module 01](CPP%20Module%2001/README.md)
- [CPP Module 02](CPP%20Module%2002/README.md)
- [CPP Module 03](CPP%20Module%2003/README.md)
- [CPP Module 04](CPP%20Module%2004/README.md)
- [CPP Module 05](CPP%20Module%2005/readme.md)
- [CPP Module 06](CPP%20Module%2006/readme.md)
- [CPP Module 07](CPP%20Module%2007/readme.md)
- [CPP Module 08](CPP%20Module%2008/readme.md)
- [CPP Module 09](CPP%20Module%2009/readme.md)

## Build and run

Every exercise is built independently from its own folder:

```bash
cd "CPP Module 03/ex01"
make
./scavtrap   # or whatever executable the Makefile produces
```

Common Makefile targets:

| Target        | Description                            |
|---------------|----------------------------------------|
| `make`        | Compile the exercise                   |
| `make clean`  | Remove object files                    |
| `make fclean` | Remove object files and the executable |
| `make re`     | `fclean` + `make` (full rebuild)       |

## Coding standards

- Target language standard: **C++98**, as required by the 42 curriculum (`-std=c++98`).
- Compilation flags: `-Wall -Wextra -Werror -std=c++98`.
- Conventions follow the subjects: `UpperCamelCase` class names, one header/source pair per class, protected headers, and the Orthodox Canonical Form from Module 02 onward.

## Getting started

```bash
git clone https://github.com/msabr/CPP-MODULES-1337.git
cd CPP-MODULES-1337
```

Then navigate into any module/exercise folder and run `make` as described above.

## Author

[msabr](https://github.com/msabr)
