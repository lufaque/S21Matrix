#include "s21_matrix_oop.h"

void S21Matrix::setRows(const int rows) {
  if (rows <= 0) throw std::invalid_argument("Invalid rows count");
  S21Matrix tmp(rows, columns_);
  tmp.copy(this);
  swap(tmp);
}

void S21Matrix::setColumns(const int columns) {
  if (columns <= 0) throw std::invalid_argument("Invalid columns count");
  S21Matrix tmp(rows_, columns);
  tmp.copy(this);
  swap(tmp);
}