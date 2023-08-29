#include "test.h"

TEST(eqTest, eqTest) {
  S21Matrix matrix(3, 6);
  S21Matrix matrix1;

  bool result = matrix.EqMatrix(matrix1);

  ASSERT_EQ(result, false);
}

TEST(eqTest, eqTest1) {
  S21Matrix matrix(10, 20);
  S21Matrix matrix1(10, 20);

  bool result = matrix.EqMatrix(matrix1);

  ASSERT_EQ(result, true);
}

TEST(S21Matrix, eqTest2) {
  S21Matrix A(4, 4);
  S21Matrix B(4, 4);

  A(0, 0) = 1.642;
  A(0, 1) = 2.5435823745;
  A(0, 2) = 3.45646;
  A(0, 3) = 4.5345356;
  A(1, 0) = 5.65464;
  A(1, 1) = 6.65464;
  A(1, 2) = 7.65464;
  A(1, 3) = 8.65464;
  A(2, 0) = 9.65464;
  A(2, 1) = 10.65464;
  A(2, 2) = 11.65464;
  A(2, 3) = 12.8762464;
  A(3, 0) = 13.65464;
  A(3, 1) = 14.65464;
  A(3, 2) = 15.65464;
  A(3, 3) = 16.65464;

  B(0, 0) = 1.642;
  B(0, 1) = 2.5435823745;
  B(0, 2) = 3.45646;
  B(0, 3) = 4.5345356;
  B(1, 0) = 5.65464;
  B(1, 1) = 6.65464;
  B(1, 2) = 7.65464;
  B(1, 3) = 8.65464;
  B(2, 0) = 9.65464;
  B(2, 1) = 10.65464;
  B(2, 2) = 11.65464;
  B(2, 3) = 12.8762462;
  B(3, 0) = 13.65464;
  B(3, 1) = 14.65464;
  B(3, 2) = 15.65464;
  B(3, 3) = 16.65464;

  bool result = A == B;

  ASSERT_EQ(result, false);
}