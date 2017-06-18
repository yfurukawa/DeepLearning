#ifndef LOSSFUNCTIONTEST_H_
#define LOSSFUNCTIONTEST_H_

#include <gtest/gtest.h>
#include "LossFunction.h"

class LossFunctionTest : public ::testing::Test {
protected:
	LossFunction* sut;
	void SetUp();
	void TearDown();

public:
	LossFunctionTest();
	virtual ~LossFunctionTest();

};

#endif
