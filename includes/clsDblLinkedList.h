#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{

protected:
	int _Size = 0;

public:
	class Node
	{

	public:
		T value;
		Node *next;
		Node *prev;
	};

	Node *head = NULL;

	void InsertAtBeginning(T value)
	{

		Node *newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = newNode;
		}
		head = newNode;
		_Size++;
	}

	void PrintList()

	{
		Node *Current = head;

		while (Current != NULL)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";
	}

	Node *Find(T Value)
	{
		Node *Current = head;
		while (Current != NULL)
		{

			if (Current->value == Value)
				return Current;

			Current = Current->next;
		}

		return NULL;
	}

	void InsertAfter(Node *current, T value)
	{

		Node *newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		if (current->next != NULL)
		{
			current->next->prev = newNode;
		}
		current->next = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{


		Node *newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			Node *current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
		_Size++;
	}

	void DeleteNode(Node *&NodeToDelete)
	{

		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{


		if (head == NULL)
		{
			return;
		}
		Node *temp = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{

	

		if (head == NULL)
		{
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}

		Node *current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}

		Node *temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size)
			DeleteFirstNode();
	}

	void Reverse()
	{
		Node *current = head;
		Node *temp = nullptr;

		while (current)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp)
		{
			head = temp->prev;
		}
	}

	/*
		void Reverse()
	{
		if (!head || !head->next)
			return ;

		Node *prev = nullptr;
		Node *current = head;
		while (current)
		{
			Node *next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}

	*/

	Node *GetNode(int index)
	{
		if (index > _Size - 1 || index < 0)
			return nullptr;
		int i = 0;
		for (Node *cur = head; cur; cur = cur->next, i++)
		{
			if (i == index)
				return cur;
		}
		return nullptr;
	}

	T	GetItem(int index)
	{
		Node *ItemNode = GetNode(index);

		if (!ItemNode)
			return T(); // Return a default-constructed value of type T
		else
			return ItemNode->value;
	}

	bool UpdateItem(int index, T NewValue)
	{
		Node *UpdateNode = GetNode(index);

		if (UpdateNode)
		{
			UpdateNode->value = NewValue;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T Value)
	{
		Node *ItemNode = GetNode(Index);
		if (ItemNode)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		return false;
	}

};