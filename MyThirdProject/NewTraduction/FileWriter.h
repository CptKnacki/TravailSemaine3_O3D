#pragma once
#include<string>
#include<fstream>

class FileWriter
{
private:
	std::string path = "";
	std::ofstream stream = std::ofstream();

public:
	FileWriter() = default;
	FileWriter(const std::string& _path) { path = _path; stream = std::ofstream(_path, std::ofstream::out | std::ofstream::app); }
	FileWriter(const FileWriter& _copy) { path = _copy.path; stream = std::ofstream(_copy.path, std::ofstream::out | std::ofstream::app); }

public:
	bool IsOpen() const;
	void Write(const std::string& _value);
	void Clear();
	void Close();

};

