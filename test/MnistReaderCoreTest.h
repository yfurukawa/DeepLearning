#ifndef MNISTREADERCORETEST_H_
#define MNISTREADERCORETEST_H_

#include <gtest/gtest.h>
#include "MnistReaderCore.h"

class MnistReaderCoreTest : public ::testing::Test {
protected:
	MnistReaderCore* sut;
	void SetUp();
	void TearDown();

public:
	MnistReaderCoreTest();
	virtual ~MnistReaderCoreTest();

};

#endif
