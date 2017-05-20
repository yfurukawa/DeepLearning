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
	float maxValue(findMaxElementValue(matrix));
	cv::exp((*matrix - maxValue), tmpMatrix);
	cv::divide(tmpMatrix, cv::sum(tmpMatrix), *matrix);
}

float OutputLayer::findMaxElementValue(cv::Mat* matrix) {
	float maxValue(0.0);
	for(int row = 0; row < (*matrix).rows; ++row) {
	    for(int column = 0; column < (*matrix).cols; ++column) {
	        maxValue = (matrix->at<float>(row, column) > maxValue) ? matrix->at<float>(row, column) : maxValue;
	    }
	}
	return maxValue;
}
