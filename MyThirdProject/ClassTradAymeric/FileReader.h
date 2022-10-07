#pragma once
#include<iostream>
#include<fstream>
#include<vector>

class FileReader
{
private:
	std::string path = "";
	std::ifstream stream = std::ifstream();

public:
	FileReader() = default;
	FileReader(const std::string& _path) { path = _path; stream = std::ifstream(_path); }
	FileReader(const FileReader& _copy) { path = _copy.path; stream = std::ifstream(_copy.path); }

public:
	bool IsOpen() const;
	void Close();
	std::vector<std::string> GetAllLines();
};

