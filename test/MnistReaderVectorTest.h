#ifndef MNISTREADERVECTORTEST_H_
#define MNISTREADERVECTORTEST_H_

#include <gtest/gtest.h>
#include "MnistReaderVector.h"

class MnistReaderVectorTest : public ::testing::Test {
protected:
	MnistReaderVector* sut;
	void SetUp();
	void TearDown();

public:
	MnistReaderVectorTest();
	virtual ~MnistReaderVectorTest();

};

#endif
