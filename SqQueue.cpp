//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : ���ݽṹ �� ���� ˳��ṹ
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int QElemType;

// ------------ ���е�˳��洢�ṹ --------------------
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

// ��ʼ��
int InitSqQueue(SqQueue &S)
{
	S.base = new QElemType[MAXSIZE];
	S.rear = S.front = 0;
	return 0;
}

// �����
int EnterQueue(SqQueue &S, QElemType e)
{
	if((S.rear +1) % MAXSIZE == S.front) // ����
		return -1;
	S.base[S.rear] = e; // ��Ԫ�ز��뵽��β
	S.rear = (S.rear+1) % MAXSIZE; // βָ���1

	return 0;
}

// ������
int DeleteQueue(SqQueue &S, QElemType &e)
{
	if(S.rear == S.front) // �ӿ�
		return -1;
	e = S.base[S.front];  // �����ͷָ��
	S.front = (S.front+1) % MAXSIZE; // ͷָ��� 1
	return 0;
}

// ��ӡ����Ԫ��
void PrintQueue(SqQueue &S)
{
	for(int i = S.front; i < S.rear; i++)
		cout<<" "<<S.base[i];
}

// ���г���
int LengthQueue(SqQueue &S)
{
	return (S.rear - S.front + MAXSIZE) % MAXSIZE;
}

// ȡ��Ԫ��
void GetTop(SqQueue &S)
{
	if(S.rear == S.front)
		cout<<"����Ϊ��"<<endl;
	else
		cout<<S.base[S.front]<<endl;;

}

int main() {
	SqQueue S;
	int number;
	QElemType  elem;
	cout<<"--��ʼ������--"<<endl;
	InitSqQueue(S);
	cout<<"--��Ӳ���--"<<endl;
	cout<<"���������Ԫ�ظ���"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue(S, elem) == 0)
			cout<<elem<<" Ԫ����ӳɹ�"<<endl;
		else
			cout<<elem<<" Ԫ�����ʧ��"<<endl;
	}
	cout<<"--���Ӳ���--"<<endl;
	if(DeleteQueue(S, elem) == 0)
		cout<<elem<<" Ԫ�س��ӳɹ�"<<endl;
	else
		cout<<elem<<"Ԫ�س���ʧ��"<<endl;

	cout<<"--��ӡ������Ԫ��--"<<endl;
	PrintQueue(S);
	cout<<endl;

	cout<<"--���г���--"<<endl;
	cout<<LengthQueue(S);
	cout<<endl;

	cout<<"--��ͷԪ��--"<<endl;
	GetTop(S);
	cout<<endl;


	return 0;
}
