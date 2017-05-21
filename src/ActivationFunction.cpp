/*
 * Copyright
 *
*/
#include <iostream>
#include "./ActivationFunction.h"

ActivationFunction::ActivationFunction() {
}

ActivationFunction::~ActivationFunction() {
}

cv::Mat ActivationFunction::sigmoid(const cv::Mat& matrix) {
	cv::Mat tmpMatrix;
	cv::exp(-1 * matrix, tmpMatrix);
	return 1/(1 + tmpMatrix);
}

cv::Mat ActivationFunction::step(const cv::Mat& matrix) {
	cv::Mat tmpMatrix = matrix.clone();
	for(int row = 0; row < matrix.rows; ++row) {
	    for(int column = 0; column < matrix.cols; ++column) {
	        tmpMatrix.at<float>(row ,column) = (matrix.at<float>(row, column) > 0) ? 1 : 0;
	    }
	}
	return tmpMatrix;
}
