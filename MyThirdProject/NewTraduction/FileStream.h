#pragma once
#include<string>
#include<fstream>

class FileWriter;
class FileReader;


class FileStream
{
private:
	FileWriter* writer = nullptr;
	FileReader* reader = nullptr;

public:
	FileStream() = default;
	FileStream(const std::string& _path);
	FileStream(const FileStream& _copy);

public:
	void Close() const;
	FileWriter* Writer();
	FileReader* Reader();
	bool IsValid() const;
};

