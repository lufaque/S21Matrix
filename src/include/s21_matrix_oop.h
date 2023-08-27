#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <iostream>

class S21Matrix {
 private:
  int rows_;
  int columns_;
  double **matrix_;
  void copy(const S21Matrix *other);  // TODO add zeroing!
  void swap(S21Matrix &other) noexcept;
  S21Matrix newMatrixByCrossedOut(int row, int column) const noexcept;

 public:
  S21Matrix() noexcept;
  S21Matrix(const int rows, const int columns);
  S21Matrix(const S21Matrix &other) noexcept;
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix() noexcept;
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double value) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose(void) const noexcept;
  S21Matrix CalcComplements(void) const;
  double Determinant(void) const;
  void print(void);
  void setRows(const int rows);
  void setColumns(const int columns);
  int getRows(void) const;
  int getColumns(void) const;
  double &operator()(const int row, const int column);
};

#endif  // S21_MATRIX_OOP_H