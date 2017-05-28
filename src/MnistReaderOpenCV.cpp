/*!------------------------------------------------
@file       MnistReaderOpenCV.h
@brief      MNISTデータの画像データを読み込む
@attention  なし
--------------------------------------------------*/

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "./MnistReaderOpenCV.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistReaderOpenCV::MnistReaderOpenCV() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
MnistReaderOpenCV::~MnistReaderOpenCV() {
}

/*!------------------------------------------------
@brief      MNISTデータ読み込み
@note       引数で指定されたファイルからMNISTの画像データを<br>
              読み込む
@param[in]  filename   MNIST画像データファイル  [-] (-)
@param[in]  normalize  読み込んだMNIST画像データを正規化する  [-] (-)
@param[in]  flatten    MNIST画像データを1次元配列にする  [-] (-)
@return     MNIST画像データが格納されたコンテナ
@attention  ファイルが存在しない等のエラー処理は不完全
--------------------------------------------------*/
std::vector<cv::Mat> MnistReaderOpenCV::readMnist(const std::string& filename, const bool& normalize=true, const bool flatten=true) {
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in | std::ios::binary);
    if (file.is_open()) {
    	int magic_number(0);
    	int number_of_images(0);
    	int n_rows(0);
    	int n_cols(0);
    	int normalizeFactor(1);

    	normalizeFactor = normalize ? 255 : 1;

    	file.read((char*) &magic_number, sizeof(magic_number));
    	magic_number = readerCore.reverseInt(magic_number);
    	file.read((char*) &number_of_images,sizeof(number_of_images));
    	number_of_images = readerCore.reverseInt(number_of_images);
    	file.read((char*) &n_rows, sizeof(n_rows));
    	n_rows = readerCore.reverseInt(n_rows);
    	file.read((char*) &n_cols, sizeof(n_cols));
    	n_cols = readerCore.reverseInt(n_cols);

    	cv::Mat tp = cv::Mat::zeros(n_rows, n_cols, CV_32FC1);
    	cv::Mat tpFlatten;

    	for(int i = 0; i < number_of_images; ++i) {
    		//cv::Mat tp = cv::Mat::zeros(n_rows, n_cols, CV_32FC1);
    		for(int r = 0; r < n_rows; ++r) {
    			for(int c = 0; c < n_cols; ++c) {
    				unsigned char temp(0);
    				file.read((char*) &temp, sizeof(temp));
    				tp.at<float>(r, c) = static_cast<float>(temp) / normalizeFactor;
    			}
    		}
    		if(flatten) {
    			tpFlatten = tp.reshape(0, 1).clone();
    		}
    		else {
    			tpFlatten = tp.clone();
    		}
    		imageData_.push_back(tpFlatten);
    	}
    }
    else {
    	std::cout << "File can not open." << std::endl;
    }
    return imageData_;
}

/*!------------------------------------------------
@brief      MNISTラベルデータ読み込み
@note       MnistReaderCoreクラスの同メソッドへ処理を移譲する
@param[in]  filename  MNISTラベルデータファイル  [-] (-)
@return     MNISTラベルデータが格納されたコンテナ
@attention  ファイルが存在しない等のエラー処理は未実装
--------------------------------------------------*/
std::vector<double> MnistReaderOpenCV::readMnistLabel(const std::string& filename) {
	return readerCore.readMnistLabel(filename);
}
