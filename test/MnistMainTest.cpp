#include "MnistMainTest.h"

MnistMainTest::MnistMainTest() : sut(NULL) {

}

MnistMainTest::~MnistMainTest() {

}

void MnistMainTest::SetUp() {
	char* argv[] = {""};
	sut = new MnistMain(1, argv);
}

void MnistMainTest::TearDown() {
	delete sut;
}

TEST_F (MnistMainTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
