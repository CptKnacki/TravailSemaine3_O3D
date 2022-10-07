#include "TranslateManager.h"
#include "Language.h"
#include "Environment.h"
#include "Path.h"
#include "Utils.h"
#include<filesystem>

TranslateManager::TranslateManager()
{
	InitLanguages();
}

void TranslateManager::InitLanguages()
{
	const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "LANGUAGE");
	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(_path.c_str()))
	{
		if (entry.is_directory()) continue;
		std::string _filePath = Path::GetPath(entry.path().string());
		std::string _filename = _filePath.substr(_filePath.find_last_of('/') + 1);
		_filename = _filename.substr(0, _filename.find_last_of('.'));
		languages.insert(std::pair(_filename, new Language(_filename)));
		Utils::Log(_filename);
	}
}

Language* TranslateManager::GetLanguage(const std::string& _languageName)
{
	if(!languages.contains(_languageName)) return nullptr;
	return languages[_languageName];
}

Language* TranslateManager::AddLanguage(const std::string& _languageName)
{
	if (languages.contains(_languageName)) return languages[_languageName];
	Language* _newlanguage = new Language(_languageName);
	languages.insert(std::pair(_languageName, _newlanguage));
	return _newlanguage;
}

std::string TranslateManager::Getmessage(const std::string& _languageName, const std::string& _key)
{
	Language* _language = GetLanguage(_languageName);
	if (_language == nullptr) return "";
	return _language->GetMessage(_key);
}
