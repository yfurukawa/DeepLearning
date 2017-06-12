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
MnistMain::MnistMain() : argc_(0), argv_(0x00), oneHotLabel_(true), normalize_(true), flatten_(true) {
}

/*!------------------------------------------------
@brief      コンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistMain::MnistMain(int argc, char** argv) : argc_(argc), argv_(argv), oneHotLabel_(true), normalize_(true), flatten_(true) {
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

	std::string filename = "../dataset/t10k-labels-idx1-ubyte";
	labels_ = mnistReader->readMnistLabel(filename, oneHotLabel_);
	/*
	std::cout << labels.size() << std::endl;
	std::cout << labels.at<float>(0) << std::endl;
	*/

	//read MNIST iamge into OpenCV Mat vector
	filename = "../dataset/t10k-images-idx3-ubyte";
	images_ = mnistReader->readMnist(filename, normalize_, flatten_);

	if(images_.rows != 0) {
		std::cout << images_.dims << std::endl;
		std::cout << images_.rows << std::endl;
		//cv::imshow("1st", images_.);
		cv::waitKey();
	}

	delete mnistReader;

}
