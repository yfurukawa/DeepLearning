/*
 * Copyright
 *
*/
#include "./MnistReaderCore.h"

MnistReaderCore::MnistReaderCore() {
}

MnistReaderCore::~MnistReaderCore() {
}

int MnistReaderCore::reverseInt (int i) {
    unsigned char ch1, ch2, ch3, ch4;

    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;

    return((int) ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

std::vector<double> MnistReaderCore::readMnistLabel(const std::string& filename) {
	std::ifstream file(filename.c_str(), std::ios::binary);
	int magic_number = 0;
	int number_of_images = 0;
	int n_rows = 0;
	int n_cols = 0;
	std::vector<double> vecl(number_of_images);

	if (file.is_open()) {
		file.read((char*) &magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		file.read((char*) &number_of_images,sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);

		for(int i = 0; i < number_of_images; ++i) {
			unsigned char temp = 0;
			file.read((char*) &temp, sizeof(temp));
			//vecl[i]= (double)temp;
			vecl.push_back((double)temp);
		}
    }
	return vecl;
}
