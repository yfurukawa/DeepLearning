#ifndef OUTPUTLAYERTEST_H_
#define OUTPUTLAYERTEST_H_

#include <gtest/gtest.h>
#include "OutputLayer.h"

class OutputLayerTest : public ::testing::Test {
protected:
	OutputLayer* sut;
	void SetUp();
	void TearDown();

public:
	OutputLayerTest();
	virtual ~OutputLayerTest();

};

#endif
