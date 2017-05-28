#include <iostream>
#include "MnistReaderOpenCVTest.h"

MnistReaderOpenCVTest::MnistReaderOpenCVTest() : sut(NULL) {

}

MnistReaderOpenCVTest::~MnistReaderOpenCVTest() {

}

void MnistReaderOpenCVTest::SetUp() {
	sut = new MnistReaderOpenCV();
}

void MnistReaderOpenCVTest::TearDown() {
	delete sut;
}

TEST_F (MnistReaderOpenCVTest, testReadMnist_unnormalize_unflatten) {
	std::string filename = "../dataset/t10k-images-idx3-ubyte";
	std::vector<cv::Mat> vec;
	bool normalize(false);
	bool flatten(false);

	vec = sut->readMnist(filename, normalize, flatten);

	// std::cout << vec[0] << std::endl;

	EXPECT_EQ(10000, vec.size());
	EXPECT_FLOAT_EQ(254, vec[0].at<float>(8, 8));
	EXPECT_FLOAT_EQ(2, vec[0].dims);
}

TEST_F (MnistReaderOpenCVTest, testReadMnist_normalize_unflatten) {
	std::string filename = "../dataset/t10k-images-idx3-ubyte";
	std::vector<cv::Mat> vec;
	bool normalize(true);
	bool flatten(false);

	vec = sut->readMnist(filename, normalize, flatten);

	// std::cout << vec[0] << std::endl;

	EXPECT_EQ(10000, vec.size());
	EXPECT_NEAR(0.996078431372549, vec[0].at<float>(8, 8), 1e-5);
	EXPECT_EQ(2, vec[0].dims);
}


TEST_F (MnistReaderOpenCVTest, testReadMnist_unnormalize_flatten) {
	std::string filename = "../dataset/t10k-images-idx3-ubyte";
	std::vector<cv::Mat> vec;
	bool normalize(false);
	bool flatten(true);

	vec = sut->readMnist(filename, normalize, flatten);

	//std::cout << vec[0] << std::endl;

	EXPECT_EQ(10000, vec.size());
	EXPECT_EQ(784, vec[0].cols);
	EXPECT_EQ(1, vec[0].rows);
}


TEST_F (MnistReaderOpenCVTest, testReadMnist_normalize_flatten) {
	std::string filename = "../dataset/t10k-images-idx3-ubyte";
	std::vector<cv::Mat> vec;
	bool normalize(true);
	bool flatten(true);

	vec = sut->readMnist(filename, normalize, flatten);

	/*
	std::cout << vec[0] << std::endl;
	for(int col = 180; col <= 190; ++col) {
		std::cout << "col = " << col << " : " << vec[0].at<float>(1,col) << std::endl;
	}
	*/
	EXPECT_EQ(10000, vec.size());
	EXPECT_NEAR(0.9921568, vec[0].at<float>(1,185), 1e-5);
	EXPECT_EQ(784, vec[0].cols);
	EXPECT_EQ(1, vec[0].rows);
}
