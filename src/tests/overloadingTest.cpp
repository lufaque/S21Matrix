#include "test.h"

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