#include "s21_matrix_oop.h"

void S21Matrix::MulNumber(const double value) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] *= value;
    }
  }
}
