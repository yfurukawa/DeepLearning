#ifndef THREELAYEREDNNTEST_H_
#define THREELAYEREDNNTEST_H_

#include <gtest/gtest.h>
#include "ThreeLayeredNN.h"

class ThreeLayeredNNTest : public ::testing::Test {
protected:
	ThreeLayeredNN* sut;
	void SetUp();
	void TearDown();

public:
	ThreeLayeredNNTest();
	virtual ~ThreeLayeredNNTest();

};

#endif
