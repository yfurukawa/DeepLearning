#include <iostream>
#include <map>
#include <gtest/gtest.h>
#include "keyValueParser.h"
#include "keyValueParserTest.h"

void keyValueParserTest::SetUp() {
	sut = new keyValueParser();
}

void keyValueParserTest::TearDown() {
	delete sut;
	sut = NULL;
}

TEST_F(keyValueParserTest, numberOfPairIsOne) {
	map<string, string> actualMap;
	string inputString("dummyKey=value");
	actualMap = sut->parseString(inputString);
	EXPECT_EQ(1, actualMap.size());
}

TEST_F(keyValueParserTest, dummyKeyPairIsCorrect) {
	map<string, string> actualMap;
	string inputString("dummyKey=value");
	actualMap = sut->parseString(inputString);

	EXPECT_EQ("dummyKey", (*actualMap.begin()).first);
	EXPECT_EQ("value", (*actualMap.begin()).second);
}

TEST_F(keyValueParserTest, dummyKey2PairIsCorrect) {
	map<string, string> actualMap;
	string inputString("dummyKey2=value2");
	actualMap = sut->parseString(inputString);

	EXPECT_EQ("dummyKey2", (*actualMap.begin()).first);
	EXPECT_EQ("value2", (*actualMap.begin()).second);
}

TEST_F(keyValueParserTest, dummyKeyPairsAreCorrect) {
	map<string, string> actualMap;
	string inputString("dummyKey=value\n dummyKey2 = value2");
	actualMap = sut->parseString(inputString);

	EXPECT_EQ(2, actualMap.size());
	map<string, string>::iterator it;
	it = actualMap.begin();
	EXPECT_EQ("dummyKey", (*it).first);
	EXPECT_EQ("value", (*it++).second);
	EXPECT_EQ("dummyKey2", (*it).first);
	EXPECT_EQ("value2", (*it).second);
}

