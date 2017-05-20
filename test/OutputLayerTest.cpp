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
	cv::Mat srcMatrix = (cv::Mat_<float>(4,1) << 1.0, 2.0, 3.0, 4.0);
	sut->softmax(&srcMatrix);
	std::cout << srcMatrix << std::endl;
}

TEST_F (OutputLayerTest, testSoftmax_general) {
	cv::Mat srcMatrix = (cv::Mat_<float>(3,1) << 0.3, 2.9, 4.0);
	sut->softmax(&srcMatrix);
	std::cout << srcMatrix << std::endl;
}

TEST_F (OutputLayerTest, testSoftmax_bigNumber) {
	cv::Mat srcMatrix = (cv::Mat_<float>(3,1) << 1010, 1000, 990);
	sut->softmax(&srcMatrix);
	std::cout << srcMatrix << std::endl;
}
