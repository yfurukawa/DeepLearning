#ifndef KEYVALUEPARSERTEST_H_
#define KEYVALUEPARSERTEST_H_

#include <gtest/gtest.h>

class KeyValueParser;

using namespace std;

class KeyValueParserTest : public ::testing::Test {
protected:
	KeyValueParser* sut;
public:
	KeyValueParserTest() : sut(NULL) {};
	virtual ~KeyValueParserTest() {};
	virtual void SetUp();
	virtual void TearDown();

};


#endif

