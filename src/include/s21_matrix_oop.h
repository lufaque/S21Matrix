#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

#define EPSILON 0.0000001

class S21Matrix {
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
  S21Matrix InverseMatrix(void) const;
  void print(void);
  void setRows(const int rows);
  void setColumns(const int columns);
  int getRows(void) const;
  int getColumns(void) const;
  double &operator()(const int row, const int column);
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double value) const;
  S21Matrix operator==(const S21Matrix &other) const;
  S21Matrix &operator=(S21Matrix &other) noexcept;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double value);

 private:
  int rows_;
  int columns_;
  double **matrix_;
  void copy(const S21Matrix *other);  // TODO add zeroing!
  void swap(S21Matrix &other) noexcept;
  S21Matrix newMatrixByCrossedOut(int row, int column) const noexcept;
  bool isEqual(double a, double b);
};

#endif  // S21_MATRIX_OOP_H