#include "DoubleLinkList.h"
#include "LinkNode.h"
#include <stdexcept>
#include <iostream>

template <typename T>
DoubleLinkList<T>::DoubleLinkList()
{
	this->Head = nullptr; 
	count = 0;
}

template <typename T>
DoubleLinkList<T>::DoubleLinkList(T data)
{
	this->Head = new LinkNode<T>(data);
	count = 1;
}



/// <summary>
/// Insert data at index (default = 0)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data">The data to insert</param>
/// <param name="index">The index to place the data</param>
template <typename T>
void DoubleLinkList<T>::Insert(T data, int index)
{
	int count = Count();
	if (index > count || index < 0)
		throw std::out_of_range("Specified index out of range");
	// If position we want to add the data is at the end, just call add function
	if (index == count || count == 0)
	{
		return Add(data);
	}

	LinkNode<T>* curr = this->Head;
	LinkNode<T>* node = new LinkNode<T>(data);

	if (index == 0)
	{
		node->next = this->Head;
		this->Head->prev = node;
		this->Head = node;
		this->count++;
		return;
	}

	int i = 0;
	while (true)
	{
		if (i == index)
		{
			curr->prev->next = node;
			node->next = curr;
			node->prev = curr->prev;
			curr->prev = node;
			this->count++;
			return;
		}
		curr = curr->next;
		i++;
	}
}

/// <summary>
/// Specifically insert data into the beginning of the list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
template <typename T>
void DoubleLinkList<T>::InsertBeginning(T data)
{
	Insert(data, 0);
}

/// <summary>
/// Append data onto end of linked list
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data">The data to add</param>
template <typename T>
void DoubleLinkList<T>::Add(T data)
{
	LinkNode<T>* curr = this->Head;
	LinkNode<T>* node = new LinkNode<T>(data);
	// Empty list
	if (curr == nullptr)
	{
		this->Head = node;
		this->count++;
		return;
	}

	while (curr->next != nullptr)
	{
		curr = curr->next;
	}
	curr->next = node;
	node->prev = curr;
	this->count++;
}

/// <summary>
/// Returns nth node with the specified data.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data">The data to search for</param>
/// <param name="occurence">The occurence on which to return the node for. Defaults to the first occurence</param>
/// <returns></returns>
template <typename T>
LinkNode<T>* DoubleLinkList<T>::FindByData(T data, int occurence)
{
	if (Count() == 0)
		return nullptr;

	LinkNode<T>* curr = this->Head;
	int i = 0;
	while (curr != nullptr)
	{
		if (curr->data == data) 
		{
			i++;
			if (i == occurence)
				return curr;
		}
		curr = curr->next;
	}

	return nullptr;
}

/// <summary>
/// Returns nth node with the specified data.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data">The data to search for</param>
/// <param name="occurence">The occurence on which to return the node for. Defaults to the first occurence</param>
/// <returns></returns>
template <typename T>
LinkNode<T>* DoubleLinkList<T>::FindByIndex(int index)
{
	if (Count() == 0)
		return nullptr;
	if (index >= Count() || index < 0)
		throw std::out_of_range("Specified index out of range");

	LinkNode<T>* curr = this->Head;
	int i = 0;
	while (curr != nullptr)
	{
		if (i == index)
		{
			return curr;
		}
		curr = curr->next;
		i++;
	}

	return nullptr;
}

/// <summary>
/// Remove node at index
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
template <typename T>
void DoubleLinkList<T>::RemoveByIndex(int index)
{
	int count = Count();
	// Guarantee valid removal
	if (index > count || index < 0 || count == 0)
		throw std::out_of_range("Specified index out of range");

	LinkNode<T>* curr = this->Head;

	int i = 0;
	while (true)
	{
		if (i == index)
		{
			if (curr->next != nullptr)
				curr->next->prev = curr->prev;
			if (curr->prev != nullptr) 
				curr->prev->next = curr->next;
			if (curr == this->Head)
				this->Head = curr->next;

			delete curr;
			this->count--;
			return;
		}
		curr = curr->next;
		i++;
	}
}

template <typename T>
void DoubleLinkList<T>::RemoveByData(T data)
{
	LinkNode<T>* node = FindByData(data);
	if (node == nullptr)
		return;
	if (node->prev != nullptr)
		node->prev->next = node->next;
	if (node->next != nullptr)
		node->next->prev = node->prev;
	if (node == this->Head)
		this->Head = node->next;
	this->count--;
	delete node;
}


template <typename T>
void DoubleLinkList<T>::RemoveAllByData(T data)
{
	// Secondary remove all function not necessarily described in scope
	// Not very fast implementation for removal since we are restarting search over and over to remove.
	// Would refactor this method if we wanted it to work well
	LinkNode<T>* node = FindByData(data);
	while (node != nullptr)
	{
		if (node->prev != nullptr)
			node->prev->next = node->next;
		if (node->next != nullptr)
			node->next->prev = node->prev;
		if (node == this->Head)
			this->Head = node->next;
		this->count--;
		delete node;
		node = FindByData(data);
	}
}

template <typename T>
int DoubleLinkList<T>::Count()
{
	return this->count;
}

/// <summary>
/// Clear the linked list
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
void DoubleLinkList<T>::Clear()
{
	while (Count() > 0) 
	{
		RemoveByIndex(0);
	}
}

template <typename T>
std::string DoubleLinkList<T>::ToString()
{
	std::string str = "";
	LinkNode<T>* curr = this->Head;

	while (curr != nullptr)
	{
		str += std::to_string(curr->data) + "\n";
		curr = curr->next;
	}
	return str;
}