#include "StepFunctionTest.h"

StepFunctionTest::StepFunctionTest() : sut(NULL) {

}

StepFunctionTest::~StepFunctionTest() {

}

void StepFunctionTest::SetUp() {
	sut = new StepFunction();
}

void StepFunctionTest::TearDown() {
	delete sut;
}

TEST_F (StepFunctionTest, testCalc_lessThanZero) {
	ASSERT_EQ(0.0, sut->calc(-1));
}

TEST_F (StepFunctionTest, testCalc_EqualZero) {
	ASSERT_EQ(0.0, sut->calc(0.0));
}

TEST_F (StepFunctionTest, testCalc_graterThanZero) {
	ASSERT_EQ(1.0, sut->calc(0.1));
}
