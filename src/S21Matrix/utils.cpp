#include "s21_matrix_oop.h"

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

S21Matrix::~S21Matrix() {
    if (_matrix) {
        for (int i = 0; i < _rows; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}

int S21Matrix::getRows() {
    return _rows;
}

int S21Matrix::getColumns() {
    return _columns;
}

void S21Matrix::setRows(const int rows) {
    if (rows <= 0) throw std::invalid_argument("Invalid rows count");
    if (_rows != rows) resizeMatrix(rows);
}

void S21Matrix::resizeMatrix(const int rows) {
    _matrix = (double **) realloc(_matrix, rows * sizeof(double *));

    for (int i = _rows; i < rows; i++) {
        _matrix[i] = new double[_columns];
        for (int k = 0; k < _columns; k++) {
            _matrix[i][k] = 0;
        }
    }

    _rows = rows;
}