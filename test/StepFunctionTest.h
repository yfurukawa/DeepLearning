#ifndef STEPFUNCTIONTEST_H_
#define STEPFUNCTIONTEST_H_

#include <gtest/gtest.h>
#include "StepFunction.h"

class StepFunctionTest : public ::testing::Test {
protected:
	StepFunction* sut;
	void SetUp();
	void TearDown();

public:
	StepFunctionTest();
	virtual ~StepFunctionTest();

};

#endif
