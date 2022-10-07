#pragma once
#include<iostream>
#include"FileStream.h"

class File
{
private:
	std::string path = "";

public:
	File() = default;
	File(const std::string& _path) { path = _path; }
	File(const File& _copy) { path = _copy.path; }

public:
	static bool Exist(const std::string& _path);
	static FileStream* Create(const std::string& _path);
};

