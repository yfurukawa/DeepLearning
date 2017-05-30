/*!------------------------------------------------
@file       ConfigDataHolder.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef CONFIGDATAHOLDER_H_
#define CONFIGDATAHOLDER_H_

// インクルードファイル ================================

// クラスの前方宣言 ====================================

// マクロの宣言 ========================================

// 型の宣言 ============================================

// クラス定義 ==========================================
/*!--------------------------------------------------
@class       ConfigDataHolder.h
@brief      
@note       
@attention  なし
@see        なし
--------------------------------------------------*/
class ConfigDataHolder {
 public:
  //! Destructor
  virtual ~ConfigDataHolder();
  static ConfigDataHolder& getInstance(){
	  static ConfigDataHolder instance;
	  return instance;
  }

 protected:
 private:
  //! Constructor
  ConfigDataHolder();
  ConfigDataHolder(ConfigDataHolder const&);  // 実装しないこと
  void operator=(ConfigDataHolder const&);    // 実装しないこと
};

#endif  // CONFIGDATAHOLDER_H_
