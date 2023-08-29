#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
  rows_ = 3;
  columns_ = 3;
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[columns_];
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(const int rows, const int columns)
    : rows_(rows), columns_(columns) {
  if (rows <= 0 || columns <= 0)
    throw std::invalid_argument("Invalid matrix size");
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[columns_];
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] = 0;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) noexcept {
  rows_ = other.rows_;
  columns_ = other.columns_;
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[columns_];
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] = other.matrix_[i][k];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  rows_ = other.rows_;
  columns_ = other.columns_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() noexcept {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

void S21Matrix::copy(const S21Matrix *other) {
  const int rows = std::min(rows_, other->rows_);
  const int columns = std::min(columns_, other->columns_);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      matrix_[i][j] = other->matrix_[i][j];
    }
  }
}

void S21Matrix::swap(S21Matrix &other) noexcept {
  std::swap(rows_, other.rows_);
  std::swap(columns_, other.columns_);
  std::swap(matrix_, other.matrix_);
}
