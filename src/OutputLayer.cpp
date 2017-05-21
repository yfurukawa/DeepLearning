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

cv::Mat OutputLayer::identity(const cv::Mat& matrix) {
	return matrix;
}

cv::Mat OutputLayer::softmax(const cv::Mat& matrix) {
	cv::Mat tmpMatrix;
	cv::Mat resultMatrix;
	float maxValue(findMaxElementValue(matrix));
	cv::exp((matrix - maxValue), tmpMatrix);
	cv::divide(tmpMatrix, cv::sum(tmpMatrix), resultMatrix);
	return resultMatrix;
}

float OutputLayer::findMaxElementValue(const cv::Mat& matrix) {
	float maxValue(0.0);

	for(int row = 0; row < matrix.rows; ++row) {
	    for(int column = 0; column < matrix.cols; ++column) {
	        maxValue = (matrix.at<float>(row, column) > maxValue) ? matrix.at<float>(row, column) : maxValue;
	    }
	}
	return maxValue;
}
