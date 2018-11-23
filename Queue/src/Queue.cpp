//============================================================================
// Name        : Queue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
//	Content  : 数据结构：队列
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAXSIZE 10 // 队列可能达到的最大长度

typedef int QElemType;

typedef struct
{
	QElemType *base; // 存储空间的基地址
	int front; // 头指针
	int rear; // 尾指针
}SqQueue;


// 循环队列初始化
int InitQueue(SqQueue &Q)
{
	Q.base = new QElemType[MAXSIZE]; // 分配数组空间
	if(!Q.base)
		return -1;
	Q.front= Q.rear = 0; // 头指针和尾指针置为零 队列为空
	return 0;
}

// 循环队列的入队
int EnterQueue(SqQueue &Q, QElemType e)
{
	if((Q.rear + 1) % MAXSIZE == Q.front) // 队满
		return -1;
	Q.base[Q.rear] = e; // 新元素插入队尾
	Q.rear = (Q.rear+1) % MAXSIZE; // 队列指针加1
	return 0;
}

// 循环队列出队
int DeleteQueue(SqQueue &Q, QElemType &e)
{
	if(Q.front == Q.rear) // 队空
		return -1;
	e = Q.base[Q.front];
	Q.front = (Q.front +1) % MAXSIZE;
	return 0;
}

// 求循环队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 取队列首元素
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
	cout<<"初始化队列"<<endl;
	InitQueue(Q);
	cout<<"元素入队"<<endl;
	for(int i = 0; i < 11; i++)
	{
		if(EnterQueue(Q, i) == 0)
			cout<<i<<" 元素入队成功"<<endl;
		else
			cout<<i<<" 元素入队失败"<<endl;
	}

	cout<<"元素出队"<<endl;
	DeleteQueue(Q, e);
	cout<<e<<" 元素已出队"<<endl;
	cout<<"队列长度"<<endl;
	cout<<QueueLength(Q)<<endl;
	cout<<"队头元素"<<endl;
	cout<<GetHead(Q);
	return 0;
}






