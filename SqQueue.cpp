//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : ���ݽṹ �� ���� ����ṹ
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef int QElemType;

// ------------ ���е�����洢�ṹ --------------------
//����
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front; // ͷָ��
	QueuePtr rear; // βָ��
}LinkQueue;

// ��ʼ��
int InitSqQueue(LinkQueue &L)
{
	L.front = L.rear = new QNode; // �����½����Ϊͷ��� ��ͷ�Ͷ�βָ��ָ��˽��
	L.rear->next = NULL;
	return 0;
}

// �����
int EnterQueue(LinkQueue &L, QElemType e)
{
	QNode *p = new QNode; // �����½�� ��ֵ���˽��
	p->next = NULL;
	p->data= e;
	L.rear->next = p;
	L.rear = p;
	return 0;
}

// ������
int DeleteQueue(LinkQueue &L, QElemType &e)
{
	QNode *temp  = new QNode;
	if(L.rear == L.front) // �ӿ�
		return -1;
	temp = L.front->next; // ָ��ͷԪ�� ͷԪ��
	e = temp->data; // �����ͷԪ��
	L.front->next = temp->next; // �޸�ͷ����ָ����
	if(L.rear == temp) // ͷԪ��Ϊ���һԪ�� ��βָ�� ָ��ͷ���
		L.rear == L.front;
	delete temp; // �ͷ���ʱ���ռ�
	return 0;
}

// ��ӡ����Ԫ��
void PrintQueue(LinkQueue &S)
{
	LinkQueue temp; // ��ʱ����
	temp = S;
	while(temp.front->next != NULL) // ͨ��ָ����������
	{
		cout<<temp.front->next->data<<" ";
		temp.front = temp.front->next;
	}

}

// ���г���
int LengthQueue(LinkQueue &S)
{
	int length = 0;// ������
	LinkQueue temp;
	temp = S;
	while(temp.front->next != NULL)
	{
		length++;
		temp.front = temp.front->next;
	}
	return length;
}

// ȡ��ͷԪ��
void GetTop(LinkQueue &L)
{
	if(L.rear == L.front)
		cout<<"����Ϊ��"<<endl;
	else
		cout<<"��ͷԪ��Ϊ "<<L.front->next->data;
}

int main() {
	LinkQueue L;
	int number;
	QElemType  elem;
	cout<<"--��ʼ������--"<<endl;
	InitSqQueue(L);
	cout<<"--��Ӳ���--"<<endl;
	cout<<"���������Ԫ�ظ���"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue(L, elem) == 0)
			cout<<elem<<" Ԫ����ӳɹ�"<<endl;
		else
			cout<<elem<<" Ԫ�����ʧ��"<<endl;
	}
	cout<<"--���Ӳ���--"<<endl;
	if(DeleteQueue(L, elem) == 0)
		cout<<elem<<" Ԫ�س��ӳɹ�"<<endl;
	else
		cout<<elem<<"Ԫ�س���ʧ��"<<endl;

	cout<<"--��ӡ������Ԫ��--"<<endl;
	PrintQueue(L);
	cout<<endl;

	cout<<"--���г���--"<<endl;
	cout<<LengthQueue(L);
	cout<<endl;

	cout<<"--��ͷԪ��--"<<endl;
	GetTop(L);
	cout<<endl;

	return 0;
}
