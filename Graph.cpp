// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
//
//============================================================================
// Name        : Graph.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : ���ݽṹ���ڽӱ� (Adjacency List) ������ȱ���
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

#define MAX_NUMBER 100
typedef int ElemType ;

// �߱� (�߽��) ����������Щ������صı�
typedef struct ArcNode {
	int adjvex; //�ñ���ָ��Ķ���λ��
	struct ArcNode *nextarc; // ��һ���ߵĵ�ַ
}ArcNode;

// ������Ϣ
typedef struct VNode {
	char name[10]; // ����������
	ArcNode *firstarc; // ָ����˶������ӵ�һ���ߵ�ָ��
}VNode, AdjList[MAX_NUMBER];

// �ڽӱ�
typedef struct ALGraph{
	AdjList vertices;
	int verNumber, arcNumber;
}ALGraph;

// ��ջ
typedef struct Stack {
	char data[10];
	struct Stack *next;
}StackNode, *StackList;

// ��ʼ��ջ
void InitStack(StackList &S)
{
	S = NULL;
}

// Ԫ��ѹ��ջ
int Push(StackList &S, char data[])
{
	StackNode *p = new StackNode;
	strcpy(p->data, data);
	p->next = S;
	S = p;
	return 0;
}

// Ԫ�ص���ջ
int Pop(StackList &S, char data[])
{
	StackNode *temp; // ��ʱ����ջ��Ԫ��
	if(S == NULL)
		return -1;
	strcpy(data, S->data);
	temp = S;
	S = S->next;
	delete temp;
	return 0;
}

// ��λ�������
int LocationVex(ALGraph A, char ver[10] )
{
	for(int l = 0; l < A.verNumber; l++)
	{
		if(strcmp(ver, A.vertices[l].name) == 0)
			return l;
	}
	return -1;
}

// �����ڽӱ��ʾ����������ͼ
int CreateGraph(ALGraph &A)
{
	int i = 0, j = 0;
	char v1[10], v2[10]; // ��ʾ���ϵ���������
	ArcNode *p1, *p2;
	// ���ļ���
	ifstream inputfile("C:\\Users\\1\\Desktop\\demo.txt");
	cout<<"�������ڽӱ�Ķ������ͱ���"<<endl;
	// ���ļ�¼������
	inputfile>>A.verNumber>>A.arcNumber;
	// ��ӡ¼������
	cout<<A.verNumber<<" "<<A.arcNumber<<endl;
	//cin>>A.verNumber>>A.arcNumber;
	// ¼�������������
	cout<<"�ֱ����� "<<A.verNumber<<" ����������"<<endl;
	for(int k = 0; k < A.verNumber; k++) {
		inputfile>>A.vertices[k].name;
		cout<<A.vertices[k].name<<" ";
		A.vertices[k].firstarc = NULL;
	}
	// ¼�������������������
	cout<<endl<<"�ֱ�����"<<A.arcNumber<<" ���ߵ����˶���"<<endl;
	for(int k = 0; k < A.arcNumber; k++) {
		inputfile>>v1>>v2;
		// ��ӡ�ļ�¼������
		cout<<v1<<" "<<v2<<endl;
		// �Ӷ�Ӧ������ȡ�����
		if(LocationVex(A, v1) != -1)
			i = LocationVex(A, v1);
		else
			cout<<"�Ҳ���"<<v1<<" �������"<<endl;

		if(LocationVex(A, v2) != -1)
			j = LocationVex(A, v2);
		else
			cout<<"�Ҳ��� "<<v2<<" �������"<<endl;

		p1 = new ArcNode;
		p2 = new ArcNode;
		p1->adjvex = i;
		p1->nextarc = A.vertices[j].firstarc;
		A.vertices[j].firstarc = p1;
		p2->adjvex = j;
		p2->nextarc = A.vertices[i].firstarc;
		A.vertices[i].firstarc = p2;
	}
	// �ر��ļ���
	inputfile.close();
	return 0;
}
bool visited[MAX_NUMBER]; // ���ʱ�־
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
{
	cout<<A.vertices[v].name<<" ";
	visited[v] = true;
	Push(S, A.vertices[v].name);
	while(S);
	

}

// д���ļ�����
int Write()
{
	ofstream outputfile("C:\\Users\\1\\Desktop\\demo.txt");
	if(!outputfile)
	{
		cout<<"�ļ�����ʧ�ܣ������Ƿ���д��Ȩ��"<<endl;
		return -1;
	} else {
		cout<<"�ļ������ɹ���д������"<<endl;
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
// ȫ��ͳһ�����ļ�

int main() {
	
	// ��������ʼ��ջ
	char data[20];
	StackList S;
	InitStack(S);
	ALGraph A;
	// д���ļ�
	Write();
	CreateGraph(A);
	cout<<"�����������"<<endl;
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<endl<<"�� "<<A.vertices[i].name<<" ��ʼ����"<<endl;
		DFS(A, i);
		for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // ���÷��ʱ�־Ϊ flag
	}
	cout<<endl<<"�����������"<<endl;

	for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // ���÷��ʱ�־Ϊ flag
	BFS(A, S, 0);

}
