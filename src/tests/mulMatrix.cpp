#include "test.h"

TEST(S21Matrix, mulMatrix) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(3, 2);

  B(0, 0) = 7;
  B(0, 1) = 8;
  B(1, 0) = 9;
  B(1, 1) = 10;
  B(2, 0) = 11;
  B(2, 1) = 12;

  A.MulMatrix(B);

  EXPECT_EQ(A(0, 0), 58);
  EXPECT_EQ(A(0, 1), 64);
  EXPECT_EQ(A(1, 0), 139);
  EXPECT_EQ(A(1, 1), 154);
}