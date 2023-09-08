# S21Matrix - Object-Oriented Matrix Library

## Overview

Welcome to S21Matrix, an object-oriented matrix library designed to simplify matrix operations in C++. Whether you're a
student working on a project or a developer in need of a reliable matrix library, S21Matrix is here to help. This
project provides a set of powerful features for creating, manipulating, and performing operations on matrices.

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

To start using this library, simply include the `S21Matrix.h` header file in your C++ project. Here's a quick example
to get you started:

```cpp
#include "S21Matrix.h"

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
