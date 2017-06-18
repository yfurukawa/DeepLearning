/*!------------------------------------------------
@file       LossFunction.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef LOSSFUNCTION_H_
#define LOSSFUNCTION_H_

// インクルードファイル ================================
#include <opencv2/core.hpp>

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      LossFunction.h
@brief      損失関数
@note       
@attention  なし
@see        なし
--------------------------------------------------*/
class LossFunction {
 public:
  //! Constructor
  LossFunction();
  //! Destructor
  virtual ~LossFunction();
  float meanSquaredError(cv::Mat predictedValue, cv::Mat oneHotLabel);

 protected:
 private:
};

#endif  // LOSSFUNCTION_H_
