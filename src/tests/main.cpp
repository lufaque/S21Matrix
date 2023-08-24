#include "test.h"

TEST(test, test1) {
    int status = test();
    ASSERT_EQ(status, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return (RUN_ALL_TESTS());
}