//============================================================================
// Name        : Graph.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : 数据结构：邻接表 (Adjacency List) 深度优先遍历
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_NUMBER 100
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
	cout<<"请输入邻接表的顶点数和边数"<<endl;
	cin>>A.verNumber>>A.arcNumber;
	// 录入各个顶点名称
	cout<<"分别输入 "<<A.verNumber<<" 个顶点名称"<<endl;
	for(int k = 0; k < A.verNumber; k++) {
		cin>>A.vertices[k].name;
		A.vertices[k].firstarc = NULL;
	}
	// 录入各边依赖的两个顶点
	cout<<"分别输入"<<A.arcNumber<<" 个边的两端顶点"<<endl;
	for(int k = 0; k < A.arcNumber; k++) {
		cin>>v1>>v2;
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

int main() {
	ALGraph A;
	CreateGraph(A);
	cout<<"深度优先搜索"<<endl;
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<endl<<"从 "<<A.vertices[i].name<<" 开始搜索"<<endl;
		DFS(A, i);
		for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // 访问标志
	}
	cout<<"广度优先搜索"<<endl;

}
