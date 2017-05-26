#include "MnistReaderCoreTest.h"

MnistReaderCoreTest::MnistReaderCoreTest() {

}

MnistReaderCoreTest::~MnistReaderCoreTest() {

}

void MnistReaderCoreTest::SetUp() {
	sut = new MnistReaderCore();
}

void MnistReaderCoreTest::TearDown() {
	delete sut;
}

TEST_F (MnistReaderCoreTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
