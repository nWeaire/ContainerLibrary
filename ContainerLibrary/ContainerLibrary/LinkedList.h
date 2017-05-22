#pragma once
#include "ListNode.h"
template <typename T>
class LinkedList
{
public:

	LinkedList() 
	{
		start = new ListNode<T>();
		end = new ListNode<T>();
		start->next = end;
		start->prev = nullptr;
		end->next = nullptr;
		end->prev = start;
	}
	
	~LinkedList() 
	{
		delete start;
		delete end;

	}




	
	ListNode<T>* start;
	ListNode<T>* end;

};

