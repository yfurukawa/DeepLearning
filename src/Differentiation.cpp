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
Differentiation::Differentiation() {
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
	float h(1e-3);

	return (function_.function(x + h) - function_.function( x - h )) / (2 * h);
}
