#pragma once

template<typename T>
class Nods
{
private:
	T data = T();
	Nods* next = nullptr;
	Nods* previous = nullptr;

public:
	Nods() = default;
	Nods(const T& _data, Nods* _nextNods = nullptr, Nods* _prevNods = nullptr);

public:

	T GetData(); 
	Nods* GetNextNods(); 
	Nods* GetPreviousNods(); 

	void SetNextNods(Nods* _newNods);
	void SetPreviousNods(Nods* _newNods); 
	
	bool operator==(const T& _item);
	operator T();
};

template<typename T>
inline Nods<T>::Nods(const T& _data, Nods* _nextNods, Nods* _prevNods)
{
	data = _data;
	next = _nextNods;
	previous = _prevNods;
}

template<typename T>
T Nods<T>::GetData() 
{
	return data;
}

template<typename T>
Nods<T>* Nods<T>::GetNextNods() 
{
	return next;
}

template<typename T>
Nods<T>* Nods<T>::GetPreviousNods() 
{
	return previous;
}

template<typename T>
void Nods<T>::SetNextNods(Nods* _newNods)
{
	next = _newNods;
}

template<typename T>
void Nods<T>::SetPreviousNods(Nods* _newNods)
{
	previous = _newNods;
}

template<typename T>
bool Nods<T>::operator==(const T& _item)
{
	return data == _item;
}

template<typename T>
Nods<T>::operator T()
{
	return data;
}