/*!------------------------------------------------
@file       ConfigDataHolder.h
@brief      
@attention  なし
--------------------------------------------------*/

#ifndef CONFIGDATAHOLDER_H_
#define CONFIGDATAHOLDER_H_

// インクルードファイル ================================
#include <string>
#include <vector>

// クラスの前方宣言 ====================================
class IInputter;

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
  void setConfigFileName(const std::string& fileName);
  int getHiddenLayer() const;
  std::string getActiveFunction() const;
  int getInputNode() const;
  int getOutputClass() const;
  std::vector<int> getHiddenNode() const;

 protected:
 private:
  std::string configFileName_;  //!< configファイルのファイル名
  int hiddenLayer_;  //!< 隠れ層の層数
  std::string activeFunction_; //!< 隠れ層のアクティブ関数の種類（step : ステップ関数、sigmoid : シグモイド関数）
  int inputNode_;  //!< 入力層のユニット数
  int outputClass_;  //!< 出力層のクラス数
  std::vector<int> hiddenNode_; //!< 隠れ層の出力ノード数

  IInputter* configFile_;
  //! Constructor
  ConfigDataHolder();
  ConfigDataHolder(ConfigDataHolder const&);  // 実装しないこと
  void operator=(ConfigDataHolder const&);    // 実装しないこと
  void prepareConfigurationData();
};

#endif  // CONFIGDATAHOLDER_H_
