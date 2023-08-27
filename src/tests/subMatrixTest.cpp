#include "test.h"

TEST(S21Matrix, SubMatrix){
    S21Matrix A(3,3);
    S21Matrix B(2,2);

    try {
        A.SubMatrix(B);
    } catch (std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Matrix dimensions must agree");
    }
}


TEST(S21Matrix, SubMatrix2){
    S21Matrix A(3,3);
    S21Matrix B(3,3);

    A(0,0) = 1;
    A(0,1) = 2;
    A(0,2) = 3;
    A(1,0) = 4;
    A(1,1) = 5;
    A(1,2) = 6;
    A(2,0) = 7;
    A(2,1) = 8;
    A(2,2) = 9;

    B(0,0) = 1;
    B(0,1) = 2;
    B(0,2) = 3;
    B(1,0) = 4;
    B(1,1) = 5;
    B(1,2) = 6;
    B(2,0) = 7;
    B(2,1) = 8;
    B(2,2) = 9;


    A.SubMatrix(B);

    for (int i = 0; i < A.getRows(); i++) {
        for (int j = 0; j < A.getColumns(); j++) {
            ASSERT_EQ(A(i,j), 0);
        }
    }
}