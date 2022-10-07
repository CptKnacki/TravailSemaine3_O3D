#pragma once
#include<iostream>


class Directory
{
// Attributes //
private:
	std::string name = "";
	std::string path = "";


// Constructor / Destructor //
public:
	Directory() = default;
	Directory(const std::string& _path);

// Methods / Operators //
public:

	std::string Name() { return name; }
	std::string Path() { return path; }

	static Directory* Create(const std::string& _path);
	static bool Exist(const std::string& _path);
	static bool Delete(const std::string& _path);
};

