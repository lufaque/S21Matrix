#include "s21_matrix_oop.h"

double S21Matrix::Determinant(void) const {
  if (columns_ != rows_) throw std::invalid_argument("Matrix must be square");

  if (rows_ == 1) return matrix_[0][0];

  if (rows_ == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  double result = 0;
  for (int i = 0; i < columns_; i++) {
    const double sign = i % 2 == 0 ? 1 : -1;
    result += matrix_[0][i] * newMatrixByCrossedOut(0, i).Determinant() * sign;
  }

  return result;
}
