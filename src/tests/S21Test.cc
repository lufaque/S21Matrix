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

TEST(S21Matrix, SumMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);

  matrix1.SumMatrix(matrix2);

  bool isEqual = matrix1.EqMatrix(matrix2);

  EXPECT_TRUE(isEqual);
}

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

TEST(S21Matrix, SubMatrix) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 2);

  try {
    A.SubMatrix(B);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Matrix dimensions must agree");
  }
}

TEST(S21Matrix, SubMatrix2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 7;
  B(2, 1) = 8;
  B(2, 2) = 9;

  A.SubMatrix(B);

  for (int i = 0; i < A.getRows(); i++) {
    for (int j = 0; j < A.getColumns(); j++) {
      ASSERT_EQ(A(i, j), 0);
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return (RUN_ALL_TESTS());
}

// overloading

TEST(S21Matrix, operatorPlus) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B(2, 2);
  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 7;
  B(1, 1) = 8;

  S21Matrix C = B + A;

  EXPECT_EQ(C(0, 0), 6);
  EXPECT_EQ(C(0, 1), 8);
  EXPECT_EQ(C(1, 0), 10);
  EXPECT_EQ(C(1, 1), 12);
}

TEST(S21Matrix, operatorMinus) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B(2, 2);
  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 7;
  B(1, 1) = 8;

  S21Matrix C = B - A;

  EXPECT_EQ(C(0, 0), 4);
  EXPECT_EQ(C(0, 1), 4);
  EXPECT_EQ(C(1, 0), 4);
  EXPECT_EQ(C(1, 1), 4);

  B.setRows(3);

  try {
    S21Matrix D = A - B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix dimensions must agree");
  }
}

TEST(S21Matrix, mul) {
  S21Matrix A(3, 5);
  A(0, 0) = 1;
  A(0, 1) = 1;
  A(0, 2) = 17;
  A(0, 3) = 1;
  A(0, 4) = 11;
  A(1, 0) = 1.254;
  A(1, 1) = 31.729;
  A(1, 2) = 1;
  A(1, 3) = 1;
  A(1, 4) = 9991.3;
  A(2, 0) = 1;
  A(2, 1) = 548;
  A(2, 2) = 456512.351;
  A(2, 3) = 1;
  A(2, 4) = 1;

  S21Matrix B = A * 0.00528;

  EXPECT_NEAR(B(0, 0), 0.00528, EPSILON);
  EXPECT_NEAR(B(0, 1), 0.00528, EPSILON);
  EXPECT_NEAR(B(0, 2), 0.08976, EPSILON);
  EXPECT_NEAR(B(0, 3), 0.00528, EPSILON);
  EXPECT_NEAR(B(0, 4), 0.05808, EPSILON);
  EXPECT_NEAR(B(1, 0), 0.00662112, EPSILON);
  EXPECT_NEAR(B(1, 1), 0.16752912, EPSILON);
  EXPECT_NEAR(B(1, 2), 0.00528, EPSILON);
  EXPECT_NEAR(B(1, 3), 0.00528, EPSILON);
  EXPECT_NEAR(B(1, 4), 52.754064, EPSILON);
  EXPECT_NEAR(B(2, 0), 0.00528, EPSILON);
  EXPECT_NEAR(B(2, 1), 2.89344, EPSILON);
  EXPECT_NEAR(B(2, 2), 2410.38521328, EPSILON);
  EXPECT_NEAR(B(2, 3), 0.00528, EPSILON);
  EXPECT_NEAR(B(2, 4), 0.00528, EPSILON);
}

TEST(S21Matrix, assignmentOperator) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(3, 3);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(0, 2) = 9;
  B(1, 0) = 10;
  B(1, 1) = 11;
  B(1, 2) = 12;

  A = B;

  EXPECT_EQ(A(0, 0), 7);
  EXPECT_EQ(A(0, 1), 8);
  EXPECT_EQ(A(0, 2), 9);
  EXPECT_EQ(A(1, 0), 10);
  EXPECT_EQ(A(1, 1), 11);
  EXPECT_EQ(A(1, 2), 12);
}

TEST(S21Matrix, assignmentOperator2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(2, 2);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(1, 0) = 9;
  B(1, 1) = 10;

  try {
    A = B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix dimensions must agree");
  }
}

TEST(S21Matrix, assignmentPlusOperator) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(3, 3);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(0, 2) = 9;
  B(1, 0) = 10;
  B(1, 1) = 11;
  B(1, 2) = 12;

  A += B;

  EXPECT_EQ(A(0, 0), 8);
  EXPECT_EQ(A(0, 1), 10);
  EXPECT_EQ(A(0, 2), 12);
  EXPECT_EQ(A(1, 0), 14);
  EXPECT_EQ(A(1, 1), 16);
  EXPECT_EQ(A(1, 2), 18);
}

TEST(S21Matrix, assignmentPlusOperator2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(2, 2);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(1, 0) = 9;
  B(1, 1) = 10;

  try {
    A += B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Invalid matrix size.");
  }
}

TEST(S21Matrix, assignmentMinusOperator) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(3, 3);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(0, 2) = 9;
  B(1, 0) = 10;
  B(1, 1) = 11;
  B(1, 2) = 12;

  A -= B;

  EXPECT_EQ(A(0, 0), -6);
  EXPECT_EQ(A(0, 1), -6);
  EXPECT_EQ(A(0, 2), -6);
  EXPECT_EQ(A(1, 0), -6);
  EXPECT_EQ(A(1, 1), -6);
  EXPECT_EQ(A(1, 2), -6);
}

TEST(S21Matrix, assignmentMinusOperator2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(2, 2);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(1, 0) = 9;
  B(1, 1) = 10;

  try {
    A -= B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Matrix dimensions must agree");
  }
}

TEST(S21Matrix, assignmentMulOperator) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(3, 3);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(0, 2) = 9;
  B(1, 0) = 10;
  B(1, 1) = 11;
  B(1, 2) = 12;

  A *= B;

  EXPECT_EQ(A(0, 0), 27);
  EXPECT_EQ(A(0, 1), 30);
  EXPECT_EQ(A(0, 2), 33);
  EXPECT_EQ(A(1, 0), 78);
  EXPECT_EQ(A(1, 1), 87);
  EXPECT_EQ(A(1, 2), 96);
}

TEST(S21Matrix, assignmentMulOperator2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  S21Matrix B(2, 2);
  B(0, 0) = 7;
  B(0, 1) = 8;
  B(1, 0) = 9;
  B(1, 1) = 10;

  try {
    A *= B;
  } catch (std::invalid_argument &e) {
    EXPECT_STREQ(e.what(), "Invalid matrix dimensions");
  }
}

TEST(S21Matrix, assignmentMulNumberOperator) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  A *= 2;

  EXPECT_EQ(A(0, 0), 2);
  EXPECT_EQ(A(0, 1), 4);
  EXPECT_EQ(A(0, 2), 6);
  EXPECT_EQ(A(1, 0), 8);
  EXPECT_EQ(A(1, 1), 10);
  EXPECT_EQ(A(1, 2), 12);
}

TEST(S21Matrix, eqOperator) {
  S21Matrix A(2, 2);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix B(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;

  EXPECT_TRUE(A == B);
}

TEST(S21Matrix, assignmentMulMatrix) {
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

  S21Matrix C = A * B;

  EXPECT_EQ(C(0, 0), 58);
  EXPECT_EQ(C(0, 1), 64);
  EXPECT_EQ(C(1, 0), 139);
  EXPECT_EQ(C(1, 1), 154);
}

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

TEST(S21Matrix, getRows) {
  S21Matrix matrix(7, 4);
  ASSERT_EQ(matrix.getRows(), 7);
  ASSERT_EQ(matrix.getColumns(), 4);
}

TEST(S21Matrix, matrix) {
  try {
    S21Matrix matrix(0, 4);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid matrix size");
  }
}

TEST(S21Matrix, matrix2) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix1(matrix);

  ASSERT_TRUE(matrix.EqMatrix(matrix1));
}

TEST(S21Matrix, matrix3) {
  S21Matrix matrix(2, 8);
  S21Matrix matrix1(std::move(matrix));

  ASSERT_EQ(matrix1.getRows(), 2);
  ASSERT_EQ(matrix1.getColumns(), 8);
}

TEST(S21Matrix, matrix4) {
  S21Matrix matrix(2, 8);

  try {
    matrix.setRows(0);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid rows count");
  }
}

TEST(S21Matrix, setRows) {
  S21Matrix matrix(81, 242);

  matrix.setRows(3);
  matrix.setColumns(31);

  ASSERT_EQ(matrix.getRows(), 3);
  ASSERT_EQ(matrix.getColumns(), 31);

  matrix.setRows(100);
  matrix.setColumns(90);

  ASSERT_EQ(matrix.getRows(), 100);
  ASSERT_EQ(matrix.getColumns(), 90);

  try {
    matrix.setRows(0);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid rows count");
  }

  try {
    matrix.setColumns(-10);
  } catch (std::invalid_argument &e) {
    ASSERT_STREQ(e.what(), "Invalid columns count");
  }
}

TEST(S21Matrix, setColumns) {
  S21Matrix matrix;
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  matrix.setColumns(5);
  matrix.setRows(5);

  ASSERT_EQ(matrix.getRows(), 5);
  ASSERT_EQ(matrix.getColumns(), 5);

  EXPECT_NEAR(matrix(0, 0), 1, EPSILON);
  EXPECT_NEAR(matrix(0, 1), 2, EPSILON);
  EXPECT_NEAR(matrix(0, 2), 3, EPSILON);
  EXPECT_NEAR(matrix(0, 3), 0, EPSILON);
  EXPECT_NEAR(matrix(0, 4), 0, EPSILON);
  EXPECT_NEAR(matrix(1, 0), 4, EPSILON);
  EXPECT_NEAR(matrix(1, 1), 5, EPSILON);
  EXPECT_NEAR(matrix(1, 2), 6, EPSILON);
  EXPECT_NEAR(matrix(1, 3), 0, EPSILON);
  EXPECT_NEAR(matrix(1, 4), 0, EPSILON);
  EXPECT_NEAR(matrix(2, 0), 7, EPSILON);
  EXPECT_NEAR(matrix(2, 1), 8, EPSILON);
  EXPECT_NEAR(matrix(2, 2), 9, EPSILON);
  EXPECT_NEAR(matrix(2, 3), 0, EPSILON);
  EXPECT_NEAR(matrix(2, 4), 0, EPSILON);
  EXPECT_NEAR(matrix(3, 0), 0, EPSILON);
  EXPECT_NEAR(matrix(3, 1), 0, EPSILON);
  EXPECT_NEAR(matrix(3, 2), 0, EPSILON);
  EXPECT_NEAR(matrix(3, 3), 0, EPSILON);
  EXPECT_NEAR(matrix(3, 4), 0, EPSILON);
  EXPECT_NEAR(matrix(4, 0), 0, EPSILON);
  EXPECT_NEAR(matrix(4, 1), 0, EPSILON);
  EXPECT_NEAR(matrix(4, 2), 0, EPSILON);
  EXPECT_NEAR(matrix(4, 3), 0, EPSILON);
  EXPECT_NEAR(matrix(4, 4), 0, EPSILON);
}

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
  } catch (std::invalid_argument &e) {
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
  } catch (std::invalid_argument &e) {
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
