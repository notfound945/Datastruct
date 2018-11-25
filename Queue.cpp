//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : 数据结构 ： 队列 链表结构
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef int QElemType;

// ------------ 队列的链表存储结构 --------------------
//链表
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front; // 头指针
	QueuePtr rear; // 尾指针
}LinkQueue;

// 初始化
int InitSqQueue(LinkQueue &L)
{
	L.front = L.rear = new QNode; // 生成新结点作为头结点 队头和队尾指针指向此结点
	L.rear->next = NULL;
	return 0;
}

// 入队列
int EnterQueue(LinkQueue &L, QElemType e)
{
	QNode *p = new QNode; // 生成新结点 赋值给此结点
	p->next = NULL;
	p->data= e;
	L.rear->next = p;
	L.rear = p;
	return 0;
}

// 出队列
int DeleteQueue(LinkQueue &L, QElemType &e)
{
	QNode *temp  = new QNode;
	if(L.rear == L.front) // 队空
		return -1;
	temp = L.front->next; // 指向头元素 头元素
	e = temp->data; // 保存队头元素
	L.front->next = temp->next; // 修改头结点的指针域
	if(L.rear == temp) // 头元素为最后一元素 队尾指针 指向头结点
		L.rear == L.front;
	delete temp; // 释放临时结点空间
	return 0;
}

// 打印队列元素
void PrintQueue(LinkQueue &S)
{
	LinkQueue temp; // 临时队列
	temp = S;
	while(temp.front->next != NULL) // 通过指针域身后遍历
	{
		cout<<temp.front->next->data<<" ";
		temp.front = temp.front->next;
	}

}

// 队列长度
int LengthQueue(LinkQueue &S)
{
	int length = 0;// 计数器
	LinkQueue temp;
	temp = S;
	while(temp.front->next != NULL)
	{
		length++;
		temp.front = temp.front->next;
	}
	return length;
}

// 取队头元素
void GetTop(LinkQueue &L)
{
	if(L.rear == L.front)
		cout<<"队列为空"<<endl;
	else
		cout<<"队头元素为 "<<L.front->next->data;
}

int main() {
	LinkQueue L;
	int number;
	QElemType  elem;
	cout<<"--初始化队列--"<<endl;
	InitSqQueue(L);
	cout<<"--入队操作--"<<endl;
	cout<<"请输入入队元素个数"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue(L, elem) == 0)
			cout<<elem<<" 元素入队成功"<<endl;
		else
			cout<<elem<<" 元素入队失败"<<endl;
	}
	cout<<"--出队操作--"<<endl;
	if(DeleteQueue(L, elem) == 0)
		cout<<elem<<" 元素出队成功"<<endl;
	else
		cout<<elem<<"元素出队失败"<<endl;

	cout<<"--打印队列中元素--"<<endl;
	PrintQueue(L);
	cout<<endl;

	cout<<"--队列长度--"<<endl;
	cout<<LengthQueue(L);
	cout<<endl;

	cout<<"--队头元素--"<<endl;
	GetTop(L);
	cout<<endl;

	return 0;
}
