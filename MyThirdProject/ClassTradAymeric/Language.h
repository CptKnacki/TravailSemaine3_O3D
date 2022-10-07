#pragma once
#include<map>
#include<string>
#include<vector>

class FileStream;
class FileReader;

class Language
{
private:

	std::string languageName = "";
	std::string filePath = "";
	FileStream* stream = nullptr;
	std::map < std::string, std::string> allMessages = std::map<std::string,std::string>();

public:
	Language() = default;
	Language(const std::string& _languageName);
	~Language();

public:
	void InitMessages();
	std::string GetMessage(const std::string& _key) const;
};

