#ifndef S21MATRIX_INCLUDE_S21_MATRIX_OOP_H_
#define S21MATRIX_INCLUDE_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  explicit S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;

  ~S21Matrix();

  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other);
  bool operator==(const S21Matrix &other) const;
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double value) const;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double value);
  double &operator()(const int row, const int column);

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double value) noexcept;
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  void SetRows(const int rows);
  void SetColumns(const int columns);
  int GetRows() const noexcept;
  int GetColumns() const noexcept;

  static const double Epsilon;

 private:
  int rows_;
  int columns_;
  double **matrix_;

  void CreateMatrix();
  void Copy(const S21Matrix &other);
  void Swap(S21Matrix &other);
  S21Matrix NewMatrixByCrossedOut(int row, int column) const;
  bool IsEqual(const double a, const double b) const;
};

#endif  // S21MATRIX_INCLUDE_S21_MATRIX_OOP_H_