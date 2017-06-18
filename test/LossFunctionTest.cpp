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

TEST_F (LossFunctionTest, testMeanSquareError) {
	cv::Mat input = (cv::Mat_<float>(1,10) << 0.1, 0.05, 0.6, 0.0, 0.05, 0.1, 0.0, 0.1, 0.0, 0.0);
	cv::Mat label = (cv::Mat_<float>(1,10) << 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

	EXPECT_FLOAT_EQ(0.0975, sut->meanSquaredError(input, label));
}
