# SimpleCompiler

## 📖 Description
**SimpleCompiler** is a C++ project that demonstrates the basics of **compiler design**.  
It implements a simple compiler that can **parse and evaluate arithmetic expressions** using:
- **Lexical Analysis (Lexer)**: Converts input string into tokens (numbers, operators, parentheses).
- **Parsing (Recursive Descent Parser)**: Applies grammar rules to build an evaluation tree.
- **Evaluation**: Computes the result of the parsed expression.

This project is designed as an educational exercise to understand the fundamentals of compilers, parsing, and expression evaluation.

## 📂 Project Structure
SimpleCompiler/
│── include/        # Header files (Lexer.h, Parser.h)  
│── src/            # Source files (Lexer.cpp, Parser.cpp, main.cpp)  
│── build/          # Compiled executable  
│── Makefile        # Build instructions  
│── README.md       # Documentation  

## ⚙️ Features
- Tokenizes arithmetic expressions (`+ - * / ()`).
- Parses expressions using recursive descent grammar:
  - expr   → term ((+|-) term)*
  - term   → factor ((*|/) factor)*
  - factor → NUMBER | '(' expr ')' | -factor
- Evaluates the result and prints it.
- Handles nested parentheses and operator precedence.

  ## Run
  ./build/simple_compiler

## Example
Enter an arithmetic expression: 3 + 5 * (2 - 4)
Result: -7

## 🚀 Getting Started
### Prerequisites
- C++17 or later
- `make` and `g++` installed

### Build
```bash
make
