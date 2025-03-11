#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
public:
	LinkedList() 
		: head(nullptr), tail(nullptr), length(0)
	{
	}

	~LinkedList()
	{
		Clear();
	}


	void AddStart(T _data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(_data, nullptr, nullptr);
			tail = head;
		}
		else
		{
			Node<T>* newNode = new Node<T>(_data, nullptr, head);
			head->prev = newNode;
			head = newNode;
		}
		length += 1;
	}
	void AddEnd(T _data)
	{
		if (tail == nullptr)
		{
			AddStart(_data);
		}
		else
		{
			Node<T>* newNode = new Node<T>(_data, tail, nullptr);
			tail->next = newNode;
			tail = newNode;
			length += 1;
		}
	}
	void AddAt(T _data, unsigned short _index)
	{
		if (_index == 0)
		{
			AddStart(_data);
		}
		else if (_index == length)
		{
			AddEnd(_data);
		}
		else if(_index < length)
		{
			Node<T>* node = head;
			for (unsigned short i = 0; i < _index - 1; i++)
			{
				node = node->next;
			}
			Node<T>* newNode = new Node<T>(_data, node, node->next);
			node->next = newNode;
			newNode->next->prev = newNode;
			length += 1;
		}
		else if (_index > length)
		{
			while (length != _index)
			{
				AddEnd(_data);				
			}
		}
	}
	void RemoveStart()
	{
		if (length > 1)
		{
			Node<T>* node = head;
			head = head->next;
			head->prev = nullptr;
			delete node;
			length -= 1;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			length = 0;
		}
	}
	void RemoveEnd()
	{
		if (length > 1)
		{
			Node<T>* node = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete node;
			length -= 1;
		}
		else
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			length = 0;
		}
	}
	void RemoveAt(unsigned short _index)
	{
		if (_index == 0)
		{
			RemoveStart();
		}
		else if (_index == length - 1)
		{
			RemoveEnd();
		}
		else if (_index < length)
		{
			Node<T>* node = head;
			for (unsigned short i = 0; i < _index; i++)
			{
				node = node->next;
			}
			node->LinkPrevToNext();
			delete node;
			length -= 1;
		}
	}
	void Clear()
	{
		while (length > 0)
		{
			RemoveEnd();
		}
	}

	T& GetAt(unsigned short _index)
	{
		if (_index >= length)
		{
			throw ("Invalid Index");
		}
		Node<T>* node = head;
		for (unsigned short i = 0; i < length; i++)
		{
			if (i == _index)
			{
				return node->data;
			}
			else
			{
				node = node->next;
			}
		}
	}
	bool Exist(T _data)
	{
		Node<T>* node = head;
		for (unsigned short i = 0; i < length; i++)
		{
			if (node->data == _data)
			{
				return true;
			}
			else
			{
				node = node->next;
			}
		}
		return false;
	}
	short IndexOf(T _data)
	{
		Node<T>* node = head;
		for (unsigned short i = 0; i < length; i++)
		{
			if (node->data == _data)
			{
				return i;
			}
			else
			{
				node = node->next;
			}
		}
		return -1;
	}
	
	void Count()
	{
		return length;
	}

private:
	Node<T>* head;
	Node<T>* tail;
	unsigned short length;
};
