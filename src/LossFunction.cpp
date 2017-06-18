/*!------------------------------------------------
@file       LossFunction.h
@brief      
@attention  なし
--------------------------------------------------*/

#include <iostream>
#include "LossFunction.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
LossFunction::LossFunction() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
LossFunction::~LossFunction() {
}

/*!------------------------------------------------
@brief      2乗和誤差
@note       predictメソッドで得られた結果から2乗和誤差を産出する
@param[in]  predictedValue  学習の結果得られた行列  [-] (-)
@param[in]  oneHotLabel  one Hot表現された正解ラベル  [ｰ] (-)
@return     誤差の算出結果。値が大きいほど誤差大
@attention  なし
--------------------------------------------------*/
float LossFunction::meanSquaredError(cv::Mat predictedValue, cv::Mat oneHotLabel) {
	cv::Mat square;
	cv::pow(predictedValue - oneHotLabel, 2, square);

	return 0.5 * sum(square)[0];
}
