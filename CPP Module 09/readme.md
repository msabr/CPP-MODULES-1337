# CPP Module 09 — STL Containers

Final module of the C++ common core. It moves away from writing your own containers/algorithms and instead requires solving three self-contained problems, each with a container of your choice from the STL — with the constraint of picking the *right* one for the job.

## Exercises

### ex00 — Bitcoin Exchange

**Files:** `BitcoinExchange.cpp`, `BitcoinExchange.hpp`, `data.csv`, `input.csv`, `main.cpp`

Reads a database of historical Bitcoin prices (`data.csv`, format `date,exchange_rate`) and an input file (`input.csv`, format `date | value`) passed as a program argument. For each line of input, it looks up the exchange rate on that date (or the closest earlier date if there's no exact match) and prints `value * rate`.

```bash
./btc input.csv
```

Key points:
- Input must be validated: date format, non-negative value, value ≤ 1000, and errors reported per-line without stopping the whole program (`Error: bad input => ...`, `Error: not a positive number.`, `Error: too large a number.`).
- A `std::map<std::string, float>` is the natural fit here since it keeps entries sorted by date and supports efficient closest-key lookup with `lower_bound`/`upper_bound`.

### ex01 — RPN (Reverse Polish Notation)

**Files:** `RPN.cpp`, `RPN.hpp`, `main.cpp`

Evaluates an arithmetic expression given in Reverse Polish Notation, passed as a single quoted argument.

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

Key points:
- Supports `+`, `-`, `*`, `/` on integers only.
- A `std::stack<int>` (or `std::deque`-backed stack) is used to push operands and pop/apply operators as they're read.
- Invalid expressions (malformed input, division by zero, insufficient operands) must produce an `Error` and a non-zero-ish clean exit rather than crashing.

### ex02 — PmergeMe (Merge-Insertion Sort)

**Files:** `PmergeMe.cpp`, `PmergeMe.hpp`, `main.cpp`

Implements the **merge-insertion sort** (Ford–Johnson algorithm) to sort a sequence of positive integers given as program arguments, using it with two different containers to compare performance.

```bash
./PmergeMe 3 5 9 7 4
```

Key points:
- The same algorithm is run on two different STL containers (typically `std::vector` and `std::deque` or `std::list`) to demonstrate container performance trade-offs.
- Output must show the sequence before and after sorting, plus the time taken to process each container, e.g.:
  ```
  Before: 3 5 9 7 4
  After:  3 4 5 7 9
  Time to process a range of 5 elements with std::vector : 0.00021 us
  Time to process a range of 5 elements with std::deque  : 0.00035 us
  ```
- Must handle duplicate values and invalid input (non-numeric, negative, overflow) with an `Error` message.

## Build and run

Each exercise builds independently:

```bash
cd ex00 && make && ./btc input.csv
cd ../ex01 && make && ./RPN "3 4 +"
cd ../ex02 && make && ./PmergeMe 1 2 3 4 5
```

Common Makefile targets: `make`, `make clean`, `make fclean`, `make re`.

## Standard & flags

- **C++98**
- `-Wall -Wextra -Werror`
- No use of: `printf`/`cout` for error-message oriented debugging beyond what's specified, `using namespace std;` at global scope, or forbidden functions per the subject.

## Notes

- The point of this module is *choosing* the right STL container for each problem (`map` for sorted key lookup, `stack`/`deque` for RPN, `vector`/`deque`/`list` for the sort comparison) rather than reimplementing container logic from scratch.
- Exception safety matters: malformed input should be caught and reported cleanly, never crash the program.