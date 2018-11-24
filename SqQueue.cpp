//============================================================================
// Name        : SqQueue.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content    : 数据结构 ： 队列 顺序结构
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int QElemType;

// ------------ 队列的顺序存储结构 --------------------
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

// 初始化
int InitSqQueue(SqQueue &S)
{
	S.base = new QElemType[MAXSIZE];
	S.rear = S.front = 0;
	return 0;
}

// 入队列
int EnterQueue(SqQueue &S, QElemType e)
{
	if((S.rear +1) % MAXSIZE == S.front) // 队满
		return -1;
	S.base[S.rear] = e; // 新元素插入到队尾
	S.rear = (S.rear+1) % MAXSIZE; // 尾指针加1

	return 0;
}

// 出队列
int DeleteQueue(SqQueue &S, QElemType &e)
{
	if(S.rear == S.front) // 队空
		return -1;
	e = S.base[S.front];  // 保存队头指针
	S.front = (S.front+1) % MAXSIZE; // 头指针加 1
	return 0;
}

// 打印队列元素
void PrintQueue(SqQueue &S)
{
	for(int i = S.front; i < S.rear; i++)
		cout<<" "<<S.base[i];
}

// 队列长度
int LengthQueue(SqQueue &S)
{
	return (S.rear - S.front + MAXSIZE) % MAXSIZE;
}

// 取顶元素
void GetTop(SqQueue &S)
{
	if(S.rear == S.front)
		cout<<"队列为空"<<endl;
	else
		cout<<S.base[S.front]<<endl;;

}

int main() {
	SqQueue S;
	int number;
	QElemType  elem;
	cout<<"--初始化队列--"<<endl;
	InitSqQueue(S);
	cout<<"--入队操作--"<<endl;
	cout<<"请输入入队元素个数"<<endl;
	cin>>number;

	for(int i = 0; i < number; i++)
	{
		cin>>elem;
		if(EnterQueue(S, elem) == 0)
			cout<<elem<<" 元素入队成功"<<endl;
		else
			cout<<elem<<" 元素入队失败"<<endl;
	}
	cout<<"--出队操作--"<<endl;
	if(DeleteQueue(S, elem) == 0)
		cout<<elem<<" 元素出队成功"<<endl;
	else
		cout<<elem<<"元素出队失败"<<endl;

	cout<<"--打印队列中元素--"<<endl;
	PrintQueue(S);
	cout<<endl;

	cout<<"--队列长度--"<<endl;
	cout<<LengthQueue(S);
	cout<<endl;

	cout<<"--队头元素--"<<endl;
	GetTop(S);
	cout<<endl;


	return 0;
}
