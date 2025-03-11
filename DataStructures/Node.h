#pragma once

template<typename T>
class Node
{
public:
public: Node(): prev(nullptr), next(nullptr)
	{
	}
public: Node(T _data, Node* _prev, Node* _next) 
	: data(_data), prev(_prev), next(_next)
	{

	}
public: Node(Node* _node)
	{
		data = _node->data;
		prev = _node->prev;
		next = _node->next;
	}
public: bool LinkPrevToNext()
	{
		if (prev != nullptr && next != nullptr)
		{
			prev->next = next;
			next->prev = prev;
			return true;
		}
		return false;
	}
public: ~Node()
	{
	}

	public: T data;
	public: Node* prev;
	public: Node* next;
};
