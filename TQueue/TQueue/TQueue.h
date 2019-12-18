#pragma once
using namespace std;

template<class T>
class TQueue
{
	T* mas;        // кольцевой буфер
	int MaxSize;   // максимальный размер очереди
	int Tail;      // позиция хвоста
	int Head;      // позиция головы
	int CurSize;   // текущий размер
public:
	TQueue(int _size = 5);                            // конструктор по умолчанию/инициализации
	~TQueue();                                        //деструктор
	TQueue <T>& operator= (const TQueue<T>& q);       //оператор присваивания
	TQueue(const TQueue<T>& q);                       //конструктор копирования
	bool Empty();                                     //проверка на пустоту
	bool Full();                                      //проверка на полноту
	void Push(T a);                                      //записать в очередь
	T Pop();                                          //уддалить из очереди
};