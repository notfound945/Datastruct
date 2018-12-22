// Adjacency Matrix.cpp : 定义控制台应用程序的入口点。
//
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
//			Vertex 顶点 (复 vertices)
//			Arc 弧
//			Edge 边
//			Directed graph 有向图
//			Undigraph 无向图
//			Minimum Cost Spanning Tree 最小生成树
//			Prim 普里姆算法
//			Kruskal 克鲁斯卡尔算法
//			
//============================================================================

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>

#define MAX_NUMBER 20 // 最大顶点数
#define MAX_INT 9999 // 表示极大值 9999

using namespace std;

// 定义邻接矩阵
typedef struct AMGraph
{
	char ver[MAX_NUMBER][20]; // 顶点表
	int arcs[MAX_NUMBER][MAX_NUMBER]; // 邻接矩阵
	int arcNumber, verNumber; // 图的顶点数和边数
}AMGraph;

// 定义辅助数组
struct Closedge
{
	int adjvex; // 最小边所在顶点
	int lowcost; // 最小边权值
}Closedge[MAX_NUMBER];

// 获取顶点地址索引
int Location(AMGraph A, char ver[])
{
	for(int i = 0; i < A.verNumber; i++)
		if(strcmp(A.ver[i], ver) == 0)
			return i;
	return -1;
}


// 创建邻接矩阵
int CreateGraph(AMGraph &A)
{
	ifstream inputfile("data.txt");
	int q, p, weight; // 定义存储顶点索引地址及权值
	char v1[10], v2[10]; // 定义存储顶点名称字符串数组
	cout<<"请输入无向图的顶点数和边数"<<endl;
	//cin>>A.verNumber>>A.arcNumber;
	inputfile>>A.verNumber>>A.arcNumber;
	cout<<A.verNumber<<" "<<A.arcNumber<<endl;
	// 输入顶点表
	cout<<"请输入 "<<A.verNumber<<" 个顶点名称"<<endl;
	for(int i =0; i < A.verNumber; i++)
	{
		//cin>>A.ver[i];
		inputfile>>A.ver[i];
		cout<<A.ver[i]<<" ";
	}
	cout<<endl;
	// 初始化所有边权值为 MAX_INT = 999
	for(int i = 0; i < A.verNumber; i++)
		for(int j = 0; j < A.verNumber; j++)
			A.arcs[i][j] = MAX_INT;
	cout<<"请输入与边依附的顶点及权值"<<endl;
	// 输入边依附的顶点和权值
	for(int i = 0; i < A.arcNumber; i++)
	{
		//cin>>v1>>v2>>weight;
		inputfile>>v1>>v2>>weight;
		cout<<v1<<" "<<v2<<" "<<weight<<endl;
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

//返回最小代价边地址索引
int Minmum(AMGraph A, struct Closedge * closedge)  
{
    unsigned int min = MAX_INT;
    int index = -1;
    for (int i = 0; i < A.verNumber;i++)
    {
        if (closedge[i].lowcost < min && closedge[i].lowcost !=0)
        {
            min = closedge[i].lowcost;
            index = i;
        }
    }
    return index;
}

// 普里姆算法
void MiniSpanTree_Prim(AMGraph A, char ver[])
{
	int s = Location(A, ver); // 按顶点名称获取顶点地址索引
    for (int i = 0; i < A.verNumber;i++)
    {
        Closedge[i].lowcost = MAX_INT;
    }      
    Closedge[s].adjvex = s;      //从顶点ver开始
    Closedge[s].lowcost = 0;
    for (int i = 0; i < A.verNumber;i++)  //初始化辅助数组
    {
        if (i != s)
        {
            Closedge[i].adjvex = s;
            Closedge[i].lowcost = A.arcs[s][i];
        }
    }
    for (int e = 1; e <= A.verNumber -1; e++)  //n-1条边时退出
    {
        int k = Minmum(A, Closedge);  //选择最小代价边
        cout << A.ver[Closedge[k].adjvex] << "--" << A.ver[k] << endl;//加入到最小生成树
        Closedge[k].lowcost = 0; //代价置为0
        for (int i = 0; i < A.verNumber;i++)  //更新v中顶点最小代价边信息
        {
            if ( A.arcs[k][i] < Closedge[i].lowcost) // 新顶点并入后重新选择最小边
            {
                Closedge[i].adjvex = k;
                Closedge[i].lowcost = A.arcs[k][i];
            }
        }
    }
}

// 将数据存储文件中
void Write()
{
	ofstream outputfile("data.txt");
	if(!outputfile)
		cout<<"文件创建失败"<<endl;
	outputfile<<
		" 6 10 "
		" v1 v2 v3 v4 v5 v6 "
		" v1 v2 6 "
		" v1 v4 5 "
		" v1 v3 1 "
		" v2 v3 5 "
		" v2 v5 3 "
		" v3 v5 6 "
		" v5 v6 6 "
		" v3 v6 4 "
		" v4 v6 2 "
		" v3 v4 5 ";
	outputfile.close();
}

// 打印输出矩阵表
void Print(AMGraph A)
{
	for(int i = 0; i < A.verNumber; i++)
	{
		for(int j = 0; j < A.verNumber; j++)
			cout<<A.arcs[i][j]<<" ";
		cout<<endl;
	}
}

// 主程序入口
int main()
{
	AMGraph A; // 定义网图
	Write(); // 输出数据到文件
	CreateGraph(A); // 创建邻接矩阵
	cout<<"打印邻接矩阵"<<endl;
	Print(A);
	cout<<"该图的最小生成树"<<endl;
	cout<<"从 v1 开始"<<endl;
	MiniSpanTree_Prim(A, "v1"); // 最小生成树
	return 0;
}
