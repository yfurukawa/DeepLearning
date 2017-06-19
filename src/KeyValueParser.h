#ifndef KEYVALUEPARSER_H_
#define KEYVALUEPARSER_H_

#include <iostream>
#include <map>

using namespace std;

class KeyValueParser {
private:
public:
	KeyValueParser() {};
	virtual ~KeyValueParser() {};
	std::map<string, string> parseString(const string&);
};

#endif


