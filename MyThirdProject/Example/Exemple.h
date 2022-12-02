#pragma once
#include <iostream>

class Exemple
{
private:
	std::string name = "Luigi";
	Exemple* next = nullptr;

public:
	// Constructor and Destructor //
	Exemple() = default;
	Exemple(const Exemple& _copy) { name = _copy.name; next = _copy.next; }
	~Exemple(){ delete next; next = nullptr; }

	// Operators //
	Exemple operator=(const Exemple& _other)
	{
		name = _other.name;
		next = _other.next;
		return *this;
	}
	bool operator==(const Exemple& _other)
	{
		return name == _other.name;
	}
	bool operator!=(const Exemple& _other)
	{
		return name != _other.name;
	}
	operator std::string()
	{
		return name;
	}
	operator bool()
	{
		return name == "Toto";
	}

	// Methods //
	void Test(){}
};

