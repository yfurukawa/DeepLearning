#include "DifferentiationTest.h"

DifferentiationTest::DifferentiationTest() : sut(NULL) {

}

DifferentiationTest::~DifferentiationTest() {

}

void DifferentiationTest::SetUp() {
	sut = new Differentiation();
}

void DifferentiationTest::TearDown() {
	delete sut;
}

TEST_F (DifferentiationTest, testNumericalDiff_value5) {
	float expect(0.2);

	EXPECT_NEAR(expect, sut->numericalDiff(5.0), 0.001);
}

TEST_F (DifferentiationTest, testNumericalDiff_value10) {
	float expect(0.3);

	EXPECT_NEAR(expect, sut->numericalDiff(10.0), 0.001);
}

TEST_F (DifferentiationTest, testNumericalDiff_value3_4) {
	cv::Mat input = (cv::Mat_<float>(1, 2) << 3.0, 4.0);
	cv::Mat result;

	result = sut->numericalDiff(input);
	EXPECT_NEAR(6.0, result.at<float>(0, 0), 0.001 );
	EXPECT_NEAR(8.0, result.at<float>(0, 1), 0.001 );
}

TEST_F (DifferentiationTest, testNumericalDiff_value0_2) {
	cv::Mat input = (cv::Mat_<float>(1, 2) << 0.0, 2.0);
	cv::Mat result;

	result = sut->numericalDiff(input);
	EXPECT_NEAR(0.0, result.at<float>(0, 0), 0.001 );
	EXPECT_NEAR(4.0, result.at<float>(0, 1), 0.001 );
}

TEST_F (DifferentiationTest, testNumericalDiff_value3_0) {
	cv::Mat input = (cv::Mat_<float>(1, 2) << 3.0, 0.0);
	cv::Mat result;

	result = sut->numericalDiff(input);
	EXPECT_NEAR(6.0, result.at<float>(0, 0), 0.001 );
	EXPECT_NEAR(0.0, result.at<float>(0, 1), 0.001 );
}
