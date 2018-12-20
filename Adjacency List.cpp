
//============================================================================
// Name        : Adjacency List.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : 数据结构：图 邻接表 (Adjacency List) 深度优先遍历广度优先遍历
// Description : Hello World in C++, Ansi-style
// Explain : 
//			Adjacency List 邻接表
//			Adjacency Matrix 邻接矩阵
//			Vertex 顶点
//			
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
int Pop(StackList &S, int &data)
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

// 获取顶点索引地址
int LocationVex(ALGraph A, char ver[10] )
{
	for(int l = 0; l < A.verNumber; l++)
	{
		if(strcmp(ver, A.vertices[l].name) == 0)
			return l; // 返回顶点索引地址
	}
	return -1;
}

// 利用邻接表表示法创建无向图
int CreateGraph(ALGraph &A)
{
	int i = 0, j = 0;
	char v1[10], v2[10]; // 表示边上的两个顶点
	ArcNode *p1, *p2;
	// 打开输入文件流
	ifstream inputfile("data1.txt");
	cout<<"请输入邻接表的顶点数和边数"<<endl;
	// 从文件录入数据
	inputfile>>A.verNumber>>A.arcNumber;
	// 打印录入数据
	cout<<A.verNumber<<" "<<A.arcNumber<<endl;
	// 录入各个顶点名称
	cout<<"分别输入 "<<A.verNumber<<" 个顶点名称"<<endl;
	for(int k = 0; k < A.verNumber; k++) {
		inputfile>>A.vertices[k].name;
		cout<<A.vertices[k].name<<" ";
		A.vertices[k].firstarc = NULL;
	}
	// 录入各边依赖的两个顶点
	cout<<endl<<"分别输入 "<<A.arcNumber<<" 个边的两端顶点"<<endl;
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
	// 关闭输入文件流
	inputfile.close();
	return 0;
}

bool visited[MAX_NUMBER]; // 顶点访问标志
// 深度优先遍历 递归法
void DFS(ALGraph A, int v)
{
	cout<<A.vertices[v].name<<" "; // 打印遍历顶点名称
	visited[v] = true; // 标记已被访问
	ArcNode *p = new ArcNode;
	p = A.vertices[v].firstarc; // p指向当前顶点的边表第一个节点
	// p指针不为空
	while(p)
	{
		int w = p->adjvex;
		// 判断是否被访问
		if(!visited[w])
		{
			DFS(A, w); // 递归操作
		}
		p = p->nextarc; // p指向当前顶点的下一个边表节点
	}
}
// 广度优先遍历
void BFS(ALGraph A, int v)
{	
	int data; // 记录每次弹出栈元素
	ArcNode *p = new ArcNode; // 临时当前顶点边表节点指针
	StackList S; // 定义链栈
	InitStack(S); // 初始化链栈
	// 将所有访问标志置为 false
	for(int j = 0; j < A.verNumber; j++)
		visited[j] = false; 
	// 从 A.vertices[v] 顶点为起点开始遍历
	cout<<A.vertices[v].name<<" ";
	visited[v] = true; // 标记已被访问
	Push(S, v); // 压入初始顶点索引地址至链栈
	// 条件 链栈不为空
	while(S) 
	{
		Pop(S, data); // 弹出链栈元素
		p = A.vertices[data].firstarc; // p指向当前顶点的边表第一个节点
		// 条件 p指针不为空
		while(p) 
		{ 
			// 判断是否被访问
			if(!visited[p->adjvex])
			{
				cout<<A.vertices[p->adjvex].name<<" "; // 打印顶点名称
				visited[p->adjvex] = true; // 标记已被访问
				Push(S, p->adjvex); // 将当前顶点索引地址压入栈
			}
			p = p->nextarc; // p指针指向下一个节点
		}
	}
}

// 写入文件数据
int Write()
{
	// 定义两个输出文件流
	ofstream outputfile1("data1.txt");
	ofstream outputfile2("data2.txt");
	if(!outputfile1 && !outputfile2)
	{
		cout<<"文件创建失败，请检查是否有写入权限"<<endl;
		return -1;
	} else {
		cout<<"文件创建成功，写入数据"<<endl;
		outputfile1<<
			"5 6 "
			"v1 v2 v3 v4 v5 "
			"v1 v2 "
			"v1 v4 "
			"v2 v3 "
			"v2 v5 "
			"v3 v5 "
			"v3 v4 ";
		outputfile2<<
			"8 9 "
			"v1 v2 v3 v4 v5 v6 v7 v8 "
			"v1 v2 "
			"v1 v3 "
			"v3 v7 "
			"v6 v7 "
			"v3 v6 "
			"v2 v4 "
			"v2 v5 "
			"v4 v8 "
			"v5 v8 ";
		// 关闭输出文件流
		outputfile1.close();
		outputfile2.close();
		return 0;
	}
}

// 打印邻接链表
void Print(ALGraph A)
{
	ArcNode *p = new ArcNode;
	cout<<"打印邻接表"<<endl;
	for(int i = 0; i < A.verNumber; i++)
	{
		p = A.vertices[i].firstarc; // p指向当前顶点的边表第一个节点
		cout<<A.vertices[i].name;
		while(p)
		{
			cout<<" --> "<<A.vertices[p->adjvex].name;
			p = p->nextarc;
		}
		cout<<endl;
	}
}

// 主函数入口
int main() {
	ALGraph A; // 定义图
	Write(); // 写入文件
	CreateGraph(A); //创建图
	Print(A); // 打印图
	cout<<"深度优先搜索"<<endl;
	// 尝试优先遍历
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<endl<<"从 "<<A.vertices[i].name<<" 开始搜索"<<endl;
		DFS(A, i);
		for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // 重置访问标志为 flag
	}

	cout<<endl<<"广度优先搜索"<<endl;
	// 广度优先遍历
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<"从 "<<A.vertices[i].name<<" 开始搜索"<<endl;
		BFS(A, i);
		cout<<endl;
	}
}
