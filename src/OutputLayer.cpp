/*
 * Copyright
 *
*/
#include "./OutputLayer.h"
#include <iostream>

OutputLayer::OutputLayer() {
}

OutputLayer::~OutputLayer() {
}

void OutputLayer::identity(cv::Mat* matrix) {
	// 入力をそのまま出力すればよいので、処理不要
}

void OutputLayer::softmax(cv::Mat* matrix) {
	cv::Mat tmpMatrix;
	cv::exp(*matrix, tmpMatrix);
	cv::divide(tmpMatrix, cv::sum(tmpMatrix), *matrix);
	std::cout << *matrix << std::endl;
}
