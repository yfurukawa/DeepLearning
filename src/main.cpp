#include <string>
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "ThreeLayeredNN.h"
#include "MnistReaderOpenCV.h"

int main(int argc, char* argv[]) {
	ThreeLayeredNN network;
	network.initialize();
	network.forward();


	MnistReaderOpenCV mnistReader;
	//int number_of_images = 10000;
	//int image_size = 28 * 28;
	std::string filenamel = "../dataset/t10k-labels-idx1-ubyte";
	//read MNIST label into double vector
	std::vector<double> vecl;
	vecl = mnistReader.readMnistLabel(filenamel);
	std::cout << vecl.size() << std::endl;
	std::cout << vecl[10] << std::endl;

	std::string filename = "../dataset/t10k-images-idx3-ubyte";

    //read MNIST iamge into OpenCV Mat vector
	std::vector<cv::Mat> vec;
	//read_Mnist(filename, vec);
	vec = mnistReader.readMnist(filename);
	if(vec.size() != 0) {
		std::cout << vec.size() << std::endl;
		cv::imshow("1st", vec[10]);
		cv::waitKey();
	}



	return 0;
}
