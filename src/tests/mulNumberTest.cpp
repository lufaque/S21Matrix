#include "test.h"

TEST(S21Matrix, mulNumber) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  matrix.MulNumber(2);

  ASSERT_EQ(matrix(0, 0), 2);
  ASSERT_EQ(matrix(0, 1), 4);
  ASSERT_EQ(matrix(1, 0), 6);
  ASSERT_EQ(matrix(1, 1), 8);
}