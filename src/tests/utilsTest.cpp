#include "test.h"

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
