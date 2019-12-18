#pragma once
using namespace std;

template<class T>
class TQueue
{
	T* mas;        // ��������� �����
	int MaxSize;   // ������������ ������ �������
	int Tail;      // ������� ������
	int Head;      // ������� ������
	int CurSize;   // ������� ������
public:
	TQueue(int _size = 5);                            // ����������� �� ���������/�������������
	~TQueue();                                        //����������
	TQueue <T>& operator= (const TQueue<T>& q);       //�������� ������������
	TQueue(const TQueue<T>& q);                       //����������� �����������
	bool Empty();                                     //�������� �� �������
	bool Full();                                      //�������� �� �������
	void Push(T a);                                      //�������� � �������
	T Pop();                                          //�������� �� �������
};