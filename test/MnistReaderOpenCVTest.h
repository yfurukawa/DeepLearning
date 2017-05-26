#ifndef MNISTREADEROPENCVTEST_H_
#define MNISTREADEROPENCVTEST_H_

#include <gtest/gtest.h>
#include "MnistReaderOpenCV.h"

class MnistReaderOpenCVTest : public ::testing::Test {
protected:
	MnistReaderOpenCV* sut;
	void SetUp();
	void TearDown();

public:
	MnistReaderOpenCVTest();
	virtual ~MnistReaderOpenCVTest();

};

#endif
