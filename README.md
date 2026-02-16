# Push Swap

A C project from the 42 curriculum where the goal is to sort integers using two stacks with a limited set of operations.

## 👩🏻‍🏫 What I gained from the project

This project helped me practice low-level algorithm design under constraints:
- Building and manipulating custom linked-list stacks (`stack_a`, `stack_b`, and helper stacks) in C.
- Designing a sorting strategy based on median/chunk logic to reduce operation count.
- Validating input rigorously (duplicates, non-numeric values, overflow) before any processing.
- Structuring a medium-size C project with modular files for parsing, operations, linked lists, and sorting.

## 📦 Prerequisites

- `clang` (used by the project `Makefile`)
- `make`
- A Unix-like shell (for running commands and `tester.sh`)
- `ruby` (optional, used by `tester.sh` to generate random test sets)
- `checker` executable (optional, useful to verify output sequences)

## 🚀 Usage

### Build push_swap (and libft)
```bash
make
```

### Run with a list of integers
```bash
./push_swap 2 1 3 6 5 8
```

### Verify result with checker (if available)
```bash
ARG="2 1 3 6 5 8"
```
```bash
./push_swap $ARG | ./checker $ARG
```

### Run benchmark script (requires ruby and checker)
```bash
bash tester.sh 3 5 100 500
```
