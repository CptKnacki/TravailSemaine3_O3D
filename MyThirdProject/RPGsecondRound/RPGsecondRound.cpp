#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class Nods
{
private:
	int data = 1;
	Nods* next = nullptr;
public:
	Nods(int _i) { data = _i; }
	Nods(int _i, Nods* _ptrListe) { data = _i; next = _ptrListe; }
	void SetNods(Nods* _nods) { next = _nods; }
	void SetData(int _i) { data = _i; }
	Nods* GetNods() { return next; }
	int GetData() { return data; }
};

class Liste
{
private:
	int nodsNumber = 0;
	Nods* nods = nullptr;
public:

	Liste() {}

	void AddFirst(int _i)
	{
		if (nods == nullptr)
		{
			nods = new Nods(_i);
		}
		else
		{
			nods = new Nods(_i, nods);
		}

		nodsNumber++;
	}

	void AddLast(int _i)
	{
		if (nods == nullptr)
		{
			nods = new Nods(_i);

		}
		else
		{
			Nods* _tempNods = nods;

			while (_tempNods->GetNods())
			{
				_tempNods = _tempNods->GetNods();
			}

			Nods* _newNods = new Nods(_i, nullptr);

			_tempNods->SetNods(_newNods);
		}
		nodsNumber++;
	}

	void AddBefore(int _i)
	{
		if (nods == nullptr)
		{
			AddFirst(_i);
		}
		else
		{
			Nods* _tempNods = nods;

			while (_tempNods->GetNods()->GetNods())
			{
				_tempNods = _tempNods->GetNods();
			}

			Nods* _newNods = new Nods(_i, _tempNods->GetNods());

			_tempNods->SetNods(_newNods);

		}
		nodsNumber++;
	}

	void RemoveLast()
	{

		Nods* _tempNods = nods;

		while (_tempNods->GetNods()->GetNods())
		{
			_tempNods = _tempNods->GetNods();
		}
		_tempNods->SetNods(nullptr);
		nodsNumber--;
	}

	void RemoveFirst()
	{
		Nods* _headNods = nods;

		Nods* _tmpNods = nods;
		while (_tmpNods)
		{
			_tmpNods = _tmpNods->GetNods();
		}
	
	}

	void Clear()
	{
		Nods* _tempNods = nods;
		for (int i = 0; i < nodsNumber; i++)
		{
			Nods* _tempNods = nods;
			while (_tempNods->GetNods())
			{
				_tempNods = _tempNods->GetNods();
			}
			delete _tempNods;
			_tempNods->SetNods(nullptr);
		}
		nods->SetNods(nullptr);

		delete nods;
		nods = nullptr;

	//	nods->SetData(0);
	}

	bool Contains(int _containing)
	{
		Nods* _tempNods = nods;

		if (nods->GetData() == _containing)
			return true;
		else
		{
			for (int i = 0; i < nodsNumber; i++)
			{
				if (_tempNods->GetData() == _containing)
					return true;
				_tempNods = _tempNods->GetNods();
			}
		}
		return false;
	}

	void Display()
	{
		Nods* _tmpNods = nods;
		while (_tmpNods != nullptr)
		{

			std::cout << _tmpNods->GetData() << " ";
			_tmpNods = _tmpNods->GetNods();
		}
		std::cout << std::endl;
	}
};

int main()
{
	Liste list;
	list.AddLast(5);
	list.AddLast(6);
	list.AddLast(7);
	list.AddLast(9);

	list.AddFirst(4);
	list.AddBefore(8);

	list.Display();

	std::string result = (list.Contains(8)) ? "La chaine contient la data" : "Le chaine ne contient pas la data";

	std::cout << result << std::endl;

}

/*
	std::ifstream stream("C:\\Users\\DEMO1209\\source\\repos\\MyThirdProject\\RPGsecondRound\\level0.scene");
	if (!stream.is_open()) return -2;
	std::string _str = "";
	std::string _result = "";
	while(std::getline(stream, _str))
	{
		_result += _str + "\n";
	}

	std::vector<int> tab = std::vector<int>();
	tab.push_back(5);
	tab.emplace_back(10);
	int size = tab.size();
	tab.erase(tab.begin() + 5); // tab.end() - 5
	tab[0] = 5;


	std::cout << _result << std::endl;

*/