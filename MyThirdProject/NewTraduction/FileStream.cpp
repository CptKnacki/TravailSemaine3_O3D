#include "FileStream.h"
#include "FileWriter.h"
#include "FileReader.h"

FileStream::FileStream(const std::string& _path)
{
	writer = new FileWriter(_path);
	reader = new FileReader(_path);
}

FileStream::FileStream(const FileStream& _copy)
{
	writer = _copy.writer;
	reader = _copy.reader;
}

void FileStream::Close() const
{
	writer->Close();
	reader->Close();
}

FileWriter* FileStream::Writer()
{
	return writer;
}

FileReader* FileStream::Reader()
{
	return reader;
}

bool FileStream::IsValid() const
{
	return writer->IsOpen() && reader->IsOpen();
}
