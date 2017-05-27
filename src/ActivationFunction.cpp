/*!------------------------------------------------
@file       Hogeh.h
@brief
@attention  なし
--------------------------------------------------*/

#include <iostream>
#include "./ActivationFunction.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
ActivationFunction::ActivationFunction() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
ActivationFunction::~ActivationFunction() {
}

/*!------------------------------------------------
@brief      シグモイド関数
@note       引数で与えられた行列の各要素に対し、<br>
              シグモイド関数を適用する
@param[in]  matrix  cv::Mat型の行列  [-] (-)
@return     引数と同じcv::Mat型の行列に格納された計算結果
@attention  マルチスレッドでの動作は未確認
--------------------------------------------------*/
cv::Mat ActivationFunction::sigmoid(const cv::Mat& matrix) {
	cv::Mat tmpMatrix;
	cv::exp(-1 * matrix, tmpMatrix);
	return 1/(1 + tmpMatrix);
}

/*!------------------------------------------------
@brief      ステップ関数
@note       引数で与えられた行列の各要素に対し、<br>
              ステップ関数を適用する
@param[in]  matrix  cv::Mat型の行列  [-] (-)
@return     引数と同じcv::Mat型の行列に格納された計算結果
@attention  マルチスレッドでの動作は未確認
--------------------------------------------------*/
cv::Mat ActivationFunction::step(const cv::Mat& matrix) {
	cv::Mat tmpMatrix = matrix.clone();
	for(int row = 0; row < matrix.rows; ++row) {
	    for(int column = 0; column < matrix.cols; ++column) {
	        tmpMatrix.at<float>(row ,column) = (matrix.at<float>(row, column) > 0) ? 1 : 0;
	    }
	}
	return tmpMatrix;
}
