#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
    if (other._rows != _rows || other._columns != _columns) throw std::invalid_argument("Invalid matrix size.");

    for (int i = 0; i < _rows; i++) {
        for (int k = 0; k < _columns; k++) {
            _matrix[i][k] += other._matrix[i][k];
        }
    }

}