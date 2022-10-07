#include <iostream>
#include <map>
#include "Environment.h"
#include "Utils.h"
#include "StringUtils.h"
#include "Path.h"
#include "Directory.h"
#include "File.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileStream.h"
#include "Language.h"
#include "TranslateManager.h"

int main()
{
	/*
		std::cout << Environment::CurrentDirectory();

		std::string _path = "C:\\Test";
		Utils::Log(_path);

		std::string _path = "C:\\Test";
		std::string _path1 = "C:\\Traduction";
		std::string _fullPath = Path::Combine(_path, _path1);
		Utils::Log(_fullPath);

		if (Directory::Exist(Environment::CurrentDirectory()))
			Utils::Log("exist !");

		Directory::Create(Path::GetPath("C:\\Test"));

		if (!Directory::Exist("C:\\Test"))
			Utils::Log("test doesnt exist !");
		else Utils::Log("exist !");

		if (Directory::Delete("C:\\Test"))
			Utils::Log("test deleted !");

	Directory d = Directory(Environment::CurrentDirectory());

	FileReader file1 = FileReader("C:\\Users\\DEMO1209\\source\\repos\\MyThirdProject\\Text.txt");
	std::vector<std::string> _allLines = file1.GetAllLines();

	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]);
	file1.Close();

	FileWriter file = FileWriter("C:\\Users\\DEMO1209\\source\\repos\\MyThirdProject\\Text.txt");

		file.Write("Gabriel");
		file.Write("Benoit");
		file.Write("Aymeric");

	FileStream* _stream = File::Create("C:\\Users\\DEMO1209\\source\\repos\\MyThirdProject\\Text.txt");
	_stream->Writer()->Write("Ouioui");


	std::vector<std::string> _allLines = _stream->Reader()->GetAllLines();

	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]);

	_stream->Close();

	*/
	setlocale(LC_ALL, "");
	//TranslateManager manager = TranslateManager();

	//    Utils::Log(manager.Getmessage("fr", "hello"));
	//    Utils::Log(manager.Getmessage("en", "hello"));
	std::string _str = "Salut comment vas tu ?";
	StringUtils::Replace(_str, " ", "");
	Utils::Log(_str);

}
