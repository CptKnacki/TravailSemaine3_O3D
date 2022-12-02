#pragma region Dependencies

#include <string>
#include <iostream>

#pragma endregion

#pragma region Classes

class Nods
{
private:
	int data = 0;
	Nods* next = nullptr;
public:

	// Constructor of the nod class //
	Nods() = default;
	Nods(int _i, Nods* _ptrListe = nullptr) { data = _i; next = _ptrListe; }

	// Methods to access and set the attributes to a new value //
	void SetNods(Nods* _nods) { next = _nods; }
	void SetData(int _i) { data = _i; }

	// Methods to access and return the value of the attributes //
	Nods* GetNods() { return next; }
	int GetData() { return data; }
};

class Liste
{
private:
	int nodsNumber = 0;
	Nods* nods = nullptr;
public:

	// Default constructor of Liste //
	Liste() = default;

	
	Liste(std::initializer_list<Nods> _nodsList)
	{
		int _nodsNumber = 0;

		for (Nods _nods : _nodsList)
			_nodsNumber++;

		Nods* _temp = new Nods[_nodsNumber];

		_nodsNumber = 0;

		for (Nods _nods : _nodsList)
		{
			_temp[_nodsNumber] = _nods;
			_nodsNumber++;
		}

		nods = _temp;
	};
	

	// Method used to add at the first position //
	void AddFirst(int _i)
	{
		if (nods->GetNods() == nullptr)
			nods = new Nods(_i);
		else
			nods = new Nods(_i, nods);
		nodsNumber++;
	}

	// Method used to add a nod at the end of the nod row //
	void AddLast(int _i)
	{
		if (nods == nullptr)
			nods = new Nods(_i);
		else
		{
			Nods* _tempNods = nods;
			while (_tempNods->GetNods())
				_tempNods = _tempNods->GetNods();
			Nods* _newNods = new Nods(_i, nullptr);
			_tempNods->SetNods(_newNods);
		}
		nodsNumber++;
	}

	// Method used to add a nod behind the last one //
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

	// Method that delete the last nod of the row //
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

	// Method that delete the first nod //
	void RemoveFirst()
	{
		Nods* _tempNods = nods;
		nods = _tempNods->GetNods();
		
		delete _tempNods;
		_tempNods = nullptr;
	}

	// Method that delete all the nods existing //
	void Clear()
	{
		delete nods;
		nods->SetNods(nullptr);
	}

	// Method used to test if a certain data is hold by a nod in the row //
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

	// Method that display the entire chains of nods //
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

#pragma endregion

int main()
{
	// Liste list = Liste{  0,1,2,3,4,5,6,7,8,9 };

	Liste list; 

	list.AddLast(5);
	list.AddLast(6);
	list.AddLast(7);
	list.AddLast(9);
	list.AddFirst(4);
	list.AddBefore(8);
	list.AddFirst(3); 

	list.RemoveFirst();

	list.Display(); 

	std::string result = (list.Contains(8)) ? "La chaine contient la data" : "Le chaine ne contient pas la data";

	std::cout << result << std::endl;

}

/*
 
//------------------------------------------------------------------//

	#include <vector>
	#include <fstream>

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

//-----------------------------------------------------------//

	template<typename T>

	class List
	{
		private:
			T* tab = new T[0];
			int count = 0;
		public:
			List(std::initializer_list<T> _tab)
			{
				tab = new T[_tab.size()];
				count = _tab.Size();
				int index = 0;
				for (T _item : _tab)
				{
					tab[index++] = _item;
				}
			}

			void Display()
			{
				for(int i = 0; i< count; i++)
				{
					std::cout << tab[i] << " ";	
				}
		
			}
	};

	int main()
	{
		List<float> _list = { 0.56f, 5.2f, 15.4f, 35.32f};
		_list.Display();
	}

//-------------------------------------------------------------//

	// first / tree / last //


	List(std::initialize_list<int> _tab)
	{
		for(int _item : _tab)
		{
			AddLast(_item);
		}
	}


	void AddFirst() // first à la place de tree //
	{
		if (tree->next == nullptr)
			tree = new Nods(_i);
		else
			tree = new Nods(_i, tree);
		count++;
	
	}
	
	void AddLast(int _data) // last à la place de tree //
	{
		if(tree == nullptr)
		{
			AddFirst(_data);
			return;
		}
		Node* _tree = tree;
		while (_tree->next->next != nullptr)
			_tree = _tree->next
		_tree->next = new Node(_data);
	}

	void RemoveFirst()
	{
		Node* _tree = tree;
		tree = _tere->next;
		first = tree;
		delete _tree;
		count--;
	}

	void RemoveLast()
	{
		Node* _tree = tree;
		while(_tree->next !=nullptr)
			_tree = _tree->next;
		_tree = _tree->next;
		count--;
	}

	void Remove(int _item)
	{
		Node* _tree = tree;
		if(_tree == first)
		{
			RemoveFirst();
		}
		else if (_tree == last)
		{
			RemoveLast();
		}
		else
		{
			while(_tree != nullptr && _tree->data != _item)
			{
				_tree = _tree->next;
			}
			if (_tree == nullptr) return;
			_tree->-prev>next = _tree->next;
			_tree->-next>prev = _tree->prev;
			delete _tree;
			count--;
		}
	}

	void AddBefore(int _index, int _item)
	{
		Node* _tree = Find(_index);
		if(_tree == nullptr) return;
		if (_tree->prev == nullptr)
			{
				AddFirst(_item);
				return;
			}
		Node* _newNode = new Node(_item, _tree, _tree->prev);
		_tree->-prev->next = _newNode;
		_tree->-prev = _newNode;
		count++;
	}

	void AddAfter(int _index, int _item)
	{
		Node* _tree = tree;
		if(_tree == nullptr) return;
		if (_tree->next == nullptr)
			{
				AddLast(_item);
				return;
			}
		Node* _newNode = new Node(_item, _tree->next, _tree);
		_tree->next = _newNode;
		count++;
	}

	Node* Find(int _item)
	{
		Node* _tree = tree;
		while(_tree != nullptr && _tree->data != _item)
			_tree = _tree->next;
		return _tree;
	}

	int& operator[](int _index)
	{
		if(_index < 0 || _index > count)
			return _result;

		Node* _tree = tree;
		int _currentIndex = _index;

		while(_currentIndex > 0 && _tree != nullptr)
		{
			_currentIndex--;
			_tree = _tree->next;
		}
		if (_tree == nullptr) return _result;
			return _tree->data;
	}


*/


