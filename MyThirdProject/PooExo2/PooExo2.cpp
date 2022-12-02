// PooExo2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>



int main()
{
	std::string theString = "Hello World";
	// "-____*-____" //

	std::string newString = "";

	for (int i = 0; i < theString.length(); i++)
	{
		if (std::isupper(theString[i]))
			newString += '-'; // Si majuscule isupper()
		
		else if (std::islower(theString[i]))
			newString += '_'; // Si minuscule islower()
		
		else if (std::isspace(theString[i]))
			newString += '*'; // Si espace isspace()
		
	}

	std::cout << newString;
}

/*

std::vector<int> tab = std::vector<int>();
tab.push_back();
tab.emplace_back();
tab.size();
tab.erase(tab.begin() + 5); // tab.erase() + 5
tab[0] = 5;

*/