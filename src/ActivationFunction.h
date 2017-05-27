/*!------------------------------------------------
@file       ActivationFunction.h
@brief      活性化関数を提供する
@attention  なし
--------------------------------------------------*/

#ifndef ACTIVATIONFUNCTION_H_
#define ACTIVATIONFUNCTION_H_

// インクルードファイル ================================
#include <opencv2/core.hpp>

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      ActivationFunction.h
@brief      活性化関数を提供する
@note       活性化関数（ステップ関数、シグモイド関数）を<br>
              提供する。<br>
@attention  マルチスレッドでの動作は未確認
@see        なし
--------------------------------------------------*/
class ActivationFunction {
 public:
  //! Constructor
  ActivationFunction();
  //! Destructor
  virtual ~ActivationFunction();
  //! シグモイド関数
  cv::Mat sigmoid(const cv::Mat& matrix);
  //! ステップ関数
  cv::Mat step(const cv::Mat& matrix);

 protected:
 private:
};

#endif  // ACTIVATIONFUNCTION_H_
