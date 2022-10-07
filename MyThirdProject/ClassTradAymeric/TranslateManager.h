#pragma once
#include<string>
#include<map>

class Language; // Déclaration forward //

class TranslateManager
{
private:
	std::map<std::string, Language*> languages = std::map<std::string, Language*>();

public:
	TranslateManager();

public:
	void InitLanguages();
	Language* GetLanguage(const std::string& _languageName);
	Language* AddLanguage(const std::string& _languageName);
	std::string Getmessage(const std::string& _languageName, const std::string& _key);
};

