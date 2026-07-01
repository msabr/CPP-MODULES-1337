# CPP Module 05 - Exceptions

## 📌 42/1337 Piscine C++ - Module 05

## About

This module is part of the C++ Modules series at 1337/42 School. It focuses on **exception handling** in C++: throwing and catching exceptions, designing custom exception classes, and combining exceptions with class hierarchies and polymorphism through a "bureaucratic paperwork" theme.

## Project Structure

```
CPP Module 05/
├── en.subject.pdf
├── exception.cpp
├── exception.tldr
├── readme.md
├── ex00/
│   ├── Bureaucrat.hpp / .cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Bureaucrat.hpp / .cpp
│   ├── Form.hpp / .cpp
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── AForm.hpp / .cpp
│   ├── Bureaucrat.hpp / .cpp
│   ├── ShrubberyCreationForm.hpp / .cpp
│   ├── RobotomyRequestForm.hpp / .cpp
│   ├── PresidentialPardonForm.hpp / .cpp
│   ├── main.cpp
│   └── Makefile
└── ex03/
    ├── AForm.hpp / .cpp
    ├── Bureaucrat.hpp / .cpp
    ├── Intern.hpp / .cpp
    ├── ShrubberyCreationForm.hpp / .cpp
    ├── RobotomyRequestForm.hpp / .cpp
    ├── PresidentialPardonForm.hpp / .cpp
    ├── main.cpp
    └── Makefile
```

## Objectives

- Understand and implement C++ exceptions (`try`, `catch`, `throw`)
- Create custom exception classes (nested classes inheriting from `std::exception`)
- Apply the Orthodox Canonical Form (OCF) to more complex classes
- Design abstract classes with pure virtual functions
- Combine polymorphism with exception handling
- Implement a simple factory pattern

## Exercises

### ex00 - Bureaucrat
Implementation of the `Bureaucrat` class:
- A `const std::string name` and an `int grade` (1 = highest, 150 = lowest)
- `getName()`, `getGrade()`, `incrementGrade()`, `decrementGrade()`
- Nested exception classes: `GradeTooHighException` and `GradeTooLowException`
- Overloaded `operator<<` to display a Bureaucrat (`name, bureaucrat grade X.`)

### ex01 - Form
Introduction of the `Form` class:
- A `const std::string name`, a `bool signed`, a `const int gradeToSign`, and a `const int gradeToExecute`
- `beSigned(Bureaucrat const & bureaucrat)` throws if the bureaucrat's grade is insufficient
- Nested exception classes: `GradeTooHighException` and `GradeTooLowException`
- `Bureaucrat::signForm(Form &form)` attempts to sign a form and catches/reports any exception
- Overloaded `operator<<` to display a Form

### ex02 - More Forms (AForm)
`Form` is replaced by the **abstract class `AForm`**, which:
- Declares a pure virtual `void execute(Bureaucrat const & executor) const = 0;`
- Handles the common name/signed/gradeToSign/gradeToExecute logic and exceptions

Three concrete forms derive from `AForm`:
- **ShrubberyCreationForm** – creates a file `<target>_shrubbery` filled with ASCII-art trees
- **RobotomyRequestForm** – prints drilling noises, then has a 50% chance of announcing the target has been robotomized successfully
- **RobotomyRequestForm** and **PresidentialPardonForm** and **ShrubberyCreationForm** each define their own sign/execute grade requirements
- `AForm::execute()` also checks the executor's grade before calling the form's own logic

### ex03 - Intern
Implementation of the `Intern` class:
- `Intern::makeForm(std::string formName, std::string target)` creates and returns the correct `AForm*` (`ShrubberyCreationForm`, `RobotomyRequestForm`, or `PresidentialPardonForm`) based on the given name
- Uses an internal array of form names paired with creation functions (function pointers), avoiding a long if/else or switch chain
- Prints a message confirming the intern created the form, or a warning if the form name is unknown

## Building

Each exercise is built independently:

```bash
cd ex00   # or ex01, ex02, ex03
make        # compiles the project
make clean  # removes object files
make fclean # removes object files and binary
make re     # recompiles from scratch
```

## Usage

```bash
./bureaucrat   # ex00
./form         # ex01
./aform        # ex02
./intern       # ex03
```

## Key Concepts Learned

- Exception safety and custom exception hierarchies (`std::exception`)
- `try` / `catch` / `throw` mechanics
- Abstract base classes and pure virtual functions
- Polymorphism applied to a real-world "bureaucratic" simulation
- Orthodox Canonical Form (constructor, destructor, copy constructor, assignment operator)
- Factory-style object creation using arrays of function pointers

## Norm

This project respects the 42 Norm coding style.

## Author

Project completed as part of the 1337/42 Network C++ Piscine curriculum.