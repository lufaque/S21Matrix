#include "test.h"

TEST(S21Matrix, InverseMatrix) {
  S21Matrix matrix;
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 1;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = 6;
  matrix(2, 2) = 0;

  S21Matrix invertedMatrix = matrix.InverseMatrix();

  matrix.MulMatrix(invertedMatrix);

  EXPECT_EQ(matrix(0, 0), 1);
  EXPECT_EQ(matrix(0, 1), 0);
  EXPECT_EQ(matrix(0, 2), 0);
  EXPECT_EQ(matrix(1, 0), 0);
  EXPECT_EQ(matrix(1, 1), 1);
  EXPECT_EQ(matrix(1, 2), 0);
  EXPECT_EQ(matrix(2, 0), 0);
  EXPECT_EQ(matrix(2, 1), 0);
  EXPECT_EQ(matrix(2, 2), 1);
}

TEST(S21Matrix, inverseMatrixTest2) {
  S21Matrix A(2, 5);

  try {
    S21Matrix result = A.InverseMatrix();
  } catch (std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Matrix must be square");
  }
}

TEST(S21Matrix, inverseMatrixTest3) {
  S21Matrix A(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 0;
  A(1, 1) = 0;

  try {
    S21Matrix result = A.InverseMatrix();
  } catch (std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Matrix is not invertible");
  }
}