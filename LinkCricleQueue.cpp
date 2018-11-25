//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : 数据结构 ： 队列 循环链式结构
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef int QElemType;

// ------------ 队列循环链式存储结构 --------------------
//链表
typedef struct CQNode
{
	QElemType data;
	struct CQNode *next;
}CQNode, *CQLink;

// 初始化
int InitSqQueue(CQLink &C)
{
	C->next = C;// 生成新结点作 使队尾指针指向它
	return 0;
}

/*
 *  和单链表中元素插入一样
 *  有两种插入方式
 *  				头插法
 *  				尾插法
 *
 *					由于头插法插入结点在头结点后 在出队操作是不便于处理
 *					故使用尾插法插入
 */

// 入队
int EnterQueue_R(CQLink &C, QElemType e)
{
	CQNode *p = new CQNode; // 生成新结点p  并赋值给此结点
	p->data= e;
	p->next = C->next; // 新结点指向队头
	C->next = p; // 新结点 p 插入到队尾C之后
	C = p; // 新队尾结点更新为 p
	return 0;
}

// 出队
int DeleteQueue_H(CQLink &C, QElemType &e)
{
	// C 表示链表尾结点
	CQNode *temp  = new CQNode;

	if(C == C->next) // 队空
		return -1;
	temp = C->next->next;// 建立临时指向首元素
	e = temp->data; // 保存队头元素
	C->next->next = temp->next;
	if(temp == C) // 头元素为最后一元素 队尾指针 指向头结点
		C = C->next;
	delete temp; // 释放临时结点空间
	return 0;
}

// 打印队列元素
void PrintQueue(CQLink &C)
{
	CQLink temp = new CQNode; // 临时队列
	if(C->next == C)
		cout<<"队列为空"<<endl;
	else
	{
		temp = C->next->next; // 指向头元素
		while(temp != C->next)
		{
			cout<<" "<<temp->data;
			temp = temp->next;
		}
	}

}

// 队列长度
int LengthQueue(CQLink &C)
{
	int length = 0;// 计数器
	CQLink temp = new CQNode;
	temp = C->next->next; // 指向头元素
	while(temp != C->next)
	{
		length++;
		temp= temp->next;
	}
	return length;
}

// 取队头元素
void GetTop(CQLink &C)
{
	if(C->next == C)
		cout<<" 队列为空"<<endl;
	else
		cout<<" 队头元素为 "<<C->next->next->data;
}

int main() {
	CQLink C = new CQNode; // 链式队列
	int number; // 入队元素
	QElemType  elem;
	cout<<"--初始化队列--"<<endl;
	InitSqQueue(C);
	cout<<"--入队操作--"<<endl;
	cout<<"请输入入队元素个数"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue_R(C, elem) == 0)
			cout<<elem<<" 元素入队成功"<<endl;
		else
			cout<<elem<<" 元素入队失败"<<endl;
	}
	cout<<"--出队操作--"<<endl;
	if(DeleteQueue_H(C, elem) == 0)
		cout<<elem<<" 元素出队成功"<<endl;
	else
		cout<<elem<<"元素出队失败"<<endl;

 	cout<<"--打印队列中元素--"<<endl;
	PrintQueue(C);
	cout<<endl;

	cout<<"--队列长度--"<<endl;
	cout<<" "<<LengthQueue(C)<<endl;

	cout<<"--队头元素--"<<endl;
	GetTop(C);
	cout<<endl;

	return 0;
}
