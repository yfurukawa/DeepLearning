/*!------------------------------------------------
@file       Differentiation.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef DIFFERENTIATION_H_
#define DIFFERENTIATION_H_

// インクルードファイル ================================
#include <opencv2/core.hpp>
#include "TargetFunction.h"

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class       Differentiation.h
@brief      
@note       
@attention  なし
@see        なし
--------------------------------------------------*/
class Differentiation {
 public:
  //! Constructor
  Differentiation();
  //! Destructor
  virtual ~Differentiation();
  float numericalDiff(float x);
  cv::Mat numericalDiff(cv::Mat x);
 protected:
 private:
  TargetFunction function_;
  float h_;
};

#endif  // DIFFERENTIATION_H_
