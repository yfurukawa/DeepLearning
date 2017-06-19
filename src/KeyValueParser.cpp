#include <boost/spirit/include/qi.hpp>       // Parsing
#include <boost/fusion/adapted/std_pair.hpp> // Make std::pair a fusion vector
#include <sstream>
#include <iostream>

#include "KeyValueParser.h"

using namespace boost::spirit;

map<string, string> KeyValueParser::parseString(const string& inputString) {
	istringstream inputStream(inputString);
	map<string, string> valueMap;
	string in;
	while(getline(inputStream, in, '\n')){
		std::string::const_iterator first = in.begin();
		std::string::const_iterator last  = in.end();

		const bool result = qi::phrase_parse(first, last,
		*( *(qi::char_-"=") >> qi::lit("=") 
		>> *(qi::char_-"\n") >> -qi::lit("\n") ), ascii::space, valueMap);
		if(!result) {
			throw "Parse Error";
		}
	}
	return valueMap;
}
