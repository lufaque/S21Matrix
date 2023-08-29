#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix(void) const {
  try {
    double determinant = Determinant();
    if (determinant == 0) {
      throw std::invalid_argument("Matrix is not invertible");
    }

    S21Matrix complements = CalcComplements();
    S21Matrix transposedComplements = complements.Transpose();
    determinant = 1 / determinant;
    transposedComplements.MulNumber(determinant);

    return transposedComplements;
  } catch (const std::invalid_argument& e) {
    throw std::invalid_argument(e.what());
  }
}