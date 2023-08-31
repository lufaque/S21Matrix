#ifndef SRC_INCLUDE_S21_MATRIX_OOP_H_
#define SRC_INCLUDE_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define EPSILON 0.0000001

class S21Matrix {
 public:
  S21Matrix() noexcept;
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix &other) noexcept;
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix() noexcept;
  S21Matrix &operator=(S21Matrix &other) noexcept;
  bool operator==(const S21Matrix &other) noexcept;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double value) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double value);
  bool EqMatrix(const S21Matrix &other) noexcept;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double value) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose(void) const noexcept;
  S21Matrix CalcComplements(void) const;
  double Determinant(void) const;
  S21Matrix InverseMatrix(void) const;
  void Print(void);
  void SetRows(const int rows);
  void SetColumns(const int columns);
  int GetRows(void) const;
  int GetColumns(void) const;
  double &operator()(const int row, const int column);

 private:
  int rows_;
  int columns_;
  double **matrix_;
  void Copy(const S21Matrix *other) noexcept;
  void Swap(S21Matrix &other) noexcept;
  S21Matrix NewMatrixByCrossedOut(int row, int column) const noexcept;
  bool IsEqual(const double a, const double b);
};

#endif  // SRC_INCLUDE_S21_MATRIX_OOP_H_