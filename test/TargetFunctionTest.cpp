#include "TargetFunctionTest.h"

TargetFunctionTest::TargetFunctionTest() {

}

TargetFunctionTest::~TargetFunctionTest() {

}

void TargetFunctionTest::SetUp() {
	sut = new TargetFunction();
}

void TargetFunctionTest::TearDown() {
	delete sut;
}

TEST_F (TargetFunctionTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
