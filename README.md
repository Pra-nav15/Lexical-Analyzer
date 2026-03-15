cat << 'EOF' > README.md
# 🔍 Lexical Analyzer in C

## 📌 Overview
The Lexical Analyzer Project is a command-line application developed in the C programming language that performs lexical analysis on C source code. Lexical analysis converts a sequence of characters into tokens such as keywords, identifiers, literals, operators, and symbols.

In compiler design, lexical analysis is the first phase of compilation where the input program is scanned and broken into meaningful tokens that can be processed by later stages such as parsing.

This project demonstrates how a basic lexical analyzer works by tokenizing a given C program and categorizing its components.

## ✨ Features

### 🔑 Keywords
Recognizes reserved C keywords such as:
int, float, char, return, if, while

### 🆔 Identifiers
Detects variable names, function names, and user-defined identifiers.

### 🔢 Literals
Identifies literals including:
- Integer literals
- Floating point numbers
- Character literals
- String literals

### 📦 Arrays
Recognizes array declarations and usage.

Example:
int arr[10];

### ⚙ Operators
Detects operators used in expressions such as:
+  -  *  /  =  ==

### 🧾 Tokenized Output
Displays the input program as tokens with their corresponding types.

Example:

Input:
sum = 3 + 2;

Output:

Token      Type
sum        Identifier
=          Assignment Operator
3          Integer Literal
+          Addition Operator
2          Integer Literal
;          End of Statement

## ⚙ How Lexical Analysis Works

1. The analyzer reads the input C program character by character.
2. It identifies lexemes (valid sequences of characters).
3. Each lexeme is categorized as a token type.
4. The tokenized output is displayed.

The lexical analyzer only identifies tokens and does not check syntax correctness. Syntax analysis is handled by the parser.

## 📋 Requirements

The analyzer performs the following tasks:

- Identify all keywords
- Identify identifiers
- Detect literals such as float, characters, string literals, and decimal values
- Identify arrays
- Display tokenized output

The project can be extended to support functions, pointers, and user-defined data types.

## 🛠 Technologies Used

- C Programming
- File Handling
- Pointers
- Structures
- String Processing
- Tokenization Logic
- Compiler Design Concepts

## 🎯 Applications

Lexical analyzers are used in:

- Compilers
- Interpreters
- Static code analyzers
- Programming language tools

## 🎓 Learning Outcomes

- Understanding lexical analysis in compiler design
- Implementing tokenization logic
- Working with file input and string processing in C
- Building a basic compiler front-end component

## 👨‍💻 Author
Pranav Prasad
EOF
