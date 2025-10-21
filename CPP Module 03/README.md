# C++ Module 03 — Inheritance

Version: 8.0

This repository contains the Module 03 exercises for the C++ track. These exercises introduce inheritance, constructor/destructor chaining, multiple inheritance, and class design in the Orthodox Canonical Form (C++98).

Each exercise is self-contained in its folder (ex00, ex01, ...). Every exercise includes a Makefile and test `main.cpp` files so you can build and run examples.

---

## Table of contents

- Project overview  
- Requirements & rules (important)  
- Build & run  
- Directory layout  
- Exercises summary (ex00..ex03)  
- Testing & memory leaks  
- Submission & peer-evaluation  
- Notes about AI usage

---

## Project overview

Module 03 builds on the foundations of Modules 01–02 and focuses on inheritance in C++. You will implement a base robot class (ClapTrap) and several derived classes that extend or modify behavior:

- ex00 — ClapTrap
- ex01 — ScavTrap (inherits ClapTrap)
- ex02 — FragTrap (inherits ClapTrap)
- ex03 — DiamondTrap (multiple inheritance from ScavTrap and FragTrap)

You will learn about:
- constructor and destructor chaining,
- visibility and attribute inheritance,
- overriding member functions,
- multiple inheritance pitfalls and how to manage them,
- proper design using the Orthodox Canonical Form.

All code must be compatible with the C++98 standard.

---

## Requirements & rules (read carefully)

- Compiler: g++ / clang++ (must compile with `-std=c++98`).
- Recommended compile flags: `-Wall -Wextra -Werror`.
- From Module 02 onward, all classes must follow the Orthodox Canonical Form:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Split classes into header (.hpp/.h) and source (.cpp). Do not put non-template function implementations in headers.
- Each header must be self-contained (include guards and all required headers).
- Forbidden (unless explicitly stated otherwise):
  - `using namespace <ns>`
  - `friend` keyword
  - C-style allocation/output (`malloc`, `free`, `printf`, etc.)
  - STL containers/algorithms are disallowed for these modules (allowed in Modules 08 and 09).
- Avoid memory leaks. When you allocate with `new` / `new[]`, free with `delete` / `delete[]` appropriately.
- Follow the exact filenames and turn-in lists required by each exercise.

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

You can also build from the repository root with `make -C ex00` etc.

Make sure your Makefiles respect the project rules and produce the expected executables for evaluation.

---

## Directory layout (typical)

- ex00/
  - Makefile
  - main.cpp
  - ClapTrap.hpp / ClapTrap.cpp
- ex01/
  - Makefile
  - main.cpp
  - ClapTrap.hpp / ClapTrap.cpp
  - ScavTrap.hpp / ScavTrap.cpp
- ex02/
  - Makefile
  - main.cpp
  - ClapTrap.hpp / ClapTrap.cpp
  - FragTrap.hpp / FragTrap.cpp
- ex03/
  - Makefile
  - main.cpp
  - ClapTrap.hpp / ClapTrap.cpp
  - ScavTrap.hpp / ScavTrap.cpp
  - FragTrap.hpp / FragTrap.cpp
  - DiamondTrap.hpp / DiamondTrap.cpp

Each exercise must include the files listed in the subject for submission.

---

## Exercises summary

- ex00 — Aaaaand... OPEN!
  - Implement class ClapTrap with:
    - Private attributes: name, hitPoints (10), energyPoints (10), attackDamage (0).
    - Public member functions:
      - void attack(const std::string& target);
      - void takeDamage(unsigned int amount);
      - void beRepaired(unsigned int amount);
  - Constructors and destructor must print messages to demonstrate construction/destruction.
  - Attacking and repairing cost 1 energy point; actions are blocked if hit points or energy points are zero.

- ex01 — Serena, my love!
  - Implement class ScavTrap that inherits from ClapTrap.
  - ScavTrap must:
    - Use ClapTrap attributes but initialize values to: hitPoints (100), energyPoints (50), attackDamage (20).
    - Override constructors, destructor, and attack() to print ScavTrap-specific messages.
    - Provide a special ability: void guardGate();
  - Tests must demonstrate proper construction/destruction chaining (ClapTrap constructed first; destroyed last).

- ex02 — Repetitive work
  - Implement class FragTrap that inherits from ClapTrap.
  - FragTrap must:
    - Initialize values to: hitPoints (100), energyPoints (100), attackDamage (30).
    - Override constructors/destructor messages.
    - Provide a special ability: void highFivesGuys(void);
  - Show construction/destruction chaining in tests.

- ex03 — Now it’s weird!
  - Implement class DiamondTrap that inherits from both ScavTrap and FragTrap.
  - DiamondTrap has a private attribute name that must use the same variable name as in ClapTrap (e.g., if ClapTrap uses `name` then DiamondTrap must also use `name`).
  - DiamondTrap specifics:
    - Its own name is passed to its constructor.
    - ClapTrap::name should be initialized to `<name>_clap_name`.
    - Hit points: use FragTrap's hit points.
    - Energy points: use ScavTrap's energy points.
    - Attack damage: use FragTrap's attack damage.
    - Use ScavTrap::attack() implementation.
    - Add void whoAmI(); that prints both DiamondTrap's own name and the ClapTrap name.
  - Ensure ClapTrap base subobject is created exactly once (manage diamond inheritance correctly).

Note: ex03 involves multiple inheritance and name resolution; study virtual inheritance if required by your design decisions. You can pass the module without completing ex03.

---

## Testing & memory leaks

- Provide your own `main.cpp` tests in each exercise folder.
- Ensure that constructors/destructors are called in expected order (verify chaining).
- Use valgrind (if available) to check for memory leaks:
  - valgrind --leak-check=full ./a.out
- Make sure there are no leaks and no undefined behavior.

---

## Submission & peer-evaluation

- Push only the required files (Makefile and specified .cpp/.hpp/.h files) to your Git repository.
- During evaluation you may be asked to make a small modification or to explain parts of your code — be prepared to defend and edit your code quickly.
- Ensure folder and file names match the subject exactly.

---

## Notes about AI usage

AI can help you learn, but do not submit work you cannot personally explain. Use AI for:
- clarifying concepts,
- getting small hints,
- reviewing your own code.

Do not use AI to produce complete solutions that you cannot discuss during peer-evaluation or exams.

---

If you want, I can:
- scaffold compliant headers and source files for ClapTrap/ScavTrap/FragTrap/DiamondTrap (C++98, canonical form), or
- provide example Makefiles and test mains for each exercise.

Pick one and I will generate the files for that exercise.