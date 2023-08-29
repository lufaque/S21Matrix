#include "s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || columns_ != other.columns_)
    throw std::invalid_argument("Matrix dimensions must agree");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}