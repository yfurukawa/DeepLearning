/*!------------------------------------------------
@file       Differentiation.h
@brief      
@attention  なし
--------------------------------------------------*/

#include "Differentiation.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
Differentiation::Differentiation() : h_(1e-3) {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
Differentiation::~Differentiation() {
}

/*!------------------------------------------------
@brief      
@note       
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out] 
@return     なし
@attention  なし
--------------------------------------------------*/
float Differentiation::numericalDiff(float x) {
	return (function_.function( x + h_ ) - function_.function( x - h_ )) / ( 2 * h_ );
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
cv::Mat Differentiation::numericalDiff(cv::Mat x) {
	cv::Mat backup(x.clone());
	cv::Mat gradient = cv::Mat::zeros(x.rows, x.cols, 0);
	float fxh1(0.0), fxh2(0.0), tempValue(0.0);

	for(int col = 0; col < x.cols; ++col) {
		tempValue = x.at<float>(0, col);
		x.at<float>(0, col) = tempValue + h_;
		fxh1 = function_.function(x);

		x.at<float>(0, col) = tempValue - h_;
		fxh2 = function_.function(x);

		gradient.at<float>(0, col) = (fxh1 - fxh2) / (2 * h_);
		x.at<float>(0, col) = tempValue;
	}

	return gradient;
}
