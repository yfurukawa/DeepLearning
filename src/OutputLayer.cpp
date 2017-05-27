/*!------------------------------------------------
@file       OutputLayer.h
@brief      ニューラルネットワークの出力層の関数を提供する
@attention  なし
--------------------------------------------------*/

#include <iostream>
#include "./OutputLayer.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
OutputLayer::OutputLayer() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
OutputLayer::~OutputLayer() {
}

/*!------------------------------------------------
@brief      恒等関数
@note       入力をそのまま出力する
@param[in]  matrix  cv::Mat型の行列  [-] (-)
@return     matrix  cv::Mat型の行列  [-] (-)
@attention  なし
--------------------------------------------------*/
cv::Mat OutputLayer::identity(const cv::Mat& matrix) {
	return matrix;
}

/*!------------------------------------------------
@brief      ソフトマックス関数
@note       引数で与えられた行列の各要素に対し、<br>
              ソフトマックス関数を適用する
@param[in]  matrix  cv::Mat型の行列  [-] (-)
@return     引数と同じcv::Mat型の行列に格納された計算結果
@attention  マルチスレッドでの動作は未確認
--------------------------------------------------*/
cv::Mat OutputLayer::softmax(const cv::Mat& matrix) {
	cv::Mat tmpMatrix;
	cv::Mat resultMatrix;
	float maxValue(findMaxElementValue(matrix));

	cv::exp((matrix - maxValue), tmpMatrix);
	cv::divide(tmpMatrix, cv::sum(tmpMatrix), resultMatrix);

	return resultMatrix;
}

/*!------------------------------------------------
@brief      最大値検索
@note       引数で与えられた行列内の最大値を検索する
@param[in]  matrix  cv::Mat型の行列  [-] (-)
@return     検索された最大値
@attention  マルチスレッドでの動作は未確認
--------------------------------------------------*/
float OutputLayer::findMaxElementValue(const cv::Mat& matrix) {
	float maxValue(0.0);

	for(int row = 0; row < matrix.rows; ++row) {
	    for(int column = 0; column < matrix.cols; ++column) {
	        maxValue = (matrix.at<float>(row, column) > maxValue) ? matrix.at<float>(row, column) : maxValue;
	    }
	}
	return maxValue;
}
