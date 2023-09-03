#include "s21_matrix_oop.h"

const double S21Matrix::Epsilon = 0.0000001;

S21Matrix::S21Matrix() : rows_(3), columns_(3) { CreateMatrix(); }

S21Matrix::S21Matrix(int rows, int columns) : rows_(rows), columns_(columns) {
  if (rows <= 0 || columns <= 0)
    throw std::invalid_argument("Invalid matrix size");
  CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), columns_(other.columns_) {
  CreateMatrix();
  Copy(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), columns_(other.columns_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.columns_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  Copy(other);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  Swap(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  return EqMatrix(other);
}

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

double& S21Matrix::operator()(int rows, int columns) {
  if (rows < 0 || rows >= rows_) throw std::invalid_argument("Invalid row");
  if (columns < 0 || columns >= columns_) {
    throw std::invalid_argument("Invalid column");
  }
  return matrix_[rows][columns];
}

void S21Matrix::SetRows(const int rows) {
  if (rows <= 0) throw std::invalid_argument("Invalid rows count");
  S21Matrix tmp(rows, columns_);
  tmp.Copy(*this);
  Swap(tmp);
}

void S21Matrix::SetColumns(const int columns) {
  if (columns <= 0) throw std::invalid_argument("Invalid columns count");
  S21Matrix tmp(rows_, columns);
  tmp.Copy(*this);
  Swap(tmp);
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetColumns() const noexcept { return columns_; }

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (other.rows_ != rows_) return false;
  if (other.columns_ != columns_) return false;

  bool result = true;

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      if (!IsEqual(matrix_[i][k], other.matrix_[i][k])) {
        result = false;
      }
    }
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (other.rows_ != rows_ || other.columns_ != columns_)
    throw std::invalid_argument("Invalid matrix size.");

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] += other.matrix_[i][k];
    }
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(columns_, rows_);

  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.columns_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }

  return result;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || columns_ != other.columns_)
    throw std::invalid_argument("Matrix dimensions must agree");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double value) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] *= value;
    }
  }
}

S21Matrix S21Matrix::NewMatrixByCrossedOut(int row, int column) const {
  S21Matrix newMatrix(rows_ - 1, columns_ - 1);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < columns_; j++)
      if (i != row && j != column)
        newMatrix.matrix_[i - (i > row)][j - (j > column)] = matrix_[i][j];

  return newMatrix;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (columns_ != other.rows_)
    throw std::invalid_argument("Invalid matrix dimensions");

  S21Matrix result(rows_, other.columns_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.columns_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  Swap(result);
}

double S21Matrix::Determinant() const {
  if (columns_ != rows_) throw std::invalid_argument("Matrix must be square");

  double result = 0;

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < columns_; i++) {
      const double sign = i % 2 == 0 ? 1 : -1;
      result +=
          matrix_[0][i] * NewMatrixByCrossedOut(0, i).Determinant() * sign;
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (columns_ != rows_) throw std::invalid_argument("Matrix must be square");
  if (rows_ == 1) return *this;

  S21Matrix result(rows_, columns_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      const double sign = (i + j) % 2 == 0 ? 1 : -1;
      result.matrix_[i][j] = NewMatrixByCrossedOut(i, j).Determinant() * sign;
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  try {
    double determinant = Determinant();
    if (std::abs(determinant) < S21Matrix::Epsilon) {
      throw std::invalid_argument("Matrix is not invertible");
    }

    S21Matrix complements = CalcComplements();
    S21Matrix transposedComplements = complements.Transpose();
    determinant = 1.0f / determinant;
    if (rows_ > 1) {
      transposedComplements.MulNumber(determinant);
    } else {
      matrix_[0][0] = determinant;
    }

    return transposedComplements;
  } catch (const std::invalid_argument& e) {
    throw std::invalid_argument(e.what());
  }
}

void S21Matrix::CreateMatrix() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[columns_];
    for (int k = 0; k < columns_; k++) {
      matrix_[i][k] = 0;
    }
  }
}

void S21Matrix::Copy(const S21Matrix& other) noexcept {
  const int rows = std::min(rows_, other.rows_);
  const int columns = std::min(columns_, other.columns_);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::Swap(S21Matrix& other) {
  std::swap(rows_, other.rows_);
  std::swap(columns_, other.columns_);
  std::swap(matrix_, other.matrix_);
}

bool S21Matrix::IsEqual(double a, double b) const noexcept {
  return std::fabs(a - b) < Epsilon;
}