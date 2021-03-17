#pragma once
#include "LinkNode.h"
#include <string>

template <typename T>
class DoubleLinkList
{
public:
	DoubleLinkList();
	DoubleLinkList(T data);
	LinkNode<T>* Head;
	void Insert(T data, int index = 0);
	void InsertBeginning(T data);
	void Add(T data);
	void RemoveByIndex(int index);
	void RemoveByData(T data);
	void RemoveAllByData(T data);
	LinkNode<T>* FindByData(T data, int occurrence = 1);
	LinkNode<T>* FindByIndex(int index);
	void Clear();
	int Count();
	std::string ToString();
private:
	int count;
};

