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

void QueueTest()
{
	cout << "Queue test" << endl << endl << endl;
	Queue<int> myQueue(1);
	cout << "Initial sizes" << endl;
	cout << "Used " << myQueue.size() << endl;
	cout << "Capacity " << myQueue.capacity() << endl << endl;

	cout << "Adding initial values" << endl;
	myQueue.push(9);
	myQueue.push(8);
	myQueue.push(7);
	myQueue.push(6);
	myQueue.push(5);
	cout << endl;

	cout << "New values are" << endl;
	for (int i = 0; i < myQueue.size(); ++i)
	{
		cout << myQueue[i] << endl;
	}

	cout << "New sizes" << endl;
	cout << "Used " << myQueue.size() << endl;
	cout << "Capacity " << myQueue.capacity() << endl << endl;

	cout << "poping off top 3 values" << endl;
	cout << myQueue.pop() << endl;
	cout << myQueue.pop() << endl;
	cout << myQueue.pop() << endl;

	cout << endl;

	cout << "New values are" << endl;
	for (int i = 0; i < myQueue.size(); ++i)
	{
		cout << myQueue[i] << endl;
	}

	cout << endl;

	cout << "Clearing" << endl << endl;
	myQueue.clear();
	cout << "Is the queue now empty? " << endl;
	int e = myQueue.empty();

	if (e != 0)
		cout << "The queue is empty!" << endl;
	else
		cout << "The queue is not empty!" << endl;

	cout << endl;

	cout << "Final Queue size and capacity!" << endl;
	cout << "Used " << myQueue.size() << endl;
	cout << "Capacity " << myQueue.capacity() << endl << endl;


	Stack<int> myStack(1);
	cout << myStack.Pop() << endl;
	cout << myStack.Pop() << endl;
	cout << myStack.Pop() << endl;

}

void LinkedListTest()
{
	LinkedList<int>* l1;
	l1 = new LinkedList<int>;
	l1->PushFront(10);
	l1->PushBack(12);
	l1->IndexInsert(2, 11);

	cout << l1->First() << endl;
	cout << l1->Last() << endl;

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
}

void main()
{
	//ObjectPool pool(50);

	//Entity* p = pool.Allocate();

	//pool.Deallocate(p);

	//DynamicArrayTest();
	//QueueTest();
	//LinkedListTest();
	ResourceManagerTest();


	system("pause");
}
