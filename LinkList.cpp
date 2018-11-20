#include <iostream>

using namespace std;

// Ϊ int ���ʹ��� ElemType ����
typedef int ElemType;

// ���������ṹ
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


// ��ʼ������
void InitList(LinkList &L)
{
    L = new LNode; // �����ڴ�
    //L = (struct  LNode *)malloc(sizeof(struct LNode)); // ����ͷ�ļ� stdlib.h �е� malloc �����ڴ�
    L->next = NULL;
}

// ����������½��
int InsertLinkList(LinkList &L, int i, ElemType e)
{
    LNode *p = L, *newNode;
    int j = 0;
    while(p &&  j < i-1) // ���ҵ� i-1 ����� pָ��ý��
    {
        p = p->next;
        j++;
    }
    if(!p || j > i-1)
        return -1;
    // ����ǰ�巨
    newNode = new LNode; // �����½��  newNode
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}


// ��ӡ�������
void PrintList(LinkList &L)
{
    LNode* p;
    p = L->next;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

// ������ȡֵ
int getElem(LinkList &L, int i)
{
    LNode *p;
    int j = 1; // ������ j ��ֵ��Ϊ 1
    p = L->next; // ��ʼ�� p ָ����Ԫ���
    while(p && j < i) // ˳����ָ�������ɨ�� ֱ�� p Ϊ�ջ�ָ��� i ��Ԫ��
    {
        p = p->next;
        j++;
    }
    if(!p || j > i) // i ֵ������ i > n �� i <= 0
    {
        cout<<"������ i ֵ������"<<endl;
        return -1;
    }
    cout<<p->data;
    return 1;
}

// ������Ĳ���
void LocationElem(LinkList L, ElemType e)
{
    LNode *p;
    int j = 1;
    p = L->next; // ��ʼ�� p ָ����Ԫ���
    while(p && p->data != e) // ˳������ָ��������ɨ�� ֱ�� p Ϊ�ջ���ָ������������� e
    {
        j++;
        p = p->next;
    }
    if(p != NULL) // �ж��Ƿ���ҵ����������Ϊ e �Ľ��
        cout<<"�������� "<<e<<" ��ֵ������Ԫ�����ڽ��λ�� "<<j<<endl;
    else
        cout<<"������û������Ԫ�غ� "<<e<<" ��ֵ "<<endl;
}

// ɾ��������Ԫ��
int LinkListDelete(LinkList &L, int i)
{
    int j = 0;
    LNode *p, *tempNode;
    p = L;
    while((p->next) && (j < i-1)) // ���ҵ� i-1 ��Ԫ�� pָ��ý��
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i-1) // �жϲ���λ���Ƿ����
        return -1;
    tempNode = p->next; // ��ʱ���汻ɾ�����ĵ�ַ�Ա��ͷ�
    p->next = tempNode->next; // �ı�ɾ�����ǰ������ָ����
    delete tempNode; // �ͷ�ɾ�����ռ�
    return 1;
}

// ǰ�巨����
void CreateList_H(LinkList &L, int n)
{
    LNode *p;
    // LinkList p;
    for(int i = 0; i < n; i++)
    {
        p = new LNode;
        cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}

// β�巨����
void CreateList_R(LinkList &L, int n)
{
    LNode *p, *tailNode;
    tailNode = L;
    for(int i = 0; i < n; i++)
    {
        p = new LNode;
        cin>>p->data;
        p->next = NULL;
        tailNode->next = p; // ���½��*p����β���*tailNode���������
        tailNode = p; // tailNode ָ���µ�β��� *p
    }
}

int main()
{
    // �������� L
    LinkList L;
    // ��ʼ������
    InitList(L);

    cout<<"ǰ�巨������5��Ԫ�صĵ�����"<<endl;
    CreateList_H(L, 5);
    cout<<"��ӡ��������"<<endl;
    PrintList(L);

    cout<<"��巨������5��Ԫ�صĵ�����"<<endl;
    CreateList_R(L, 5);
    cout<<"��ӡ��������"<<endl;
    PrintList(L);

    cout<<"�����������λ�ò�����ֵΪ 100 �Ľ��"<<endl;
    InsertLinkList(L, 3, 100);
    cout<<"��ӡ����Ԫ�غ����������"<<endl;
    PrintList(L);

    cout<<"ɾ�����������"<<endl;
    LinkListDelete(L, 6);
    cout<<"��ӡɾ��������������"<<endl;
    PrintList(L);

    cout<<"����Ԫ������Ϊ 100 ����������λ��"<<endl;
    LocationElem(L, 100);

}

