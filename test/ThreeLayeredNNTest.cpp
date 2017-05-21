#include "ThreeLayeredNNTest.h"

ThreeLayeredNNTest::ThreeLayeredNNTest() {

}

ThreeLayeredNNTest::~ThreeLayeredNNTest() {

}

void ThreeLayeredNNTest::SetUp() {
	sut = new ThreeLayeredNN();
}

void ThreeLayeredNNTest::TearDown() {
	delete sut;
}

TEST_F (ThreeLayeredNNTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
