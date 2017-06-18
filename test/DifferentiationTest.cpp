#include "DifferentiationTest.h"

DifferentiationTest::DifferentiationTest() : sut(NULL) {

}

DifferentiationTest::~DifferentiationTest() {

}

void DifferentiationTest::SetUp() {
	sut = new Differentiation();
}

void DifferentiationTest::TearDown() {
	delete sut;
}

TEST_F (DifferentiationTest, testNumericalDiff_value5) {
	float expect(0.2);

	EXPECT_NEAR(expect, sut->numericalDiff(5.0), 0.001);
}

TEST_F (DifferentiationTest, testNumericalDiff_value10) {
	float expect(0.3);

	EXPECT_NEAR(expect, sut->numericalDiff(10.0), 0.001);
}
