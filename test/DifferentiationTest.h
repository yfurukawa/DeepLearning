#ifndef DIFFERENTIATIONTEST_H_
#define DIFFERENTIATIONTEST_H_

#include <gtest/gtest.h>
#include "Differentiation.h"

class DifferentiationTest : public ::testing::Test {
protected:
	Differentiation* sut;
	void SetUp();
	void TearDown();

public:
	DifferentiationTest();
	virtual ~DifferentiationTest();

};

#endif
