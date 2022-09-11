#include "pch.h"
#include"C:\\Users\\Виктор\\source\\repos\\week_8_tests\\week_8_tests\\Rational.h"
#include"C:\\Users\\Виктор\\source\\repos\\week_8_tests\\week_8_tests\\Rational.cpp"

TEST(TestDefaultConstructor, CheckDefaultParam) {
	Rational r;
  EXPECT_EQ(r.get_a(), 0);
  EXPECT_EQ(r.get_b(), 1);
}
TEST(TCheckFile, PrintInFile) {
	std::ofstream outf;
	outf.open("output.txt");
	ASSERT_EQ(1,outf.is_open());

}
TEST(TestConstructorWithParam, CheckParam1) {
	Rational r(1,2);
	EXPECT_EQ(r.get_a(), 1);
	EXPECT_EQ(r.get_b(), 2);
}
TEST(TestConstructorWithParam, CheckParam2) {
	Rational r(1, 0);
	EXPECT_EQ(r.get_a(), 1);
	EXPECT_EQ(r.get_b(), 1);
}
TEST(TestSum, CheckReduce) {
	Rational r1(1, 2);
	Rational r2(1, 2);
	Rational sum(1, 2);
	sum = r1 + r2;
	EXPECT_EQ(sum.get_a(), 1);
	EXPECT_EQ(sum.get_b(), 1);
}

//TEST(TestSum, CheckZero) {
//	Rational r1(1, 2);
//	Rational r2(-1, 2);
//	Rational sum;
//	sum = r1 + r2;
//	EXPECT_EQ(sum.get_a(), 0);
//}
