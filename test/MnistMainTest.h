#ifndef MNISTMAINTEST_H_
#define MNISTMAINTEST_H_

#include <gtest/gtest.h>
#include "MnistMain.h"

class MnistMainTest : public ::testing::Test {
protected:
	MnistMain* sut;
	void SetUp();
	void TearDown();

public:
	MnistMainTest();
	virtual ~MnistMainTest();

};

#endif
