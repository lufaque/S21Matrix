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

TEST(S21Matrix, matrix3){
    S21Matrix matrix(2, 8);
    S21Matrix matrix1(std::move(matrix));

    ASSERT_EQ(matrix1.getRows(), 2);
    ASSERT_EQ(matrix1.getColumns(), 8);
}


TEST(S21Matrix, matrix4){
    S21Matrix matrix(2, 8);

    try {
        matrix.setRows(0);
    } catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Invalid rows count");
    }
}

//TEST(S21Matrix, setRows) {
//    S21Matrix matrix(8, 2);
//
//    matrix.setRows(3);
//
//    ASSERT_EQ(matrix.getRows(), 3);
//}