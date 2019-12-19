#include"TQueue.h"

using namespace std;

template<class T>
TQueue<T>::TQueue(int _size)
{
	if (_size <= 0) throw - 1;
	MaxSize = _size;
	mas = new T[_size];
	Head = 0;
	Tail = -1;
	CurSize = 0;
}
template<class T>
TQueue<T>::~TQueue()
{
	delete[] mas;
}
template<class T>
TQueue<T>& TQueue<T>:: operator=(const TQueue<T>& q)
{
	
	
		if (MaxSize != q.MaxSize)
		{
			MaxSize = q.MaxSize;
			delete[] mas;
			mas = new T[MaxSize];
		}
		CurSize = q.CurSize;
		Head = q.Head;
		Tail = q.Tail;
		if (Tail >= Head)
		{
			for (int i = Head; i <= Tail; i++)
			{
				mas[i] = q.mas[i];
			}
		}
		else
		{
			for (int i = Head; i < MaxSize; i++)
			{
				mas[i] = q.mas[i];
			}
			for (int i = 0; i <= Tail ;i++)
			{
				mas[i] = q.mas[i];
			}
		}
	
	return *this;
}
template<class T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
	MaxSize = q.MaxSize;
	//delete[] mas;
	mas = new T[MaxSize];
	Head = q.Head;
	Tail = q.Tail;
	if (Tail >= Head)
	{
		for (int i = Head; i <= Tail; i++)
		{
			mas[i] = q.mas[i];
		}
	}
	else
	{
		for (int i = Head; i < MaxSize; i++)
		{
			mas[i] = q.mas[i];
		}
		for (int i = 0; i <= Tail ; i++)
		{
			mas[i] = q.mas[i];
		}
	}
}
template<class T>
bool TQueue<T>::Empty()
{
	return !CurSize;
}
template<class T>
bool TQueue<T>::Full()
{
	return CurSize == MaxSize;
}
template<class T>
void TQueue<T>::Push(T a)
{
	if (Full()) throw - 1;
	if (Tail != MaxSize - 1)
	{
		mas[++Tail] = a;
	}
	else
	{
		Tail = 0;
		mas[Tail] = a;
	}
	CurSize++;
}
template<class T>
T TQueue<T>::Pop()
{
	if (Empty())throw - 1;
	int pos = Head;
	if (Head != MaxSize - 1)
	{
		Head++;
	}
	else Head = 0;
	CurSize--;
	return mas[pos];
}
template<class T>
T TQueue<T>::Top()
{
	if (Empty())throw - 1;
	int pos = Head;
	return mas[pos];
}