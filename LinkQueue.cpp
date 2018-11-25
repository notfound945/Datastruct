//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : ���ݽṹ �� ���� ѭ����ʽ�ṹ
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef int QElemType;

// ------------ ����ѭ����ʽ�洢�ṹ --------------------
//����
typedef struct CQNode
{
	QElemType data;
	struct CQNode *next;
}CQNode, *CQLink;

// ��ʼ��
int InitSqQueue(CQLink &C)
{
	C->next = C;// �����½���� ʹ��βָ��ָ����
	return 0;
}

/*
 *  �͵�������Ԫ�ز���һ��
 *  �����ֲ��뷽ʽ
 *  				ͷ�巨
 *  				β�巨
 *
 *					����ͷ�巨��������ͷ���� �ڳ��Ӳ����ǲ����ڴ���
 *					��ʹ��β�巨����
 */

// ���
int EnterQueue_R(CQLink &C, QElemType e)
{
	CQNode *p = new CQNode; // �����½��p  ����ֵ���˽��
	p->data= e;
	p->next = C->next; // �½��ָ���ͷ
	C->next = p; // �½�� p ���뵽��βC֮��
	C = p; // �¶�β������Ϊ p
	return 0;
}

// ����
int DeleteQueue_H(CQLink &C, QElemType &e)
{
	// C ��ʾ����β���
	CQNode *temp  = new CQNode;

	if(C == C->next) // �ӿ�
		return -1;
	temp = C->next->next;// ������ʱָ����Ԫ��
	e = temp->data; // �����ͷԪ��
	C->next->next = temp->next;
	if(temp == C) // ͷԪ��Ϊ���һԪ�� ��βָ�� ָ��ͷ���
		C = C->next;
	delete temp; // �ͷ���ʱ���ռ�
	return 0;
}

// ��ӡ����Ԫ��
void PrintQueue(CQLink &C)
{
	CQLink temp = new CQNode; // ��ʱ����
	if(C->next == C)
		cout<<"����Ϊ��"<<endl;
	else
	{
		temp = C->next->next; // ָ��ͷԪ��
		while(temp != C->next)
		{
			cout<<" "<<temp->data;
			temp = temp->next;
		}
	}

}

// ���г���
int LengthQueue(CQLink &C)
{
	int length = 0;// ������
	CQLink temp = new CQNode;
	temp = C->next->next; // ָ��ͷԪ��
	while(temp != C->next)
	{
		length++;
		temp= temp->next;
	}
	return length;
}

// ȡ��ͷԪ��
void GetTop(CQLink &C)
{
	if(C->next == C)
		cout<<" ����Ϊ��"<<endl;
	else
		cout<<" ��ͷԪ��Ϊ "<<C->next->next->data;
}

int main() {
	CQLink C = new CQNode; // ��ʽ����
	int number; // ���Ԫ��
	QElemType  elem;
	cout<<"--��ʼ������--"<<endl;
	InitSqQueue(C);
	cout<<"--��Ӳ���--"<<endl;
	cout<<"���������Ԫ�ظ���"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue_R(C, elem) == 0)
			cout<<elem<<" Ԫ����ӳɹ�"<<endl;
		else
			cout<<elem<<" Ԫ�����ʧ��"<<endl;
	}
	cout<<"--���Ӳ���--"<<endl;
	if(DeleteQueue_H(C, elem) == 0)
		cout<<elem<<" Ԫ�س��ӳɹ�"<<endl;
	else
		cout<<elem<<"Ԫ�س���ʧ��"<<endl;

 	cout<<"--��ӡ������Ԫ��--"<<endl;
	PrintQueue(C);
	cout<<endl;

	cout<<"--���г���--"<<endl;
	cout<<" "<<LengthQueue(C)<<endl;

	cout<<"--��ͷԪ��--"<<endl;
	GetTop(C);
	cout<<endl;

	return 0;
}
