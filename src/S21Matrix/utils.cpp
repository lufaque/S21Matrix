#include "s21_matrix.h"

S21Matrix::S21Matrix() {
    _rows = 3;
    _columns = 3;
    _matrix = new double *[_rows];

    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_columns];
        for (int j = 0; j < _columns; j++) {
            _matrix[i][j] = 0;
        }
    }
}

S21Matrix::S21Matrix(const int rows, const int columns) {
    _rows = rows;
    _columns = columns;
    _matrix = new double *[_rows];

    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_columns];
        for (int k = 0; k < _columns; k++) {
            _matrix[i][k] = 0;
        }
    }
}

S21Matrix::~S21Matrix() {
    if (_matrix) {
        for (int i = 0; i < _rows; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}