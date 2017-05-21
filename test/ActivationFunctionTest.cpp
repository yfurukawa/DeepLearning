#include "ActivationFunctionTest.h"

ActivationFunctionTest::ActivationFunctionTest() : sut(NULL) {

}

ActivationFunctionTest::~ActivationFunctionTest() {

}

void ActivationFunctionTest::SetUp() {
	sut = new ActivationFunction();
}

void ActivationFunctionTest::TearDown() {
	delete sut;
}

TEST_F (ActivationFunctionTest, testSigmoid) {
	cv::Mat srcMatrix = (cv::Mat_<float>(4, 1) << 1, 2, 3, 4);
	cv::Mat expectMatrix = (cv::Mat_<float>(4, 1) << 0.7310586, 0.88079703, 0.95257413, 0.98201376);

	cv::Mat resultMatrix = sut->sigmoid(srcMatrix);

	for(int row = 0; row < (srcMatrix).rows; ++row) {
	    for(int column = 0; column < (srcMatrix).cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}

TEST_F(ActivationFunctionTest, testStep_Mx1_float) {
	cv::Mat srcMatrix = (cv::Mat_<float>(6, 1) << -2.0, -0.1, 0, 0.1, 2.0, 3.0);
	cv::Mat expectMatrix = (cv::Mat_<float>(6, 1) << 0, 0, 0, 1, 1, 1);

	cv::Mat resultMatrix = sut->step(srcMatrix);

	for(int row = 0; row < srcMatrix.rows; ++row) {
	    for(int column = 0; column < srcMatrix.cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}

TEST_F(ActivationFunctionTest, testStep_1xN_float) {
	cv::Mat srcMatrix = (cv::Mat_<float>(1, 6) << -2.0, -0.1, 0, 0.1, 2.0, 3.0);
	cv::Mat expectMatrix = (cv::Mat_<float>(1, 6) << 0, 0, 0, 1, 1, 1);

	cv::Mat resultMatrix = sut->step(srcMatrix);

	for(int row = 0; row < srcMatrix.rows; ++row) {
	    for(int column = 0; column < srcMatrix.cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}
