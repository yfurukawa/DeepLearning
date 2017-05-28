/*!------------------------------------------------
@file       MnistReaderVector.h
@brief      MNISTデータの画像データを読み込む
@attention  なし
--------------------------------------------------*/

#include "./MnistReaderVector.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistReaderVector::MnistReaderVector() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
MnistReaderVector::~MnistReaderVector() {
}

/*!------------------------------------------------
@brief      MNISTデータ読み込み
@note       引数で指定されたファイルからMNISTの画像データを<br>
              読み込む
@param[in]  filename  MNIST画像データファイル  [-] (-)
@return     MNIST画像データが格納されたコンテナ
@attention  ファイルが存在しない等のエラー処理は不完全
--------------------------------------------------*/
void MnistReaderVector::readMnist(const std::string& filename) {
    std::ifstream file (filename.c_str(), std::ios::binary);
    if (file.is_open()) {
    	int magic_number = 0;
    	int number_of_images = 0;
    	int n_rows = 0;
    	int n_cols = 0;

    	file.read((char*) &magic_number, sizeof(magic_number));
    	magic_number = readerCore.reverseInt(magic_number);
    	file.read((char*) &number_of_images,sizeof(number_of_images));
    	number_of_images = readerCore.reverseInt(number_of_images);
    	file.read((char*) &n_rows, sizeof(n_rows));
    	n_rows = readerCore.reverseInt(n_rows);
    	file.read((char*) &n_cols, sizeof(n_cols));
    	n_cols = readerCore.reverseInt(n_cols);

    	for(int i = 0; i < number_of_images; ++i) {
    		std::vector<double> tp;
    		for(int r = 0; r < n_rows; ++r) {
    			for(int c = 0; c < n_cols; ++c) {
    				unsigned char temp = 0;
    				file.read((char*) &temp, sizeof(temp));
    				tp.push_back((double)temp);
    			}
    		}
    		imageData_.push_back(tp);
    	}
    }
}

/*!------------------------------------------------
@brief      MNISTラベルデータ読み込み
@note       MnistReaderCoreクラスの同メソッドへ処理を移譲する
@param[in]  filename  MNISTラベルデータファイル  [-] (-)
@param[in]  oneHotLabel ラベルをone-hot表現にする  [-] (-)
@return     MNISTラベルデータが格納されたコンテナ
@attention  ファイルが存在しない等のエラー処理は未実装
--------------------------------------------------*/
std::vector<double> MnistReaderVector::readMnistLabel(const std::string& filename, const bool& oneHotLabel) {
	return readerCore.readMnistLabel(filename, oneHotLabel);
}
