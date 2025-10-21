# C++ Module 01 — Memory allocation, pointers to members, references and switch statements

This repository contains the Module 01 exercises for the C++ track. The goal of these exercises is to teach fundamental C++ concepts: dynamic memory allocation, constructors/destructors, references vs pointers, pointers-to-member-functions, and the `switch` statement — all using the C++98 standard.

Each exercise is self-contained inside its directory (ex00, ex01, ...). Every exercise includes a Makefile and test `main.cpp` files so you can build and run examples.

---

## Table of contents

- Project overview
- Requirements
- Build & run
- Directory layout
- Exercises summary
- Coding rules & restrictions
- Testing & memory leaks
- Submission & evaluation
- Notes about AI usage

---

## Project overview

This repository implements the Module 01 exercises from the C++ curriculum. Exercises are progressively introduced:

- ex00 — Zombie class, stack vs heap
- ex01 — Zombie horde allocation
- ex02 — Pointer and reference demo
- ex03 — Weapon, HumanA/HumanB (references vs pointers)
- ex04 — File text replacement (s1 -> s2)
- ex05 — Harl: use of pointers-to-member-functions
- ex06 — Harl filter: use of `switch` to filter log levels (optional)

Each exercise is intended to be small and focused on a well-defined concept. Read each exercise description in its folder before coding.

---

## Requirements

- Compiler: a standard-compliant C++ compiler (g++, clang++).
- Target standard: compile with `-std=c++98` (solutions must still compile with this flag).
- Recommended compile flags: `-Wall -Wextra -Werror`.
- No external libraries other than the standard library (note: most STL containers/algorithms are forbidden for this module; see restrictions).
- Each exercise directory contains its own Makefile. Use the Makefile provided (or adapt it) and ensure the required files are present.

---

## Build & run

Each exercise has its own Makefile. Typical usage:

- Build an exercise:
  - cd into the exercise directory, e.g. `cd ex00`
  - run `make`
- Clean an exercise:
  - `make fclean` or `make clean` (depends on the Makefile provided)
- Build from repository root (if Makefiles are set to support it):
  - `make -C ex00` (build ex00 without changing directory)

Example:
- Build ex05:
  - cd ex05 && make
- Run:
  - ./harl

Replace `harl` with the executable name specified by the exercise (for ex06: `harlFilter`).

---

## Directory layout (typical)

Each `exNN` directory should contain at least:

- Makefile
- main.cpp (tests)
- The exercise source/header files (for example `Zombie.hpp`, `Zombie.cpp`, ...)
- Optional extra tests you add

Top-level tree example:
- ex00/
  - Makefile
  - main.cpp
  - Zombie.hpp
  - Zombie.cpp
  - newZombie.cpp
  - randomChump.cpp
- ex01/
  - Makefile
  - main.cpp
  - Zombie.hpp
  - Zombie.cpp
  - zombieHorde.cpp
- ex02/
  - ...
- ex03/
  - Weapon.hpp Weapon.cpp
  - HumanA.hpp HumanA.cpp
  - HumanB.hpp HumanB.cpp
  - main.cpp
- ex04/, ex05/, ex06/ similarly

---

## Exercises summary

- ex00 — BraiiiiiiinnnzzzZ
  - Implement a `Zombie` class with `announce()` and destructor message.
  - Implement `newZombie(std::string)` (heap allocation) and `randomChump(std::string)` (stack allocation).
  - Learn when heap vs stack allocation is appropriate.

- ex01 — Moar brainz!
  - Implement `zombieHorde(int N, std::string name)` which allocates a contiguous array of `N` `Zombie` objects and initializes them.
  - Return pointer to first `Zombie`.

- ex02 — HI THIS IS BRAIN
  - Demonstrate a string variable, a pointer to it, and a reference to it.
  - Print addresses and values.

- ex03 — Unnecessary violence
  - Implement `Weapon` with `getType()` and `setType()`.
  - Implement `HumanA` (holds a `Weapon&`) and `HumanB` (may hold a `Weapon*`), each with `attack()` showing correct behavior when the weapon type changes.

- ex04 — Sed is for losers
  - Implement a file-text replace utility: takes `filename s1 s2`, writes output to `filename.replace`, replacing all occurrences of `s1` by `s2`.
  - Forbidden: `std::string::replace` and C file functions (fopen, fread, etc).

- ex05 — Harl 2.0
  - Implement `Harl` class with private `debug`, `info`, `warning`, `error` methods.
  - Public `complain(std::string level)` dispatches to the right method using a pointer-to-member-function array or mapping (no big if/else chains).

- ex06 — Harl filter (optional)
  - Build a `harlFilter` executable that prints messages of a chosen level and above. Implement level selection using `switch`.

---

## Coding rules & restrictions (IMPORTANT)

Follow these rules carefully — violations may lead to failing grades:

- Use C++98 language features only.
- Compile with `-Wall -Wextra -Werror` and `-std=c++98`.
- You are allowed to use most of the standard library, but:
  - The STL containers and algorithms are forbidden in Modules 01..07 (vectors, lists, maps, algorithm header, etc.). They are allowed only in Modules 08 and 09.
  - Forbidden functions: do not use `printf()`, `alloc()` and `free()` in these exercises. Using these results in a grade of 0.
  - `using namespace <ns>` and `friend` keyword are forbidden.
- Header files must have include guards and include all necessary headers so they can be used independently.
- Implement the Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor) for classes where required (Modules 02..09). For Module 01 exercises, follow instructions per exercise.
- Do not implement non-template function bodies in header files (except when the exercise explicitly allows it). Violations can score 0.
- Avoid memory leaks. If you allocate with `new`, pair with `delete` (or `new[]` with `delete[]`) at the appropriate time.

---

## Testing & memory leaks

- Provide your own tests (main.cpp) in each exercise to demonstrate correct behavior.
- Use tools like valgrind (if available) to check for memory leaks:
  - valgrind --leak-check=full ./your_executable
- Ensure destructors are called and that allocated memory is freed.

---

## Submission & peer-evaluation

- Submit the required files in each exercise directory to your Git repository.
- During peer evaluation or defense, you may be asked to make a small modification; be ready to explain your code and apply a minor change within a few minutes.
- Only the work inside your repository will be evaluated.

---

## Notes about AI usage

This curriculum expects you to build foundations yourself. AI can be a learning aid, but avoid copying complete solutions. Use AI to:
- clarify concepts,
- get small hints,
- or review your own code — but not to produce final code you cannot explain.

During peer-evaluation or exams, you must be able to justify your design and implementation.

---

## Examples

Build and run ex05 (Harl):
- cd ex05
- make
- ./harl             # or run the provided test executable

Build ex06 (harlFilter):
- cd ex06
- make
- ./harlFilter "WARNING"

Replace files example (ex04):
- cd ex04
- make
- ./replace input.txt foo bar
- The program should create `input.txt.replace`.

---

If you need any clarification about a specific exercise, the expected files, or the Makefile targets, check the exercise directory's README (if present) or the top-of-file comments in `main.cpp`. Good luck and have fun learning core C++ concepts!
