#include "FileWriter.h"


bool FileWriter::IsOpen() const
{
	return stream.is_open();
}

void FileWriter::Write(const std::string& _value)
{
	if (!IsOpen()) return;
	stream << _value;
	stream << std::endl;
}


void FileWriter::Clear()
{
	Close();
	std::ofstream of = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);
	of.close();
}


void FileWriter::Close()
{
	if (!IsOpen()) return;
	stream.close();
}