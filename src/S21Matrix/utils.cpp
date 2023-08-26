#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
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
    if (rows <= 0 || columns <= 0) throw std::invalid_argument("Invalid matrix size");

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

S21Matrix::S21Matrix(const S21Matrix &other) noexcept {
    _rows = other._rows;
    _columns = other._columns;
    _matrix = new double *[_rows];

    for (int i = 0; i < _rows; i++) {
        _matrix[i] = new double[_columns];
        for (int k = 0; k < _columns; k++) {
            _matrix[i][k] = other._matrix[i][k];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
    _rows = other._rows;
    _columns = other._columns;
    _matrix = other._matrix;
    other._matrix = nullptr;
}

S21Matrix::~S21Matrix() noexcept {
    if (_matrix) {
        for (int i = 0; i < _rows; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}

void S21Matrix::copy(const S21Matrix *other) {
    const int rows = std::min(_rows, other->_rows);
    const int columns = std::min(_columns, other->_columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            _matrix[i][j] = other->_matrix[i][j];
        }
    }
}

void S21Matrix::swap(S21Matrix &other) noexcept {
    std::swap(_rows, other._rows);
    std::swap(_columns, other._columns);
    std::swap(_matrix, other._matrix);
}