#include "MnistReaderVectorTest.h"

MnistReaderVectorTest::MnistReaderVectorTest() {

}

MnistReaderVectorTest::~MnistReaderVectorTest() {

}

void MnistReaderVectorTest::SetUp() {
	sut = new MnistReaderVector();
}

void MnistReaderVectorTest::TearDown() {
	delete sut;
}

TEST_F (MnistReaderVectorTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
