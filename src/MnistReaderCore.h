/*!------------------------------------------------
@file       MnistReaderCore.h
@brief      MNISTデータの読み込みで共通する関数を提供する
@attention  なし
--------------------------------------------------*/

#ifndef MNISTREADERCORE_H_
#define MNISTREADERCORE_H_

// インクルードファイル ================================
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class      MnistReaderCore.h
@brief      MNISTデータの読み込みで共通する関数を提供する
@note       MNISTデータの読み込みの内、データを格納する変数の型に<br>
              依存しない処理を提供する
@attention  なし
@see        なし
--------------------------------------------------*/
class MnistReaderCore {
 public:
  //! Constructor
  MnistReaderCore();
  //! Destructor
  virtual ~MnistReaderCore();
  //! MNISTデータのラベルデータ読み込み
  std::vector<double> readMnistLabel(const std::string& filename, const bool& oneHotLabel);
  //! エンディアン変換
  int reverseInt (int data);

 protected:
 private:
};

#endif  // MNISTREADERCORE_H_
