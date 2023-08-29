#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result = S21Matrix(*this);

  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result = S21Matrix(*this);

  result.SubMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result = S21Matrix(*this);

  result.MulMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const double value) const {
  S21Matrix result = S21Matrix(*this);

  result.MulNumber(value);

  return result;
}