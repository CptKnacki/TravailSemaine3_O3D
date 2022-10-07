#include <iostream>
#include"Liste.h"
#include"Nods.h"

int main()
{
	Liste<std::string> liste1 = Liste<std::string>();
	liste1.AddLast("Hello");
	liste1.AddLast("World");

	liste1.Display();

	liste1.Clear();
}
