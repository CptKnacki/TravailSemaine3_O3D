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
		if (theString[i] == 'A' || theString[i] == 'B' || theString[i] == 'C' || theString[i] == 'D' || theString[i] == 'E' || theString[i] == 'F' || theString[i] == 'G' || theString[i] == 'H' || theString[i] == 'I' || theString[i] == 'J' || theString[i] == 'K' || theString[i] == 'L' || theString[i] == 'M' || theString[i] == 'N' || theString[i] == 'O' || theString[i] == 'P' || theString[i] == 'Q' || theString[i] == 'R' || theString[i] == 'S' || theString[i] == 'T' || theString[i] == 'U' || theString[i] == 'V' || theString[i] == 'W' || theString[i] == 'X' || theString[i] == 'Y' || theString[i] == 'Z')
		{
			newString += '-'; // Si majuscule isupper()
		}
		else if (theString[i] == 'a' || theString[i] == 'b' || theString[i] == 'c' || theString[i] == 'd' || theString[i] == 'e' || theString[i] == 'f' || theString[i] == 'g' || theString[i] == 'h' || theString[i] == 'i' || theString[i] == 'j' || theString[i] == 'k' || theString[i] == 'l' || theString[i] == 'm' || theString[i] == 'n' || theString[i] == 'o' || theString[i] == 'p' || theString[i] == 'q' || theString[i] == 'r' || theString[i] == 's' || theString[i] == 't' || theString[i] == 'u' || theString[i] == 'v' || theString[i] == 'w' || theString[i] == 'x' || theString[i] == 'y' || theString[i] == 'z')
		{
			newString += '_'; // Si minuscule islower()
		}
		else if (theString[i] == ' ')
		{
			newString += '*'; // Si espace isspace()
		}

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