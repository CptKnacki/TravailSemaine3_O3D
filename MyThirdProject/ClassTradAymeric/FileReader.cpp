#include "FileReader.h"
#include <string>

bool FileReader::IsOpen() const
{
	return stream.is_open();
}

void FileReader::Close()
{
	if (!IsOpen()) return;
	stream.close();
}

std::vector<std::string> FileReader::GetAllLines()
{
	std::vector<std::string> _result = std::vector<std::string>();
	std::string _str = "";
	while (std::getline(stream, _str))
	{
		_result.push_back(_str);
	}
	return _result;
}
