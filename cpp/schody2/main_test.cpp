#include <gtest/gtest.h>
#include "functions.cpp"

TEST(SchodyTests, TestIloscStopni){
	EXPECT_EQ(obliczIloscStopni(150, 200), 7);
	EXPECT_EQ(obliczIloscStopni(180, 280), 10);
	EXPECT_EQ(obliczIloscStopni(50, 70), -1);
}

TEST(SchodyTests, TestWymiarySchodka){
	double dlugoscStopnia, wysokoscStopnia;

	obliczWymiaryStopnia(300.0, 150.0, 10, dlugoscStopnia, wysokoscStopnia);
	EXPECT_DOUBLE_EQ(dlugoscStopnia, 30.0);
	EXPECT_DOUBLE_EQ(wysokoscStopnia, 15.0);

	obliczWymiaryStopnia(280.0, 180.0, 10, dlugoscStopnia, wysokoscStopnia);
	EXPECT_DOUBLE_EQ(dlugoscStopnia, 28);
	EXPECT_DOUBLE_EQ(wysokoscStopnia, 18);
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
