/*!------------------------------------------------
@file       ConfigDataHolder.h
@brief      
@attention  なし
--------------------------------------------------*/

#include <cstdlib>
#include "ConfigDataHolder.h"
#include "FileDAO.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
ConfigDataHolder::ConfigDataHolder() : configFileName_("NeuralNetwork.conf"), hiddenLayer_(3), activeFunction_("sigmoid"),
	inputNode_(784), outputClass_(10), configFile_(NULL)
{
	prepareConfigurationData();
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
ConfigDataHolder::~ConfigDataHolder() {
}

/*!------------------------------------------------
@brief      
@note       
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out] 
@return     なし
@attention  なし
--------------------------------------------------*/
void ConfigDataHolder::setConfigFileName(const std::string& fileName) {
	configFileName_ = fileName;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
int ConfigDataHolder::getHiddenLayer() const {
	return hiddenLayer_;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
std::string ConfigDataHolder::getActiveFunction() const {
	return activeFunction_;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
int ConfigDataHolder::getInputNode() const {
	return inputNode_;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
int ConfigDataHolder::getOutputClass() const {
	return outputClass_;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
std::vector<int> ConfigDataHolder::getHiddenNode() const {
	  return hiddenNode_;
}

/*!------------------------------------------------
@brief
@note
@param[in]  パラメータ名  説明  [単位] (範囲)
@param[out]
@return     なし
@attention  なし
--------------------------------------------------*/
void ConfigDataHolder::prepareConfigurationData() {
	// TODO
	// confファイルの内容を読み込むようにする
	if(configFile_ == NULL) {
		configFile_ = new FileDAO();
	}

	if(configFile_->isExsist(configFileName_)){
		try {
			configFile_->openInputter(configFileName_);
		}
		catch(const std::ios::failure& e) {
			std::cout << e.what() << std::endl;
			exit(1);
		}
	}
}
