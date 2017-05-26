#include "MnistReaderOpenCVTest.h"

MnistReaderOpenCVTest::MnistReaderOpenCVTest() {

}

MnistReaderOpenCVTest::~MnistReaderOpenCVTest() {

}

void MnistReaderOpenCVTest::SetUp() {
	sut = new MnistReaderOpenCV();
}

void MnistReaderOpenCVTest::TearDown() {
	delete sut;
}

TEST_F (MnistReaderOpenCVTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
