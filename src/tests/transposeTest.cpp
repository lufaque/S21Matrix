#include "test.h"

TEST(S21Matrix, transpose) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B = A.Transpose();

  EXPECT_EQ(B(0, 0), 1);
  EXPECT_EQ(B(0, 1), 3);
  EXPECT_EQ(B(1, 0), 2);
  EXPECT_EQ(B(1, 1), 4);
}