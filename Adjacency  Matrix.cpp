
//============================================================================
// Name        : Adjacency Matrix.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : 数据结构：图 邻接矩阵 (Adjacency Matrix) 最小生成树
// Description : Hello World in C++, Ansi-style
// Explain : 
//			Adjacency List 邻接表
//			Adjacency Matrix 邻接矩阵
//			Vertex 顶点
//			Minimum Cost Spanning Tree 最小生成树
//			Prim 普里姆算法
//			Kruskal 克鲁斯卡尔算法
//			
//============================================================================

#include "stdafx.h"
#include <iostream>
#include <string.h>

#define MAX_NUMBER 20
#define MAX_INT 9999

using namespace std;

typedef struct 
{
	char ver[MAX_NUMBER][20];
	int arcs[MAX_NUMBER][MAX_NUMBER];
	int arcNumber, verNumber;
}AMGraph;

int Location(AMGraph A, char ver[])
{
	for(int i = 0; i < A.verNumber; i++)
		if(strcmp(A.ver[i], ver) == 0)
			return i;
	return -1;
}

int CreateGraph(AMGraph &A)
{
	int q, p, weight; // 定义存储顶点索引地址及权值
	char v1[10], v2[10]; // 定义存储顶点名称字符串数组
	cout<<"输入邻接矩阵的顶点数和边数"<<endl;
	cin>>A.verNumber>>A.arcNumber;
	// 输入顶点表
	cout<<"输入 "<<A.verNumber<<" 个顶点信息"<<endl;
	for(int i =0; i < A.verNumber; i++)
		cin>>A.ver[i];
	// 初始化所有边权值为 MAX_INT = 999
	for(int i = 0; i < A.verNumber; i++)
		for(int j = 0; j < A.verNumber; j++)
			A.arcs[i][j] = MAX_INT;
	cout<<"输入边依附的顶点和权值"<<endl;
	// 输入边依附的顶点和权值
	for(int i = 0; i < A.arcNumber; i++)
	{
		cin>>v1>>v2>>weight;
		if(Location(A, v1) != -1 && Location(A, v2) != -1)
		{
			q = Location(A, v1);
			p = Location(A, v2);
			A.arcs[q][p] = weight; // 边<v1, v2>的权值均置为 weight 
			A.arcs[p][q] = weight; // 边<v2, v1>的权值均置为 weight
		}
		else
			cout<<"没有找到 "<<v1<<" 或 "<<v2<<" 节点"<<endl;
	}
	return 0;
}
