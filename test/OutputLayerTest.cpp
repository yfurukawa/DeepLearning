#include <opencv2/core.hpp>
#include "OutputLayerTest.h"

OutputLayerTest::OutputLayerTest() : sut(NULL){

}

OutputLayerTest::~OutputLayerTest() {

}

void OutputLayerTest::SetUp() {
	sut = new OutputLayer();
}

void OutputLayerTest::TearDown() {
	delete sut;
}

TEST_F (OutputLayerTest, testSoftmax) {
	cv::Mat srcMatrix = (cv::Mat_<float>(4, 1) << 1.0, 2.0, 3.0, 4.0);
	cv::Mat expectMatrix = (cv::Mat_<float>(4, 1) << 0.0320586, 0.0871443, 0.23688281, 0.64391428);

	cv::Mat resultMatrix = sut->softmax(srcMatrix);

	for(int row = 0; row < (srcMatrix).rows; ++row) {
	    for(int column = 0; column < (srcMatrix).cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}

TEST_F (OutputLayerTest, testSoftmax_general) {
	cv::Mat srcMatrix = (cv::Mat_<float>(3, 1) << 0.3, 2.9, 4.0);
	cv::Mat expectMatrix = (cv::Mat_<float>(3, 1) << 0.018211273, 0.24519183, 0.73659688);

	cv::Mat resultMatrix = sut->softmax(srcMatrix);

	for(int row = 0; row < (srcMatrix).rows; ++row) {
	    for(int column = 0; column < (srcMatrix).cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}

TEST_F (OutputLayerTest, testSoftmax_bigNumber) {
	cv::Mat srcMatrix = (cv::Mat_<float>(3,1) << 1010, 1000, 990);
	cv::Mat expectMatrix = (cv::Mat_<float>(3, 1) << 0.99995458, 4.5397868e-05, 2.0610602e-09);

	cv::Mat resultMatrix = sut->softmax(srcMatrix);

	for(int row = 0; row < (srcMatrix).rows; ++row) {
	    for(int column = 0; column < (srcMatrix).cols; ++column) {
	        EXPECT_FLOAT_EQ(expectMatrix.at<float>(row, column), resultMatrix.at<float>(row, column));
	    }
	}
}
