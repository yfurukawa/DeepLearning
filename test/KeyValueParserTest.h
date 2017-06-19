#ifndef KEYVALUEPARSERTEST_H_
#define KEYVALUEPARSERTEST_H_

#include <gtest/gtest.h>

class keyValueParser;

using namespace std;

class keyValueParserTest : public ::testing::Test {
protected:
	keyValueParser* sut;
public:
	keyValueParserTest() : sut(NULL) {};
	virtual ~keyValueParserTest() {};
	virtual void SetUp();
	virtual void TearDown();

};


#endif

