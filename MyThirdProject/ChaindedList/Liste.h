#pragma once
#include"Nods.h"
#include <initializer_list>
#include <iostream>

template<typename T>
class Liste
{
private:
	Nods<T>* head = nullptr;
	Nods<T>* first = nullptr;
	Nods<T>* last = nullptr;
	int count = 0;

public:
	Liste() = default;
	Liste(const std::initializer_list<T>& _tab);
	~Liste();

public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Clear();
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	void AddBefore(const int& _index, const T& _item);
	void AddAfter(const int& _index, const T& _item);
	void Display();
	int GetCount();

	Nods<T>* Find(const T& _item);
};

template<typename T>
Liste<T>::Liste(const std::initializer_list<T>& _tab)
{
	for (const T& _item : _tab)
		Addlast(_item);
}

template<typename T>
Liste<T>::~Liste()
{
	Clear();
}

template<typename T>
void Liste<T>::AddFirst(const T& _item)
{
	Nods<T>* _newNods = new Nods<T>(_item);
	if (head == nullptr)
	{
		head = _newNods;
		first = _newNods;
		last = _newNods;
	}
	else
	{
		_newNods->SetNextNods(first);
		first->SetPreviousNods(_newNods);
		head = first = _newNods;
	}
	count++;
}

template<typename T>
void Liste<T>::AddLast(const T& _item)
{

	if (head == nullptr)
	{
		AddFirst(_item);
		return;
	}

	Nods<T>* _newNods = new Nods<T>(_item, nullptr, last);
	last->SetNextNods(_newNods);
	last = _newNods;

	count++;
}

template<typename T>
void Liste<T>::Clear()
{
	if (count == 0 || count == 1)
		delete head;
	
	delete[] head;

	last = nullptr;
	first = nullptr;
	head = nullptr;

	count = 0;
}

template<typename T>
void Liste<T>::RemoveFirst()
{
	const Nods<T>* _head = head;
	head = _head->GetNextNods();

	if(head != nullptr)
		head->previous = nullptr;
	delete _head;
	count--;
	if (count == 0)
		head = first = last = nullptr;
}

template<typename T>
void Liste<T>::RemoveLast()
{
	const Nods<T>* _last = last;
	last = _last->Prev();
	if(last != nullptr)
		last->SetNextNods(nullptr);
	delete _last;
	count--;
	if (count == 0)
		head = first = last = nullptr;
}

template<typename T>
bool Liste<T>::Contains(const T& _item)
{
	return Find(_item) != nullptr;
}

template<typename T>
void Liste<T>::Remove(const T& _item)
{
	if (first == _item)
	{	
		RemoveFirst();
			return;
	}
	if (last == _item)
	{
		RemoveLast();
		return;
	}

	const Nods<T>* _head = Find(_item);

	if (_head == nullptr) return;

	_head->GetPreviousNods()->SetNextNods(_head->GetnextNods());
	_head->GetnextNods()->SetPreviousNods(_head->GetPreviousNods());
	delete _head;
	count--;
}

template<typename T>
void Liste<T>::AddAfter(const int& _index, const T& _item)
{
	Nods<T>* _head = Find(_item);
	if (_head == nullptr) return;
	if (_head->GetNextNods() == nullptr)
	{
		AddLast(_item);
		return;
	}
	Nods<T>* _newNods = new Nods<T>(_item, _head->GetNextNods(), _head);
	_head->SetPreviousNods()->GetNextNods(_newNods);
	_head->SetNextNods(_newNods);
	count++;
}

template<typename T>
void Liste<T>::AddBefore(const int& _index, const T& _item)
{
	Nods<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->GetPreviousNods() == nullptr)
	{
		AddFirst(_item);
		return;
	}
	Nods<T>* _newNods = new Nods<T>(_item, _head, _head->GetPreviousNods());
	_head->GetPreviousNods()->SetnextNods(_newNods);
	_head->SetPreviousNods(_newNods);
	count++;
}

template<typename T>
Nods<T>* Liste<T>::Find(const T& _item)
{
	Nods<T>* _head = head;
	while (_head != nullptr)
		if (*_head == _item) return _head;
	return nullptr;
}

template<typename T>
void Liste<T>::Display()
{
	Nods<T>* _head = head;
	while (_head != nullptr)
	{
		std::cout << _head << ", ";
		_head = _head->GetNextNods();
	}
	std::cout << std::endl;

}

template<typename T>
int Liste<T>::GetCount()
{
	return count;
}