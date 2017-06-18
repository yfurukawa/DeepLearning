#include "DifferentiationTest.h"

DifferentiationTest::DifferentiationTest() {

}

DifferentiationTest::~DifferentiationTest() {

}

void DifferentiationTest::SetUp() {
	sut = new Differentiation();
}

void DifferentiationTest::TearDown() {
	delete sut;
}

TEST_F (DifferentiationTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
