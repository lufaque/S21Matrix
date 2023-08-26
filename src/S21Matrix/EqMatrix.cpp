#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
    if (other._rows != this->_rows) return false;
    if (other._columns != this->_columns) return false;

    for (int i = 0; i < this->_rows; i++) {
        for (int k = 0; k < this->_columns; k++) {
            if (this->_matrix[i][k] != other._matrix[i][k]) return false;
        }
    }

    return true;
}