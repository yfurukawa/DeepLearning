#include "LossFunctionTest.h"

LossFunctionTest::LossFunctionTest() : sut(NULL) {

}

LossFunctionTest::~LossFunctionTest() {

}

void LossFunctionTest::SetUp() {
	sut = new LossFunction();
}

void LossFunctionTest::TearDown() {
	delete sut;
}

TEST_F (LossFunctionTest, testMeanSquareError_Correct) {
	cv::Mat input = (cv::Mat_<float>(1,10) << 0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0);
	cv::Mat label = (cv::Mat_<float>(1,10) << 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	EXPECT_FLOAT_EQ(0.0975, sut->meanSquaredError(input, label));
}


TEST_F (LossFunctionTest, testMeanSquareError_NotCorrect) {
	cv::Mat input = (cv::Mat_<float>(1,10) << 0.1, 0.05, 0.1, 0.0, 0.05, 0.1, 0.0, 0.6, 0.0, 0.0);
	cv::Mat label = (cv::Mat_<float>(1,10) << 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	EXPECT_FLOAT_EQ(0.5975, sut->meanSquaredError(input, label));
}


TEST_F (LossFunctionTest, testCrossEntropyError_Correct) {
	cv::Mat input = (cv::Mat_<float>(1,10) << 0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0);
	cv::Mat label = (cv::Mat_<float>(1,10) << 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	EXPECT_FLOAT_EQ(0.5108254, sut->crossEntropyError(input, label));
}


TEST_F (LossFunctionTest, testCrossEntropyError_NotCorrect) {
	cv::Mat input = (cv::Mat_<float>(1,10) << 0.1, 0.05, 0.1, 0.0, 0.05, 0.1, 0.0, 0.6, 0.0, 0.0);
	cv::Mat label = (cv::Mat_<float>(1,10) << 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	EXPECT_FLOAT_EQ(2.3025841, sut->crossEntropyError(input, label));
}
