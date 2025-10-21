# C++ Module 02 — Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

Version: 9.0

This repository contains the Module 02 exercises for the C++ track. These exercises teach ad-hoc polymorphism (operator overloading), the Orthodox Canonical Form for classes, and how to build small numeric and geometric utilities in C++98.

Each exercise lives in its own folder (ex00, ex01, ...) and includes a Makefile and test `main.cpp` so you can build and run examples quickly.

---

## Table of contents

- Project overview  
- Requirements & rules  
- Build & run  
- Directory layout  
- Exercises summary (ex00..ex03)  
- Testing & memory leaks  
- Submission & peer-evaluation  
- Notes about AI usage

---

## Project overview

Module 02 continues your C++ foundations by making you implement:

- A Fixed-point number type (Fixed) in Orthodox Canonical Form.
- Conversions between int/float and the fixed representation.
- Operator overloads for comparisons, arithmetic and increments/decrements.
- Utilities: min/max static members.
- A 2D Point class using Fixed values and a BSP function to test point-in-triangle.

All code must be compatible with the C++98 standard.

---

## Requirements & rules (read carefully)

- Compiler: g++ / clang++ (must compile with `-std=c++98`).
- Recommended flags: `-Wall -Wextra -Werror`.
- From Module 02 onward, all classes must follow the Orthodox Canonical Form:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Split classes into header (.hpp/.h) and source (.cpp). Do not put non-template function implementations in headers.
- Each header must be self-contained (include guards and all required headers).
- Forbidden: `using namespace <ns>`, `friend` keyword (unless stated otherwise), C-style memory functions (`malloc`, `free`, `printf`, ...), and STL containers/algorithms (vectors, lists, map, <algorithm>, etc.) until Modules 08/09.
- Allowed: the C standard math function `roundf` where explicitly permitted (ex01, ex02, ex03).
- Avoid memory leaks: when you allocate with `new` / `new[]`, free with `delete` / `delete[]` appropriately.

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

Make sure your Makefiles respect the project rules for targets if you intend to reuse them in an evaluative environment.

---

## Directory layout (typical)

- ex00/
  - Makefile
  - main.cpp
  - Fixed.hpp / Fixed.cpp
- ex01/
  - Makefile
  - main.cpp
  - Fixed.hpp / Fixed.cpp
- ex02/
  - Makefile
  - main.cpp
  - Fixed.hpp / Fixed.cpp
- ex03/ (optional)
  - Makefile
  - main.cpp
  - Fixed.hpp / Fixed.cpp
  - Point.hpp / Point.cpp
  - bsp.cpp

Each exercise must include the files listed in the subject text for submission.

---

## Exercises summary

- ex00 — My First Class in Orthodox Canonical Form
  - Implement class Fixed (orthodox canonical).
  - Private: int _rawBits; static const int _fractionalBits = 8.
  - Public: default ctor, copy ctor, copy assignment, destructor, getRawBits(), setRawBits().
  - Provide diagnostic output in constructors/destructor/members to match the subject examples.

- ex01 — Towards a more useful fixed-point number class
  - Add:
    - Fixed(int)
    - Fixed(float)
    - float toFloat() const
    - int toInt() const
    - Overload operator<< to print the fixed point as float.
  - Allowed function: roundf (from <cmath>) to implement conversions.

- ex02 — Now we're talking
  - Add operator overloads:
    - Comparisons: >, <, >=, <=, ==, !=
    - Arithmetic: +, -, *, /
    - Increment/decrement: pre/post ++ and -- (increase/decrease by 1 LSB)
  - Add static member functions:
    - min(Fixed&, Fixed&)
    - min(const Fixed&, const Fixed&)
    - max(Fixed&, Fixed&)
    - max(const Fixed&, const Fixed&)
  - Test thoroughly for precision/rounding behavior.

- ex03 — BSP (optional for passing the module)
  - Implement Point class (Orthodox Canonical Form) using Fixed as const members for x and y.
  - Implement bool bsp(Point const a, Point const b, Point const c, Point const point);
    - Returns true only if point is strictly inside the triangle (not on edge or vertex).
  - Allowed function: roundf (from <cmath>).

---

## Testing & memory leaks

- Provide your own `main.cpp` tests in each exercise folder.
- Check behavior against the example outputs in the subject.
- Use valgrind or equivalent to check memory leaks where applicable:
  - valgrind --leak-check=full ./a.out
- Make sure constructors/destructors and copy/assignment behave as expected.

---

## Submission & peer-evaluation

- Push only the required files (Makefile and specified .cpp/.hpp/.h files) to your Git repository.
- During evaluation you may be asked for a small modification or to explain parts of your implementation — be prepared to defend and edit your code quickly.
- Ensure file and folder names exactly match the subject.

---

## Notes about AI usage

Use AI as a learning aid (explain concepts, get hints) but do not copy full solutions you cannot explain. Solutions must be your own work so you can discuss and modify them during peer evaluation and exams.

---

If you want, I can now:
- produce example Makefiles for each exercise,
- scaffold minimal compliant Fixed/Point class headers and implementations (C++98, canonical form),
- or write test mains matching the subject examples.

Tell me which one you want next and I will generate the files for that exercise accordingly.