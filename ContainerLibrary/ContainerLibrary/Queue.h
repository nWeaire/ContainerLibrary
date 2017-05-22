#pragma once

template <typename T>
class Queue
{
public:
	Queue(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	Queue(const Queue& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	~Queue()
	{
		delete m_pData;
	}

	T front()
	{
		return m_pData[0];
	}

	T back()
	{
		return m_pData[m_nUsed];
	}

	void push(T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();
		
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}
	
	T pop()
	{
		// backup value we are removing from list
		T value = m_pData[0];

		// shuffle all other values across to fill removed space
		for (int i = 0; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		// return removed value
		return value;
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