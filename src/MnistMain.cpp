/*!------------------------------------------------
@file       MnistMain.h
@brief      
@attention  なし
--------------------------------------------------*/
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "MnistReaderOpenCV.h"
#include "MnistMain.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistMain::MnistMain() : argc_(0), argv_(0x00) {
}

/*!------------------------------------------------
@brief      コンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistMain::MnistMain(int argc, char** argv) : argc_(argc), argv_(argv) {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
MnistMain::~MnistMain() {
}

/*!------------------------------------------------
@brief      処理を開始する
@note       処理を開始する
@return     なし
@attention  なし
--------------------------------------------------*/
int MnistMain::run() {
	initialize();

	return 0;
}

/*!------------------------------------------------
@brief      
@note       
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out] 
@return     なし
@attention  なし
--------------------------------------------------*/
void MnistMain::initialize() {
	MnistReaderOpenCV* mnistReader;
	mnistReader = new MnistReaderOpenCV();

	//イメージ数 = 10000
	//イメージサイズ = 28 * 28

	cv::Mat labels;
	bool oneHotLabel(true);
	std::string filename = "../dataset/t10k-labels-idx1-ubyte";
	labels = mnistReader->readMnistLabel(filename, oneHotLabel);
	/*
	std::cout << labels.size() << std::endl;
	std::cout << labels.at<float>(0) << std::endl;
	*/

	//read MNIST iamge into OpenCV Mat vector
	filename = "../dataset/t10k-images-idx3-ubyte";
	std::vector<cv::Mat> images;
	bool normalize(false);
	bool flatten(false);

	images = mnistReader->readMnist(filename, normalize, flatten);
	/*
	if(images.size() != 0) {
		std::cout << images.size() << std::endl;
		cv::imshow("1st", images[0]);
		cv::waitKey();
	}
	*/
	delete mnistReader;

}
