#ifndef TARGETFUNCTIONTEST_H_
#define TARGETFUNCTIONTEST_H_

#include <gtest/gtest.h>
#include "TargetFunction.h"

class TargetFunctionTest : public ::testing::Test {
protected:
	TargetFunction* sut;
	void SetUp();
	void TearDown();

public:
	TargetFunctionTest();
	virtual ~TargetFunctionTest();

};

#endif
