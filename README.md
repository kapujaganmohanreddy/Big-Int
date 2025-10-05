# BigInt - Arbitrary Precision Integer in C++

A single-file C++ implementation of arbitrary precision integers that can handle very large numbers beyond standard integer limits.

## 📋 About

This is a complete `BigInt` class implementation in a single C++ file that provides:
- Addition of arbitrarily large integers
- Subtraction with proper sign handling  
- Multiplication using school algorithm
- Support for both positive and negative numbers

## 🚀 Quick Start

### Compilation
```bash
g++ -o bigint Big_Int.cpp
```
### Run The Code
```bash
./bigint
```
## 💻 Usage Example

The program provides an interactive menu:
1. Addition
2. Subtraction  
3. Multiplication
4. Exit

Enter your choice: 1  
Enter the number: 12345678901234567890  
Enter the number: 98765432109876543210  
Addition result: 111111111011111111100  

## 🔧 Features
• Unlimited Precision: No maximum number size  
• Sign Handling: Full support for negative numbers  
• Efficient Algorithms: School method arithmetic  
• Clean Output: Automatic leading zero removal  
• Memory Safe: String-based storage  

## 📁 Code Structure
The BigInt class includes:

### Private Members
• string num - Stores the number digits  
• int sign - Tracks positive/negative  

### Key Methods
• removeLeadingZeroes() - Cleans number format  
• addStrings() - School addition algorithm  
• subStrings() - School subtraction algorithm  
• operator*() - Digit-by-digit multiplication  

### Public Interface
• Constructors from string  
• read()/print() for I/O  
• operator+, operator-, operator*  

## ⚠️ Limitations
• No division or modulus operations  
• No input validation for non-digit characters  
• Basic multiplication algorithm (O(n²))  
