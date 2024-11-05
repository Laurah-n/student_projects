// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"
#include <string>

TEST(FizzBuzzTests, ReturnsFizzForMultipleOf3) {
 //#TODO: tu napisz test
	string result = FizzBuzz(3);
	EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTests, ReturnsBuzzForMultipleOf5) {
  //#TODO: tu napisz test
	string result = FizzBuzz(5);
	EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTests, ReturnsEmptyStringForNonMultipleOf3Or5) {
  //#TODO: tu napisz test
	string result = FizzBuzz(15);
	EXPECT_EQ(result, "FizzBuzz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

