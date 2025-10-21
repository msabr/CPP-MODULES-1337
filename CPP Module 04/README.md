# C++ Module 04 — Subtype Polymorphism, Abstract Classes, and Interfaces

Version: 12.0

This repository contains the Module 04 exercises for the C++ curriculum. These exercises teach subtype polymorphism, abstract classes (pure virtual interfaces), and safe object ownership in C++98.

Each exercise is self-contained inside its directory (ex00, ex01, ex02, ex03). Every exercise should include a Makefile and test `main.cpp` files so you can build and run examples.

---

## Contents

- Overview
- Requirements & rules (important)
- Build & run
- Directory layout
- Exercises summary
  - ex00 — Polymorphism
  - ex01 — I don’t want to set the world on fire
  - ex02 — Abstract class
  - ex03 — Interface & recap
- Testing & memory management
- Submission & peer-evaluation
- Notes about AI usage

---

## Overview

Module 04 focuses on:
- using virtual functions to achieve subtype polymorphism,
- making base classes abstract when appropriate,
- implementing deep copies and correct memory ownership,
- designing interfaces via pure-abstract classes,
- managing object lifetime safely (avoid leaks and dangling pointers).

All code must compile and run with C++98.

---

## Requirements & rules (read carefully)

- Compiler: g++ / clang++ that supports `-std=c++98`.
- Recommended flags: `-Wall -Wextra -Werror`.
- From Module 02 onward, classes must follow the Orthodox Canonical Form when required:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Split class declarations (headers) and implementations (sources). Do not put non-template function implementations in header files.
- All headers must be self-contained (include guards and required includes).
- Forbidden (unless explicitly stated otherwise):
  - `using namespace <ns>`
  - `friend` keyword
  - C-style I/O/allocation (`printf`, `malloc`, `free`, etc.)
  - STL containers/algorithms are disallowed for Modules 01–07 (allowed only in Modules 08/09).
- Avoid memory leaks: every `new` must have a matching `delete` (or `new[]` / `delete[]`).
- For each class, constructor/destructor messages should be distinct and informative to demonstrate the program flow.

---

## Build & run

Each exercise folder contains a Makefile. Typical workflow:

- Build:
  - cd ex00
  - make
- Clean:
  - make clean
  - make fclean
- Run:
  - ./a.out (or the executable named in the exercise)

You can also build from the repository root using:
- make -C ex00

Make sure your Makefile targets and produced executable names match the exercise instructions.

---

## Directory layout (typical)

- ex00/
  - Makefile
  - main.cpp
  - Animal.hpp Animal.cpp
  - Dog.hpp Dog.cpp
  - Cat.hpp Cat.cpp
  - WrongAnimal.hpp WrongAnimal.cpp
  - WrongCat.hpp WrongCat.cpp
- ex01/
  - Makefile
  - main.cpp
  - Brain.hpp Brain.cpp
  - Dog.hpp Dog.cpp
  - Cat.hpp Cat.cpp
  - (plus ex00 files as required)
- ex02/
  - Makefile
  - main.cpp
  - (ex01 files updated: Animal becomes abstract)
- ex03/
  - Makefile
  - main.cpp
  - AMateria.hpp AMateria.cpp
  - Ice.hpp Ice.cpp
  - Cure.hpp Cure.cpp
  - ICharacter.hpp
  - Character.hpp Character.cpp
  - IMateriaSource.hpp
  - MateriaSource.hpp MateriaSource.cpp

Follow the filenames and submission lists in the subject for each exercise.

---

## Exercises summary

- ex00 — Polymorphism
  - Implement base class `Animal` with protected `std::string type`.
  - Implement `Dog` and `Cat` deriving from `Animal`. Their `type` must be `"Dog"` and `"Cat"`.
  - Provide `makeSound()` and `getType()`; `makeSound()` must be virtual so derived classes print their own sounds.
  - Implement `WrongAnimal` / `WrongCat` to show what happens without `virtual`.
  - Tests must demonstrate correct dynamic dispatch for `Dog`/`Cat` and incorrect behavior for the `Wrong*` classes.

- ex01 — I don’t want to set the world on fire
  - Implement `Brain` class containing a `std::string ideas[100]`.
  - `Dog` and `Cat` must contain a private `Brain*` member.
  - Allocate `Brain` in constructors and free in destructors.
  - Build an array of `Animal*`, fill half with `Dog` and half with `Cat`, then delete them via `Animal*` to prove proper virtual destruction.
  - Implement and test deep copy semantics (copy ctor and assignment produce deep copies of Brain).

- ex02 — Abstract class
  - Make `Animal` abstract (cannot be instantiated) by declaring at least one pure virtual function (e.g., `virtual void makeSound() const = 0;`).
  - Everything else should behave as before but creating `Animal` objects should be impossible.

- ex03 — Interface & recap
  - Implement `AMateria` (abstract base class) with `getType()`, `clone()` (pure virtual), and a virtual `use(ICharacter&)`.
  - Implement concrete `Ice` and `Cure` classes (`type` = `"ice"` / `"cure"`), `clone()` returns a new object of the same concrete type, and `use()` performs the text outputs:
    - Ice: "* shoots an ice bolt at <name> *"
    - Cure: "* heals <name>'s wounds *"
  - Implement `ICharacter` interface and concrete `Character`:
    - Character stores a name and an inventory of 4 `AMateria*` slots.
    - `equip()` places a materia in the first empty slot.
    - `unequip()` removes without deleting (behavior: caller responsible for floor items).
    - `use(idx, ICharacter& target)` calls `slot[idx]->use(target)` if present.
    - Copying Characters must produce deep copies (cloned Materias).
  - Implement `IMateriaSource` and `MateriaSource`:
    - `learnMateria(AMateria*)` stores (a copy) up to 4 templates.
    - `createMateria(type)` returns a new instance cloned from a stored template matching `type`, or `NULL` if not known.
  - Tests should match the provided example and include additional cases (equip/unequip edge cases, copies, unknown materia requests).

---

## Testing & memory management

- Provide comprehensive tests (main.cpp) for each exercise.
- Check:
  - correct virtual dispatch,
  - proper construction/destruction order and messages,
  - deep copy correctness,
  - no double-deletes or memory leaks.
- Tools:
  - valgrind --leak-check=full ./a.out (recommended where available).
- Handle unequipped Materias properly (store them or transfer ownership) so leaving items on the floor does not leak.

---

## Submission & peer-evaluation

- Push the required files (Makefile and listed .cpp/.hpp/.h) to your Git repository.
- During evaluation you may be asked to:
  - make a small behavior change,
  - add or modify a test,
  - explain or refactor a part of your code.
- Ensure file and folder names exactly match the subject.

---

## Notes about AI usage

- Use AI as a learning aid — for concept clarification, hints, or reviewing your code — but avoid submitting code you cannot explain.
- Relying on AI to produce entire solutions prevents you from learning the material; you must be able to defend and modify your code during peer evaluation and exams.

---

If you want, I can:
- scaffold compliant headers and implementations for the classes in any exercise (ex00..ex03),
- produce example Makefiles and test mains that match the subject examples,
- or generate a checklist of test cases to verify deep copies, polymorphism, and memory safety.

Tell me which exercise or artifact you'd like generated next and I will produce the files.