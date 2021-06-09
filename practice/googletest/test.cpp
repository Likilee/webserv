#include "gtest/gtest.h"
#include "main.cpp"

TEST(Multiply, TwoMultiplyThree) {
	EXPECT_EQ(multiply(2, 3), 6);
}

TEST(Multiply, MultiplyZero) {
	EXPECT_EQ(multiply(2, 0), 0);
	EXPECT_EQ(multiply(-1, 0), 0);
	EXPECT_EQ(multiply(0, 0), 0);
}

TEST(Max, PositiveMax) {
	ASSERT_EQ(myMax(1, 3, 2), 3);
	ASSERT_EQ(myMax(2, 3, 2), 3);
	ASSERT_EQ(myMax(5, 5, 5), 5);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
