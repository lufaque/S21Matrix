#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose(void) const noexcept {
  S21Matrix result(*this);

  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.columns_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }

  return result;
}