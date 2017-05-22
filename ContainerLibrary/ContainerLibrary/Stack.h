#pragma once

template <typename T>
class Stack
{
public:

	Stack(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	Stack(const Stack& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	~Stack()
	{
		delete m_pData;
	}

	void pushFront(T value)
	{
		Insert(0, value);
	}

	void Insert(int index, T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();

		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}
		m_pData[index] = value;
		++m_nUsed;

	}

	T Pop()
	{
		if (m_nUsed >= 0)
		{
			--m_nUsed;
			return m_pData[m_nUsed];
		}
		else
			return NULL;
	}

	T Top()
	{
		if (m_nUsed < 0)
			return NULL;
		else
			return m_nData[m_nUsed];
	}

	int capacity()
	{
		return m_nCapacity;
	}

	int size()
	{
		return m_nUsed;
	}


	T& operator[](const int index)
	{
		return m_pData[index];
	}

	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[nCapacity];
		memcpy(newData, m_pData, sizeof(T) * nCapacity);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = nCapacity;
	}

	void clear()
	{
		m_nUsed = 0;
		Shrink();
	}

	bool empty()
	{
		if (m_nUsed == 0)
			return true;
	}


private:
	void Resize()
	{
		// Create new array that is twice as big as original
		T* newData = new T[m_nCapacity * 2];

		// Cope old data across into new array
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);

		// Delete old array
		delete m_pData;

		//Make sure our pointers still work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	};

	T* m_pData;
	int m_nCapacity;
	int m_nUsed;


};