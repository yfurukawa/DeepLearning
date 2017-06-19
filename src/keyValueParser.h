#ifndef KEYVALUEPARSER_H_
#define KEYVALUEPARSER_H_

#include <iostream>
#include <map>

using namespace std;

class keyValueParser {
private:
public:
	keyValueParser() {};
	virtual ~keyValueParser() {};
	std::map<string, string> parseString(const string&);
};

#endif


