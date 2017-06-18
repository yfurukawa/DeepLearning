/*!------------------------------------------------
@file       TargetFunction.h
@brief      
@attention  なし
--------------------------------------------------*/

#include <cmath>
#include "TargetFunction.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
TargetFunction::TargetFunction() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
TargetFunction::~TargetFunction() {
}

/*!------------------------------------------------
@brief      
@note       
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out] 
@return     なし
@attention  なし
--------------------------------------------------*/
float TargetFunction::function(float x) {
	return 0.01 * std::pow(x, 2) + 0.1 * x;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
float TargetFunction::function(cv::Mat x) {
	return std::pow(x.at<float>(0), 2.0) + std::pow(x.at<float>(1), 2.0);
}
