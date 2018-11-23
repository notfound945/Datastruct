//============================================================================
// Name        : Queue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
//	Content  : ���ݽṹ������
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAXSIZE 10 // ���п��ܴﵽ����󳤶�

typedef int QElemType;

typedef struct
{
	QElemType *base; // �洢�ռ�Ļ���ַ
	int front; // ͷָ��
	int rear; // βָ��
}SqQueue;


// ѭ�����г�ʼ��
int InitQueue(SqQueue &Q)
{
	Q.base = new QElemType[MAXSIZE]; // ��������ռ�
	if(!Q.base)
		return -1;
	Q.front= Q.rear = 0; // ͷָ���βָ����Ϊ�� ����Ϊ��
	return 0;
}

// ѭ�����е����
int EnterQueue(SqQueue &Q, QElemType e)
{
	if((Q.rear + 1) % MAXSIZE == Q.front) // ����
		return -1;
	Q.base[Q.rear] = e; // ��Ԫ�ز����β
	Q.rear = (Q.rear+1) % MAXSIZE; // ����ָ���1
	return 0;
}

// ѭ�����г���
int DeleteQueue(SqQueue &Q, QElemType &e)
{
	if(Q.front == Q.rear) // �ӿ�
		return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front +1) % MAXSIZE;
	return 0;
}

// ��ѭ�����г���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// ȡ������Ԫ��
QElemType GetHead(SqQueue Q)
{
	if(Q.front != Q.rear)
		return Q.base[Q.front];
	else
		return -1;
}

int main() {
	SqQueue Q;
	QElemType e;
	cout<<"��ʼ������"<<endl;
	InitQueue(Q);
	cout<<"Ԫ�����"<<endl;
	for(int i = 0; i < 11; i++)
	{
		if(EnterQueue(Q, i) == 0)
			cout<<i<<" Ԫ����ӳɹ�"<<endl;
		else
			cout<<i<<" Ԫ�����ʧ��"<<endl;
	}

	cout<<"Ԫ�س���"<<endl;
	DeleteQueue(Q, e);
	cout<<e<<" Ԫ���ѳ���"<<endl;
	cout<<"���г���"<<endl;
	cout<<QueueLength(Q)<<endl;
	cout<<"��ͷԪ��"<<endl;
	cout<<GetHead(Q);
	return 0;
}






