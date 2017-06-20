/*!------------------------------------------------
@file       MnistMain.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef MNISTMAIN_H_
#define MNISTMAIN_H_

// インクルードファイル ================================
#include <string>
#include <map>
#include <opencv2/core.hpp>
#include "ActivationFunction.h"
#include "OutputLayer.h"

// クラスの前方宣言 ====================================
class MnistReaderOpenCV;

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class       MnistMain.h
@brief      
@note       
@attention  なし
@see        なし
--------------------------------------------------*/
class MnistMain {
 public:
  //! Constructor
  MnistMain(int argc, char** argv);
  //! Destructor
  virtual ~MnistMain();
  int run();

 protected:
 private:
  int argc_;
  char** argv_;
  cv::Mat testLabels_;  //!< テスト画像ラベル
  cv::Mat testImages_;  //!< テスト画像
  cv::Mat trainingLabels_; //!< 訓練画像ラベル
  cv::Mat trainingImages_; //!< 訓練画像
  bool oneHotLabel_;  //!< ラベルの表記をone-Hot表現にする
  bool normalize_;    //!< 画像データを正規化する
  bool flatten_;      //!< 画像データを1次元配列に整形する
  std::map<std::string, cv::Mat > network;  //!< ニューラルネットワーク
  int accuracyCount_;  //!< テストの正解率
  ActivationFunction activeFunction_;
  OutputLayer outputLayer_;
  MnistMain();
  void initialize();
  void establishNetwork();
  void predict(int row);
  cv::Mat getMiniBatch(cv::Mat& wholeImages);
};

#endif  // MNISTMAIN_H_
