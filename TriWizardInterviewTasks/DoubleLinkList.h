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
	void Add(T data);
	void Remove(int index);
	LinkNode<T>* Find(T data, int occurrence = 1);
	void RemoveNode(T data);
	void Clear();
	int Count();
	std::string ToString();
private:
	int count;
};

