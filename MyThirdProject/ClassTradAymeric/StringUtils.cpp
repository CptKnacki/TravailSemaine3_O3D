#include "StringUtils.h"
#include<algorithm>

void StringUtils::Replace(std::string& _str, const char& _old, const char& _newValue)
{
	std::ranges::replace(_str, _old, _newValue);
}

void StringUtils::Replace(std::string& _str, const std::string& _old, const std::string& _newValue)
{
	int _startPos = 0;
	while ((_startPos = _str.find(_old, _startPos)) != std::string::npos)
	{
		_str.replace(_startPos, _old.length(), _newValue);
		_startPos += _old.length();
	}
}
