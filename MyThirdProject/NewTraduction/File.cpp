#include "File.h"
#include<fstream>
#include"Path.h"
#include"Directory.h"

bool File::Exist(const std::string& _path)
{
    std::ifstream _stream = std::ifstream(_path);
    const bool _exist = _stream.good();
    _stream.close();
    return _exist;
}

FileStream* File::Create(const std::string& _path)
{
    const std::string& _directoryPath = Path::GetDirectoryPath(_path);
    if (!Directory::Exist(_directoryPath))
        Directory::Create(_directoryPath);

    return new FileStream(_path);

}
