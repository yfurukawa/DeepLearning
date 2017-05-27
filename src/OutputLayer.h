/*!------------------------------------------------
@file       OutputLayer.h
@brief      ニューラルネットワークの出力層の関数を提供する
@attention  なし
--------------------------------------------------*/
#ifndef OUTPUTLAYER_H_
#define OUTPUTLAYER_H_

// インクルードファイル ================================
#include <opencv2/core.hpp>

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      OutputLayer.h
@brief      ニューラルネットワークの出力層
@note       ニューラルネットワークの出力層で使用する<br>
              関数（恒等関数およびソフトマックス関数）を提供する<br>
              回帰問題では恒等関数を、分類問題ではソフトマックス関数を<br>
              使用するのが一般的
@attention  マルチスレッドでの動作は未確認
@see        なし
--------------------------------------------------*/
class OutputLayer {
 public:
  //! Constructor
  OutputLayer();
  //! Destructor
  virtual ~OutputLayer();
  //! 恒等関数
  cv::Mat identity(const cv::Mat& matrix);
  //! ソフトマックス関数
  cv::Mat softmax(const cv::Mat& matrix);

 protected:
 private:
  float findMaxElementValue(const cv::Mat& matrix);
};

#endif  // OUTPUTLAYER_H_
