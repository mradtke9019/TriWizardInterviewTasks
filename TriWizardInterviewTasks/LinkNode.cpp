#include "LinkNode.h"

template <typename T>
LinkNode<T>::LinkNode(T data) 
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

template <typename T>
LinkNode<T>::LinkNode()
{
	this->data = (T)nullptr;
	this->next = nullptr;
	this->prev = nullptr;
}
