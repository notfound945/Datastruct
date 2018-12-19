// Graph.cpp : 定义控制台应用程序的入口点。
//
//============================================================================
// Name        : Graph.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : 数据结构：邻接表 (Adjacency List) 深度优先遍历
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_NUMBER 50
typedef int ElemType ;

// 边表 (边结点) 储存所有与些顶点相关的边
typedef struct ArcNode {
	int adjvex; //该边所指向的顶点位置
	struct ArcNode *nextarc; // 下一条边的地址
}ArcNode;

// 顶点信息
typedef struct VNode {
	char name[10]; // 顶点数据域
	ArcNode *firstarc; // 指向与此顶点连接第一条边的指针
}VNode, AdjList[MAX_NUMBER];

// 邻接表
typedef struct ALGraph{
	AdjList vertices;
	int verNumber, arcNumber;
}ALGraph;

// 链栈
typedef struct Stack {
	int data;
	struct Stack *next;
}StackNode, *StackList;

// 初始化栈
void InitStack(StackList &S)
{
	S = NULL;
}

// 元素压入栈
int Push(StackList &S, int data)
{
	StackNode *p = new StackNode;
	p->data = data;
	p->next = S;
	S = p;
	return 0;
}

// 元素弹出栈
int Pop(StackList &S, int data)
{
	StackNode *temp; // 临时保存栈顶元素
	if(S == NULL)
		return -1;
	data = S->data;
	temp = S;
	S = S->next;
	delete temp;
	return 0;
}

// 定位顶点序号
int LocationVex(ALGraph A, char ver[10] )
{
	for(int l = 0; l < A.verNumber; l++)
	{
		if(strcmp(ver, A.vertices[l].name) == 0)
			return l;
	}
	return -1;
}

// 利用邻接表表示法创建无向图
int CreateGraph(ALGraph &A)
{
	int i = 0, j = 0;
	char v1[10], v2[10]; // 表示边上的两个顶点
	ArcNode *p1, *p2;
	// 打开文件流
	ifstream inputfile("C:\\Users\\1\\Desktop\\demo.txt");
	cout<<"请输入邻接表的顶点数和边数"<<endl;
	// 从文件录入数据
	inputfile>>A.verNumber>>A.arcNumber;
	// 打印录入数据
	cout<<A.verNumber<<" "<<A.arcNumber<<endl;
	//cin>>A.verNumber>>A.arcNumber;
	// 录入各个顶点名称
	cout<<"分别输入 "<<A.verNumber<<" 个顶点名称"<<endl;
	for(int k = 0; k < A.verNumber; k++) {
		inputfile>>A.vertices[k].name;
		cout<<A.vertices[k].name<<" ";
		A.vertices[k].firstarc = NULL;
	}
	// 录入各边依赖的两个顶点
	cout<<endl<<"分别输入"<<A.arcNumber<<" 个边的两端顶点"<<endl;
	for(int k = 0; k < A.arcNumber; k++)  
	{
		inputfile>>v1>>v2;
		// 打印文件录入数据
		cout<<v1<<" "<<v2<<endl;
		// 从对应顶点中取出序号
		if(LocationVex(A, v1) != -1)
			i = LocationVex(A, v1);
		else
			cout<<"找不到"<<v1<<" 这个顶点"<<endl;

		if(LocationVex(A, v2) != -1)
			j = LocationVex(A, v2);
		else
			cout<<"找不到 "<<v2<<" 这个顶点"<<endl;

		p1 = new ArcNode;
		p2 = new ArcNode;
		p1->adjvex = i;
		p1->nextarc = A.vertices[j].firstarc;
		A.vertices[j].firstarc = p1;
		p2->adjvex = j;
		p2->nextarc = A.vertices[i].firstarc;
		A.vertices[i].firstarc = p2;
	}
	// 关闭文件流
	inputfile.close();
	return 0;
}
bool visited[MAX_NUMBER]; // 访问标志
void DFS(ALGraph A, int v)
{
	cout<<A.vertices[v].name<<" ";
	visited[v] = true;
	ArcNode *p = new ArcNode;
	p = A.vertices[v].firstarc;
	while(p)
	{
		int w = p->adjvex;
		if(!visited[w])
		{
			DFS(A, w);
		}
		p = p->nextarc;
	}
}

void BFS(ALGraph A,StackList &S, int v)
{\
	InitStack(S);
	cout<<A.vertices[v].name<<" ";
	visited[v] = true;
	for(int i = 0; i < A.verNumber; i++)
	{
		if(!visited[i])
		{
			visited[v] = true;
			cout<<A.vertices[v].name<<" ";
			Push(S, i);
			while(S)
			{
				
			}

	}
	}

}

// 写入文件数据
int Write()
{
	ofstream outputfile("C:\\Users\\1\\Desktop\\demo.txt");
	if(!outputfile)
	{
		cout<<"文件创建失败，请检查是否有写入权限"<<endl;
		return -1;
	} else {
		cout<<"文件创建成功，写入数据"<<endl;
		outputfile<<
			"5 6 "
			"v1 v2 v3 v4 v5 "
			"v1 v2 "
			"v1 v4 "
			"v2 v3 "
			"v2 v5 "
			"v3 v5 "
			"v3 v4 ";
		return 0;
	}
}
// 全局统一输入文件

int main() {
	
	// 建立并初始化栈
	char data[20];
	StackList S;

	ALGraph A;
	// 写入文件
	Write();
	CreateGraph(A);
	cout<<"测试打印"<<endl;
	while(A.vertices[0].firstarc)
	{
		cout<<" --> "<<A.vertices[A.vertices[0].firstarc->adjvex].name;
		A.vertices[0].firstarc = A.vertices[0].firstarc->nextarc;
		
	}
	cout<<"深度优先搜索"<<endl;
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<endl<<"从 "<<A.vertices[i].name<<" 开始搜索"<<endl;
		DFS(A, i);
		for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // 重置访问标志为 flag
	}
	cout<<endl<<"广度优先搜索"<<endl;

	for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // 重置访问标志为 flag
	BFS(A, S, 0);

}
