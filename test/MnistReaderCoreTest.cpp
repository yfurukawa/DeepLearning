#include "MnistReaderCoreTest.h"

MnistReaderCoreTest::MnistReaderCoreTest() : sut(NULL) {

}

MnistReaderCoreTest::~MnistReaderCoreTest() {

}

void MnistReaderCoreTest::SetUp() {
	sut = new MnistReaderCore();
}

void MnistReaderCoreTest::TearDown() {
	delete sut;
}

TEST_F (MnistReaderCoreTest, testReverseInt) {
	int expect(0x78563412);
	EXPECT_EQ(expect, sut->reverseInt(0x12345678));
}

TEST_F (MnistReaderCoreTest, testReadMnistLabel_notOneHotLabel) {
	int expect(7);
	std::vector<float> result;
	std::string filename = "../dataset/t10k-labels-idx1-ubyte";

	result = sut->readMnistLabel(filename);
	EXPECT_EQ(expect, result[0]);
}

