/*!------------------------------------------------
@file       TargetFunction.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef TARGETFUNCTION_H_
#define TARGETFUNCTION_H_

// インクルードファイル ================================

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class       TargetFunction.h
@brief      
@note       
@attention  なし
@see        なし
--------------------------------------------------*/
class TargetFunction {
 public:
  //! Constructor
  TargetFunction();
  //! Destructor
  virtual ~TargetFunction();
  float function(float x);
 protected:
 private:
};

#endif  // TARGETFUNCTION_H_
