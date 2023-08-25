#include "test.h"

TEST(test, test1) {
    S21Matrix matrix(3, 6);
    matrix.printMatrix();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return (RUN_ALL_TESTS());
}