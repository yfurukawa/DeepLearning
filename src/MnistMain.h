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
  cv::Mat labels_;
  cv::Mat images_;
  bool oneHotLabel_;
  bool normalize_;
  bool flatten_;
  std::map<std::string, cv::Mat > network;
  int accuracyCount_;
  ActivationFunction activeFunction_;
  OutputLayer outputLayer_;
  MnistMain();
  void initialize();
  void establishNetwork();
  void predict(int row);
};

#endif  // MNISTMAIN_H_
