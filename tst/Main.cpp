#include "googletest/include/gtest/gtest.h"
#include "Search.hpp"


TEST(TestGroupSet, Test_BinarySearch)
{   
	double a[10] = {-540,-71,-18,-15,-13,-5,0,1,34,100};
	int p1 = BinarySearch<double>(34, a, 10, [](double x, double y) {if (x > y) return -1; else if (x < y) return 1; else return 0; });
	int p2 = BinarySearch<double>(-15, a, 10, [](double x, double y) {if (x > y) return -1; else if (x < y) return 1; else return 0; });
	int p3 = BinarySearch<double>(54, a, 10, [](double x, double y) {if (x > y) return -1; else if (x < y) return 1; else return 0; });
	int p4 = BinarySearch<double>(3965, a, 10, [](double x, double y) {if (x > y) return -1; else if (x < y) return 1; else return 0; });
	ASSERT_EQ(p1,8);
	ASSERT_EQ(p2,4);
	ASSERT_EQ(p3,-1);
	ASSERT_EQ(p4,-1);
	double b[10] = {-540,71,-18,-15,13,-5,0,1,-34,100};
	int p5 = BinarySearch<double>(13, a, 10, [](double x, double y) {if (x > y) return -1; else if (x < y) return 1; else return 0; });
	ASSERT_EQ(p5,-1)
}
    
TEST(TestGroupSet, Test_InterpolSearch)
{
    	int a[10] = {-540,-71,-18,-15,-13,-5,0,1,34,100};
	int p1 = interpol_search<int>(34, a, 10);
	int p2 = interpol_search<int>(-15, a, 10);
	int p3 = interpol_search<int>(54, a, 10);
	int p4 = interpol_search<int>(3965, a, 10);
	ASSERT_EQ(p1,1);
	ASSERT_EQ(p2,1);
	ASSERT_EQ(p3,0);
	ASSERT_EQ(p4,0);
}

TEST(TestGroupSet, Test_IndexPosledSearch)
{
    	double a[10] = {-540,-71,-18,-15,-13,-5,0,1,34,100};
		int p1 = IndexPosledSearch<double>(a, 10, 5, 34);
	int p2 = IndexPosledSearch<double>(a, 10, 5, -15);
	int p3 = IndexPosledSearch<double>(a, 10, 5, 54);
	int p4 = IndexPosledSearch<double>(a, 10, 5, 3965);
	ASSERT_EQ(p1,1);
	ASSERT_EQ(p2,1);
	ASSERT_EQ(p3,0);
	ASSERT_EQ(p4,0);
}

int main(int argc, char **argv)
{   ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); }