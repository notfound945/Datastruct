//============================================================================
// Name        : Graph.cpp
// Author      : PHL
// Version     :
// Copyright   : 
// Content : ���ݽṹ���ڽӱ� (Adjacency List) ������ȱ���
// Description : Hello World in C++, Ansi-style
//============================================================================

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
	cout<<"�������ڽӱ�Ķ������ͱ���"<<endl;
	cin>>A.verNumber>>A.arcNumber;
	// ¼�������������
	cout<<"�ֱ����� "<<A.verNumber<<" ����������"<<endl;
	for(int k = 0; k < A.verNumber; k++) {
		cin>>A.vertices[k].name;
		A.vertices[k].firstarc = NULL;
	}
	// ¼�������������������
	cout<<"�ֱ�����"<<A.arcNumber<<" ���ߵ����˶���"<<endl;
	for(int k = 0; k < A.arcNumber; k++) {
		cin>>v1>>v2;
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

int main() {
	ALGraph A;
	CreateGraph(A);
	cout<<"�����������"<<endl;
	for(int i = 0; i < A.verNumber; i++)
	{
		cout<<endl<<"�� "<<A.vertices[i].name<<" ��ʼ����"<<endl;
		DFS(A, i);
		for(int j = 0; j < A.verNumber; j++)
			visited[j] = false; // ���ʱ�־
	}
	cout<<"�����������"<<endl;



}
