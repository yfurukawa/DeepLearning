/*
 * Copyright
 *
*/
#include <iostream>
#include "ThreeLayeredNN.h"
#include "ActivationFunction.h"
#include "OutputLayer.h"

ThreeLayeredNN::ThreeLayeredNN() {
}

ThreeLayeredNN::~ThreeLayeredNN() {
}

void ThreeLayeredNN::initialize() {
	network["W1"] = (cv::Mat_<float>(2, 3) << 0.1, 0.3, 0.5, 0.2, 0.4, 0.6);
	network["b1"] = (cv::Mat_<float>(1, 3) << 0.1, 0.2, 0.3);
	network["W2"]	= (cv::Mat_<float>(3, 2) << 0.1, 0.4, 0.2, 0.5, 0.3, 0.6);
	network["b2"]	= (cv::Mat_<float>(1, 2) << 0.1, 0.2);
	network["W3"]	= (cv::Mat_<float>(2, 2) << 0.1, 0.3, 0.2, 0.4);
	network["b3"] = (cv::Mat_<float>(1, 2) << 0.1, 0.2);
}

void ThreeLayeredNN::forward() {
	cv::Mat a1, z1, a2, z2, a3, y;
	ActivationFunction activeFunction;
	OutputLayer outputLayer;

	cv::Mat x = (cv::Mat_<float>(1, 2) << 1.0, 0.5);

	a1 = x * network.at("W1") + network.at("b1");
	z1 = activeFunction.sigmoid(a1);
	a2 = z1 * network.at("W2") + network.at("b2");
	z2 = activeFunction.sigmoid(a2);
	a3 = z2 * network.at("W3") + network.at("b3");

	outputLayer.identity(&a3);

	std::cout << a3 << std::endl;
}
