#ifndef CONFIGDATAHOLDERTEST_H_
#define CONFIGDATAHOLDERTEST_H_

#include <gtest/gtest.h>
#include "ConfigDataHolder.h"

class ConfigDataHolderTest : public ::testing::Test {
protected:
	//ConfigDataHolder* sut;
	void SetUp();
	void TearDown();

public:
	ConfigDataHolderTest();
	virtual ~ConfigDataHolderTest();

};

#endif
