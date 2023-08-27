#include "test.h"

TEST(S21Matrix, CalcComplements) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  S21Matrix c = A.CalcComplements();

  EXPECT_EQ(c(0, 0), -3);
  EXPECT_EQ(c(0, 1), 6);
  EXPECT_EQ(c(0, 2), -3);
  EXPECT_EQ(c(1, 0), 6);
  EXPECT_EQ(c(1, 1), -12);
  EXPECT_EQ(c(1, 2), 6);
  EXPECT_EQ(c(2, 0), -3);
  EXPECT_EQ(c(2, 1), 6);
  EXPECT_EQ(c(2, 2), -3);
}