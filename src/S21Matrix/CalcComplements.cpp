#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements(void) const {
  if (columns_ != rows_) throw std::invalid_argument("Matrix must be square");

  S21Matrix result(rows_, columns_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      const double sign = (i + j) % 2 == 0 ? 1 : -1;
      result.matrix_[i][j] = newMatrixByCrossedOut(i, j).Determinant() * sign;
    }
  }

  return result;
}