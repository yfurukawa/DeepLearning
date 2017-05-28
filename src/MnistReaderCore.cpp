/*!------------------------------------------------
@file       MnistReaderCore.h
@brief      MNISTデータの読み込みで共通する関数を提供する
@attention  なし
--------------------------------------------------*/

#include "./MnistReaderCore.h"

/*!------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する
@attention  なし
--------------------------------------------------*/
MnistReaderCore::MnistReaderCore() {
}

/*!------------------------------------------------
@brief      デフォルトデストラクタ
@note       クラスを破棄する
@attention  なし
--------------------------------------------------*/
MnistReaderCore::~MnistReaderCore() {
}

/*!------------------------------------------------
@brief      エンディアン変換
@note       MNISTデータは値がビックエンディアンで格納されているので<br>
            Intelプロセッサで処理する場合は、リトルエンディアンに<br>
              変換する必要がある
@param[in]  data  変換対象のデータ  [-] (-)
@return     変換された値
@attention  なし
--------------------------------------------------*/
int MnistReaderCore::reverseInt (int data) {
    unsigned char ch1(0x00), ch2(0x00), ch3(0x00), ch4(0x00);

    ch1 = data & 255;
    ch2 = (data >> 8) & 255;
    ch3 = (data >> 16) & 255;
    ch4 = (data >> 24) & 255;

    return((int) ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

/*!------------------------------------------------
@brief      MNISTラベルデータ読み込み
@note       引数で指定されたファイルからMNISTのラベルデータを<br>
              読み込む
@param[in]  filename  MNISTラベルデータファイル  [-] (-)
@param[in]  oneHotLabel ラベルをone-hot表現にする  [-] (-)
@return     MNISTラベルデータが格納されたコンテナ
@attention  ファイルが存在しない等のエラー処理は未実装
--------------------------------------------------*/
std::vector<float> MnistReaderCore::readMnistLabel(const std::string& filename, const bool& oneHotLabel) {
	std::ifstream file(filename.c_str(), std::ios::binary);
	int magic_number(0);
	int number_of_images(0);
	std::vector<float> vecl;

	if (file.is_open()) {
		file.read((char*) &magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		file.read((char*) &number_of_images,sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);

		for(int i = 0; i < number_of_images; ++i) {
			unsigned char temp(0);
			file.read((char*) &temp, sizeof(temp));
			vecl.push_back(static_cast<float>(temp));
		}
    }
	return vecl;
}
