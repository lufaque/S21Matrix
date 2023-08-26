#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
    rows_ = 3;
    columns_ = 3;
    _matrix = new double *[rows_];

    for (int i = 0; i < rows_; i++) {
        _matrix[i] = new double[columns_];
        for (int j = 0; j < columns_; j++) {
            _matrix[i][j] = 0;
        }
    }
}

S21Matrix::S21Matrix(const int rows, const int columns) {
    if (rows <= 0 || columns <= 0) throw std::invalid_argument("Invalid matrix size");

    rows_ = rows;
    columns_ = columns;
    _matrix = new double *[rows_];

    for (int i = 0; i < rows_; i++) {
        _matrix[i] = new double[columns_];
        for (int k = 0; k < columns_; k++) {
            _matrix[i][k] = 0;
        }
    }
}

S21Matrix::S21Matrix(const S21Matrix &other) noexcept {
    rows_ = other.rows_;
    columns_ = other.columns_;
    _matrix = new double *[rows_];

    for (int i = 0; i < rows_; i++) {
        _matrix[i] = new double[columns_];
        for (int k = 0; k < columns_; k++) {
            _matrix[i][k] = other._matrix[i][k];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
    rows_ = other.rows_;
    columns_ = other.columns_;
    _matrix = other._matrix;
    other._matrix = nullptr;
}

S21Matrix::~S21Matrix() noexcept {
    if (_matrix) {
        for (int i = 0; i < rows_; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
    }
}

void S21Matrix::copy(const S21Matrix *other) {
    const int rows = std::min(rows_, other->rows_);
    const int columns = std::min(columns_, other->columns_);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            _matrix[i][j] = other->_matrix[i][j];
        }
    }
}

void S21Matrix::swap(S21Matrix &other) noexcept {
    std::swap(rows_, other.rows_);
    std::swap(columns_, other.columns_);
    std::swap(_matrix, other._matrix);
}