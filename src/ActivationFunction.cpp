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

void ActivationFunction::sigmoid(cv::Mat* matrix) {
	cv::Mat tmpMatrix = matrix->clone();
	cv::exp(-1 * tmpMatrix, *matrix);
	*matrix = 1/(1 + *matrix);
}

void ActivationFunction::step(cv::Mat* matrix) {
	for(int row = 0; row < (*matrix).rows; ++row) {
	    for(int column = 0; column < (*matrix).cols; ++column) {
	        matrix->at<float>(row ,column) = (matrix->at<float>(row, column) > 0) ? 1 : 0;
	    }
	}
}
