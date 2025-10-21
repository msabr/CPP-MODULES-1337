```markdown
# C++ Module 00 — Basics: namespaces, classes, streams, initialization lists, static & const

Version: 11.0

This repository contains the Module 00 exercises for the C++ curriculum. These exercises introduce basic C++ concepts: simple classes, member functions, I/O with std::iostream, initialization lists, static/const members, basic arrays, and small program structure. Code must compile with the C++98 standard and follow the project rules.

---

## Contents

- Overview
- Requirements & rules (important)
- Build & run
- Directory layout
- Exercises summary
  - ex00 — Megaphone
  - ex01 — My Awesome PhoneBook
  - ex02 — The Job Of Your Dreams (Account)
- Testing & memory checks
- Submission & peer-evaluation
- Notes about AI usage

---

## Overview

Module 00 is designed to get you comfortable with the basic syntax and idioms of C++ (C++98): writing small programs, defining classes and headers, using constructors/destructors, member functions, standard streams, and basic arrays. Exercises progress from tiny command-line utilities to small class-based applications.

---

## Requirements & rules (read carefully)

- Compiler: a standard C++ compiler (g++, clang++).
- Required flags: compile with `-Wall -Wextra -Werror`. Ensure code still compiles with `-std=c++98`.
- Forbidden:
  - `using namespace <ns>` is forbidden unless stated otherwise.
  - No external libraries other than the standard library.
  - The following C functions are forbidden in these exercises: `printf()`, `alloc()` and `free()` (use C++ facilities instead).
- Files:
  - Put class declarations in headers (.hpp/.h) and implementations in .cpp files.
  - Header files must be self-contained and protect against double inclusion (include guards).
  - Do not implement non-template functions in header files.
- Dynamic allocation:
  - For ex01 the subject forbids dynamic allocation — use fixed-size arrays or stack allocation where required.
- Output:
  - Unless specified otherwise, every output message must end with a newline and be written to standard output.

---

## Build & run

Each exercise directory contains a Makefile (or should). Typical workflow:

- Build an exercise:
  - cd ex00
  - make
- Run:
  - ./megaphone ... (for ex00)
  - ./phonebook (for ex01)
  - ./accounts_tests (or as named) for ex02
- Clean:
  - make clean or make fclean (depends on provided Makefile)

If you prefer, build from repository root with `make -C ex00`, etc.

---

## Directory layout (expected)

- ex00/
  - Makefile
  - megaphone.cpp
- ex01/
  - Makefile
  - main.cpp
  - PhoneBook.hpp PhoneBook.cpp
  - Contact.hpp Contact.cpp
- ex02/
  - Makefile
  - Account.hpp Account.cpp
  - tests.cpp
  - log file (provided by subject)

Follow the filenames required by the subject when turning in your exercises.

---

## Exercises summary

ex00 — Megaphone
- A simple command-line utility that echoes its arguments converted to uppercase.
- Behavior:
  - If arguments provided: print them concatenated in uppercase, followed by newline.
  - If no argument: print "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
- File to turn in: `megaphone.cpp`.

ex01 — My Awesome PhoneBook
- Implement two classes: `PhoneBook` and `Contact`.
- PhoneBook stores up to 8 contacts (fixed-size array). Adding a 9th contact replaces the oldest.
- Contact fields: first name, last name, nickname, phone number, darkest secret. Saved contacts cannot have empty fields.
- Interactive program accepts commands: `ADD`, `SEARCH`, `EXIT`.
  - `ADD`: prompt field-by-field and save a contact.
  - `SEARCH`: show a table of stored contacts with columns (index, first name, last name, nickname) each 10 characters wide, right-aligned; long fields are truncated with a dot. Then prompt for an index and show full contact fields if index is valid.
  - `EXIT`: quit the program.
- Dynamic allocation is forbidden for this exercise; use stack / fixed arrays.

ex02 — The Job Of Your Dreams (Account)
- Recreate `Account.cpp` using the provided `Account.hpp`, `tests.cpp`, and the log file.
- The goal is to implement a class that matches the behavior recorded in the log file (transactions, tracking, static data members, timestamped logs in tests).
- Completing ex02 is optional to pass the module, but it's an excellent exercise on static members, formatting, and class design.

---

## Testing & memory checks

- Provide thorough test `main.cpp` files for ex01/ex02 to show correct behavior and edge cases.
- Use valgrind or similar (when available) to check for memory errors/leaks for exercises that allocate memory.
- Make sure destructors run and output expected messages when used in tests.

---

## Submission & peer-evaluation

- Commit and push the required files for each exercise to your Git repository.
- Only the work in your repository will be evaluated.
- During peer evaluation you may be asked to make a small change or explain parts of your implementation — be ready to modify your code quickly and discuss design choices.

---

## Notes about AI usage

- Use AI as a learning aid: ask for clarifications, small hints, or explanations — not full solutions you can't explain.
- The goal is to develop problem-solving skills and the ability to explain your work during peer evaluation and exams.

---

## Example commands

Build and run ex00:
```
cd ex00
make
./megaphone "hello world"
```

Run ex01:
```
cd ex01
make
./phonebook
```

---

Good luck — read each exercise carefully and design your classes and tests before writing code. Have fun learning C++!

```