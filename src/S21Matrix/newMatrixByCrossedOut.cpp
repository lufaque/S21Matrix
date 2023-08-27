#include "s21_matrix_oop.h"

S21Matrix S21Matrix::newMatrixByCrossedOut(int row, int column) const noexcept {
  S21Matrix newMatrix(rows_ - 1, columns_ - 1);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < columns_; j++)
      if (i != row && j != column)
        newMatrix.matrix_[i - (i > row)][j - (j > column)] = matrix_[i][j];

  return newMatrix;
}