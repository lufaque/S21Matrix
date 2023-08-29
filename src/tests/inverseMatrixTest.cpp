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
  matrix(2, 2) = 10;

  S21Matrix invertedMatrix = matrix.InverseMatrix();

  matrix.MulMatrix(invertedMatrix);

  EXPECT_NEAR(matrix(0, 0), 1, EPSILON);
  EXPECT_NEAR(matrix(0, 1), 0, EPSILON);
  EXPECT_NEAR(matrix(0, 2), 0, EPSILON);
  EXPECT_NEAR(matrix(1, 0), 0, EPSILON);
  EXPECT_NEAR(matrix(1, 1), 1, EPSILON);
  EXPECT_NEAR(matrix(1, 2), 0, EPSILON);
  EXPECT_NEAR(matrix(2, 0), 0, EPSILON);
  EXPECT_NEAR(matrix(2, 1), 0, EPSILON);
  EXPECT_NEAR(matrix(2, 2), 1, EPSILON);
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

TEST(S21Matrix, inverseMatrixTest4) {
  S21Matrix A(5, 5);
  A(0, 0) = 12;
  A(0, 1) = 2.254353453;
  A(0, 2) = 335.534534;
  A(0, 3) = 4.5334;
  A(0, 4) = 5.423;
  A(1, 0) = 0.5433;
  A(1, 1) = 1;
  A(1, 2) = 4.53453;
  A(1, 3) = 230;
  A(1, 4) = 3520.53453;
  A(2, 0) = 5.000001;
  A(2, 1) = 6.0000235;
  A(2, 2) = 50;
  A(2, 3) = 76.534;
  A(2, 4) = 50.534;
  A(3, 0) = 7457.5435;
  A(3, 1) = 0.000002;
  A(3, 2) = 3554774.5670;
  A(3, 3) = 1.532543;
  A(3, 4) = 3.3232;
  A(4, 0) = 6346.5345;
  A(4, 1) = 450.434543;
  A(4, 2) = 4352;
  A(4, 3) = 705345353453;
  A(4, 4) = 631;

  S21Matrix inverseMatrix = A.InverseMatrix();

  A.MulMatrix(inverseMatrix);

  EXPECT_NEAR(A(0, 0), 1, EPSILON);
  EXPECT_NEAR(A(0, 1), 0, EPSILON);
  EXPECT_NEAR(A(0, 2), 0, EPSILON);
  EXPECT_NEAR(A(0, 3), 0, EPSILON);
  EXPECT_NEAR(A(0, 4), 0, EPSILON);
  EXPECT_NEAR(A(1, 0), 0, EPSILON);
  EXPECT_NEAR(A(1, 1), 1, EPSILON);
  EXPECT_NEAR(A(1, 2), 0, EPSILON);
  EXPECT_NEAR(A(1, 3), 0, EPSILON);
  EXPECT_NEAR(A(1, 4), 0, EPSILON);
  EXPECT_NEAR(A(2, 0), 0, EPSILON);
  EXPECT_NEAR(A(2, 1), 0, EPSILON);
  EXPECT_NEAR(A(2, 2), 1, EPSILON);
  EXPECT_NEAR(A(2, 3), 0, EPSILON);
  EXPECT_NEAR(A(2, 4), 0, EPSILON);
  EXPECT_NEAR(A(3, 0), 0, EPSILON);
  EXPECT_NEAR(A(3, 1), 0, EPSILON);
  EXPECT_NEAR(A(3, 2), 0, EPSILON);
  EXPECT_NEAR(A(3, 3), 1, EPSILON);
  EXPECT_NEAR(A(3, 4), 0, EPSILON);
  EXPECT_NEAR(A(4, 0), 0, EPSILON);
  EXPECT_NEAR(A(4, 1), 0, EPSILON);
  EXPECT_NEAR(A(4, 2), 0, EPSILON);
  EXPECT_NEAR(A(4, 3), 0, EPSILON);
  EXPECT_NEAR(A(4, 4), 1, EPSILON);
}
