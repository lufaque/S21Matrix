# S21Matrix - Object-Oriented Matrix Library

## Overview

Welcome to the S21Matrix project! This C++ library provides a class called `S21Matrix` for working with matrices,
including basic matrix operations such as addition, subtraction, multiplication, and various matrix transformations. The
library is designed to be easy to use and efficient for common matrix operations.

## Features

- **Matrix Creation:** Easily create matrices of specified dimensions.
- **Matrix Operations:** Perform standard matrix operations, including addition, subtraction, multiplication, and scalar
  operations.
- **Matrix Transposition:** Calculate the transpose of a matrix.
- **Matrix Determinant:** Compute the determinant of a square matrix.
- **Matrix Inversion:** Find the inverse of a square matrix.
- **Matrix Comparison:** Compare matrices for equality.
- **Matrix Complements:** Calculate the matrix of complements.
- **Flexible Access:** Access matrix elements with a natural syntax using `operator()`.
- **Efficient Memory Management:** Optimal memory allocation and deallocation.

## Getting Started

To start using this library, simply include the `s21_matrix_oop.h` header file in your C++ project. Here's a quick
example
to get you started:

```cpp
#include "s21_matrix_oop.h"

int main() {
    // Create a 3x3 matrix
    S21Matrix matrixA(3, 3);
    
    // Fill the matrix with values
    matrixA(0, 0) = 1.0;
    matrixA(0, 1) = 2.0;
    // ... Fill the rest of the matrix ...

    // Perform matrix operations
    S21Matrix matrixB(3, 3);
    // ... Fill matrixB ...
    
    S21Matrix result = matrixA + matrixB; // Matrix addition
    
    // Calculate the transpose of a matrix
    S21Matrix transposed = matrixA.Transpose();
    
    // Calculate the determinant of a square matrix
    double determinant = matrixA.Determinant();
    
    // Find the inverse of a square matrix
    S21Matrix inverse = matrixA.InverseMatrix();
    
    // Compare matrices for equality
    if (matrixA == matrixB) {
        // Matrices are equal
    } else {
        // Matrices are not equal
    }
    
    return 0;
}
