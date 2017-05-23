#include <iostream>
#include "DynamicArray.h"
#include "Queue.h"
#include "Stack.h"
#include "ObjectPool.h"
#include "LinkedList.h"
#include "ResourceManager.h"


using namespace std;

void DynamicArrayTest() // Testing Dynamic array
{
//	DynamicArray<int> data(10);

	DynamicArray<int> myArray(3);

	cout << "Initial sizes" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;
	
	cout << "Adding initial values" << endl;
	myArray.pushBack(9);
	myArray.pushBack(8);
	myArray.pushBack(7);
	myArray.pushBack(6);
	myArray.pushBack(5);
	cout << endl;

	cout << "The new sizes are:" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;

	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	// Clears array
	myArray.Clear();

	myArray.pushFront(1);
	myArray.pushFront(2);
	myArray.pushFront(3);
	myArray.pushFront(4);
	myArray.pushFront(5);
	cout << endl;

	// Prints values
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}

	// Inserts a 4 in slot 1
	myArray.Insert(1, 4);
	cout << endl;

	myArray.Remove(5);

	// Prints values
	cout << "Values are" << endl;
	for (int i = 0; i < myArray.Size(); ++i)
	{
		cout << myArray[i] << endl;
	}
	cout << endl;

	// Clear
	myArray.Clear();
	// Shrink
	myArray.Shrink();
	cout << "Clears and Shrinks!" << endl << endl;
	cout << "The new sizes are:" << endl;
	cout << "Used " << myArray.Size() << endl;
	cout << "Capacity " << myArray.Capacity() << endl << endl;

	
}

void LinkedListTest()
{
	LinkedList<int>* l1;
	l1 = new LinkedList<int>;
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushFront(10);
	l1->PushBack(12);
	l1->IndexInsert(2, 11);
	//Print List
	l1->printList();

	// test remove
	l1->remove(10);
	cout << l1->First() << endl;
	// test removing from iterator
	l1->erase(1);
	cout << l1->First() << endl;
	// clears entire list
	l1->clear();
	// checks if empty
	if (l1->empty() != 0)
		cout << "This list is empty!" << endl;
	else
		cout << "This list has something in it!" << endl;
	// Add to front and back of list
	l1->PushFront(3);
	l1->PushFront(2);
	l1->PushFront(1);
	l1->PushBack(4);
	// pop from front
	cout << l1->popFront() << endl;
	cout << l1->popFront() << endl;
	// pop from back
	cout << l1->popBack() << endl;
	cout << l1->popBack() << endl;




	system("pause");
}

void ResourceManagerTest()
{
	// Declare in header
	// ResourceManager<aie::Texture>* m_pResourceMan; 

	// Create
	// m_pResourceMan = new ResourceManager<Texture>()
	
	// Delete
	// delete m_pResourceMan

	//m_shipTexure = m_pResourceMan->LoadResource(Texture location);
	//Texture* Ship2 = m_pResourceMan->LoadResource(Texture location);



	//singleton 
	//ResourceManager<Texture>::Create();
	//m_pResourceMan = ResourceManager<Texture>::GetInstance();

}

void QueueTest()
{
	Queue<int> q1;

	//Create inital queue values
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);

	//Print values
	q1.printList();

	// Clear Queue
	q1.clear();

	// Check if empty
	if (q1.empty() != 0)
		cout << "List is empty" << endl;
	else
		cout << "List is not empty" << endl;

	q1.Push(1);
	q1.Push(2);
	q1.Push(3);

	//Popping values off
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;

	cout << q1.size() << endl;
	
	system("pause");
}

void main()
{
	//ObjectPool pool(50);

	//Entity* p = pool.Allocate();

	//pool.Deallocate(p);

	//DynamicArrayTest();
	//QueueTest();
	//LinkedListTest();
	//ResourceManagerTest();
	QueueTest();

}
