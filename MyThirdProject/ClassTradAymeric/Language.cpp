#include "Language.h"
#include "FileStream.h"
#include "FileReader.h"
#include "Path.h"
#include "File.h"
#include "Environment.h"

Language::Language(const std::string& _languageName)
{
	languageName = _languageName;
	filePath = Path::Combine(Environment::CurrentDirectory(), "Language", _languageName + ".txt");
	stream = File::Create(filePath);
	InitMessages();
}

Language::~Language()
{
	stream->Close();
	delete stream;
	stream = nullptr;
}

void Language::InitMessages()
{
	if (!stream->IsValid()) return;
	const std::vector<std::string> _allLines = stream->Reader()->GetAllLines();
	for (int i = 0; i < _allLines.size(); i++)
	{
		const std::string _line = _allLines[i];
		std::string _key = _line.substr(0, _line.find_first_of(':'));
		if (allMessages.contains(_key)) continue; // retour au début si sontinue //
		std::string _message = _line.substr(_line.find_first_of(':') + 1);
		allMessages.insert(std::pair(_key, _message));
	}

}

std::string Language::GetMessage(const std::string& _key) const
{
	if (!allMessages.contains(_key)) return "";
	return allMessages.at(_key);
}
