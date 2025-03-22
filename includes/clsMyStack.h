#pragma once
#include "clsMyQueue.h"
#include <iostream>

using namespace std;


template <class T>
class  clsMyStack:public   clsMyQueue <T>
{

public :
	
	void push(T Item)
	{
		clsMyQueue <T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue <T>::front();
	}

	T Bottom()
	{
		return clsMyQueue <T>::back();
	}
	
};


/*
	This is an efficient way to implement a stack using inheritance while leveraging the existing queue structure. 
	Instead of creating a separate list, we reuse clsMyQueue and just tweak the behavior of push. 
	This demonstrates code reuse, modularity, and flexibility in OOP. 🚀



	Queue	Follows FIFO (First In, First Out)	   Elements are added at the back and removed from the front
	Stack	Follows LIFO (Last In, First Out)	   Elements are added and removed from the top

*/