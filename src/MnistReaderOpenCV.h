/*!------------------------------------------------
@file       MnistReaderOpenCV.h
@brief      MNISTデータの画像データを読み込む
@attention  なし
--------------------------------------------------*/

#ifndef MNISTREADEROPENCV_H_
#define MNISTREADEROPENCV_H_

// インクルードファイル ================================
#include <vector>
#include <opencv2/core.hpp>
#include "MnistReaderCore.h"

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      MnistReaderOpenCV.h
@brief      MNISTデータの画像データを読み込む
@note       MNISTデータの画像データを読み込み、その結果を<br>
            OpenCVのcv::Mat型で保持する
@attention  なし
@see        なし
--------------------------------------------------*/
class MnistReaderOpenCV {
 public:
  //! Constructor
  MnistReaderOpenCV();
  //! Destructor
  virtual ~MnistReaderOpenCV();
  //! MNISTデータ読み込み
  cv::Mat readMnist(const std::string& filename, const bool& normalize, const bool& flatten);
  //! MnisiReaderCoreへのデリゲータ
  cv::Mat readMnistLabel(const std::string& filename, const bool& oneHotLabel);

 protected:
 private:
  std::vector<cv::Mat> imageData_; //!< 読み込んだ画像データを保持するコンテナ  FIXME コンテナに入れるのではなく、cv::Matに入れるように修正する
  cv::Mat image_;  //!< 読み込んだ画像データ
  MnistReaderCore readerCore;      //!< ラベルを読み込むための共通インスタンス
  void covertVector2Mat(const std::vector<float>& tempLabel, cv::Mat* label);
  void covertVector2Mat(const std::vector<float>& tempLabel, const int& columns, cv::Mat* label);
  cv::Mat readMnistFalatten(const std::string& filename, const bool& normalize);
  cv::Mat readMnistMatrix(const std::string& filename, const bool& normalize);

};

#endif  // MNISTREADEROPENCV_H_
