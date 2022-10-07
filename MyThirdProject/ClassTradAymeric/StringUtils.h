#pragma once
#include<iostream>

class StringUtils
{
public:
	static void Replace(std::string& _str, const char& _old, const char& _newValue);
	static void Replace(std::string& _str, const std::string& _old, const std::string& _newValue);
};

