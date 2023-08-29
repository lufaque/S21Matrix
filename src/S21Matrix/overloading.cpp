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

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  bool result = EqMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator=(S21Matrix& other) noexcept {
  swap(other);
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double value) {
  MulNumber(value);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_) throw std::invalid_argument("Invalid row");
  if (j < 0 || j >= columns_) throw std::invalid_argument("Invalid column");
  return matrix_[i][j];
}
