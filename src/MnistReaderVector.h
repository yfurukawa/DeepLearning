/*!------------------------------------------------
@file       MnistReaderVector.h
@brief      MNISTデータの画像データを読み込む
@attention  なし
--------------------------------------------------*/

#ifndef MNISTREADERVECTOR_H_
#define MNISTREADERVECTOR_H_

// インクルードファイル ================================
#include "MnistReaderCore.h"

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      MnistReaderOpenCV.h
@brief      MNISTデータの画像データを読み込む
@note       MNISTデータの画像データを読み込み、その結果を<br>
            vectorコンテナで保持する
@attention  なし
@see        なし
--------------------------------------------------*/
class MnistReaderVector {
 public:
  //! Constructor
  MnistReaderVector();
  //! Destructor
  virtual ~MnistReaderVector();
  //! MNISTデータ読み込み
  void readMnist(const std::string& filename);
  //! MnisiReaderCoreへのデリゲータ
  std::vector<float> readMnistLabel(const std::string& filename, const bool& oneHotLabel);

 protected:
 private:
  std::vector<std::vector<double> > imageData_;  //!< 読み込んだ画像データを保持するコンテナ
  MnistReaderCore readerCore;                    //!< ラベルを読み込むための共通インスタンス
};

#endif  // MNISTREADERVECTOR_H_
