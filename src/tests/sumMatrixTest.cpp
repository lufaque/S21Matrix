#include "test.h"

TEST(S21Matrix, SumMatrix){
    S21Matrix matrix1(2, 2);
    S21Matrix matrix2(2, 2);

    matrix1.SumMatrix(matrix2);

    bool isEqual = matrix1.EqMatrix(matrix2);

    EXPECT_TRUE(isEqual);
}