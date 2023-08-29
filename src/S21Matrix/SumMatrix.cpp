#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (other.rows_ != rows_ || other.columns_ != columns_)
    throw std::invalid_argument("Invalid matrix size.");

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] += other.matrix_[i][k];
    }
  }
}