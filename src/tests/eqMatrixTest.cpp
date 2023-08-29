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