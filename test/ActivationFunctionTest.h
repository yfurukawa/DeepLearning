#ifndef ACTIVATIONFUNCTIONTEST_H_
#define ACTIVATIONFUNCTIONTEST_H_

#include <gtest/gtest.h>
#include "ActivationFunction.h"

class ActivationFunctionTest : public ::testing::Test {
protected:
	ActivationFunction* sut;
	void SetUp();
	void TearDown();

public:
	ActivationFunctionTest();
	virtual ~ActivationFunctionTest();

};

#endif
