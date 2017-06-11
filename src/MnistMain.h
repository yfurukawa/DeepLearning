/*!------------------------------------------------
@file       MnistMain.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef MNISTMAIN_H_
#define MNISTMAIN_H_

// インクルードファイル ================================
#include <string>

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
  MnistMain();
  int argc_;
  char** argv_;
};

#endif  // MNISTMAIN_H_
