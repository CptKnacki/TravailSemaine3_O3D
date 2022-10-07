#pragma once
#include<string>
#include<vector>

class TranslateManager
{
private:
	std::vector<std::string> key; 
	std::vector<std::string> wordTab;

public:
	void Translate(std::vector<std::string> _key, std::string _translate);
};

