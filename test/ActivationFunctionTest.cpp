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
	cv::Mat srcMatrix = (cv::Mat_<float>(4,1) << 1, 2, 3, 4);
	cv::Mat expectMatrix = (cv::Mat_<float>(4,1) << 0.7310586, 0.88079703, 0.95257413, 0.98201376);
	std::cout << srcMatrix << std::endl;
	sut->sigmoid(&srcMatrix);
	std::cout << srcMatrix << std::endl;

}

TEST_F(ActivationFunctionTest, testStep_Mx1_float) {
	cv::Mat srcMatrix = (cv::Mat_<float>(6,1) << -2.0, -0.1, 0, 0.1, 2.0, 3.0);
	std::cout << srcMatrix << std::endl;
	sut->step(&srcMatrix);
	std::cout << srcMatrix << std::endl;
}

TEST_F(ActivationFunctionTest, testStep_1xN_float) {
	cv::Mat srcMatrix = (cv::Mat_<float>(6,1) << -2.0, -0.1, 0, 0.1, 2.0, 3.0);
	std::cout << srcMatrix << std::endl;
	sut->step(&srcMatrix);
	std::cout << srcMatrix << std::endl;
}
