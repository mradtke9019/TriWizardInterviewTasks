#pragma once

template <typename T>
class LinkNode
{
public:
	LinkNode(T data);
	LinkNode();
	T data;
	LinkNode<T>* next;
	LinkNode<T>* prev;

private:
};
