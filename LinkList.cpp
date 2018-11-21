#include <iostream>

using namespace std;

// 为 int 类型创建 ElemType 别名
typedef int ElemType;

// 定义链表储结构
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


// 初始化链表
void InitList(LinkList &L)
{
    L = new LNode; // 分配内存
    //L = (struct  LNode *)malloc(sizeof(struct LNode)); // 调用头文件 stdlib.h 中的 malloc 分配内存
    L->next = NULL;
}

// 单链表插入新结点
int InsertLinkList(LinkList &L, int i, ElemType e)
{
    LNode *p = L, *newNode;
    int j = 0;
    while(p &&  j < i-1) // 查找第 i-1 个结点 p指向该结点
    {
        p = p->next;
        j++;
    }
    if(!p || j > i-1)
        return -1;
    // 类似前插法
    newNode = new LNode; // 生成新结点  newNode
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}


// 打印输出链表
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

// 单链表取值
int getElem(LinkList &L, int i)
{
    LNode *p;
    int j = 1; // 计数器 j 初值赋为 1
    p = L->next; // 初始化 p 指向首元结点
    while(p && j < i) // 顺链表指针域向后扫描 直到 p 为空或指向第 i 个元素
    {
        p = p->next;
        j++;
    }
    if(!p || j > i) // i 值不合理 i > n 或 i <= 0
    {
        cout<<"所给定 i 值不合理"<<endl;
        return -1;
    }
    cout<<p->data;
    return 1;
}

// 单链表的查找
void LocationElem(LinkList L, ElemType e)
{
    LNode *p;
    int j = 1;
    p = L->next; // 初始化 p 指向首元结点
    while(p && p->data != e) // 顺着链表指针域向下扫描 直到 p 为空或所指结点的数据域等于 e
    {
        j++;
        p = p->next;
    }
    if(p != NULL) // 判断是否查找到结点数据域为 e 的结点
        cout<<"链表中与 "<<e<<" 等值的数据元素所在结点位于 "<<j<<endl;
    else
        cout<<"链表中没有数据元素和 "<<e<<" 等值 "<<endl;
}

// 删除单链表元素
int LinkListDelete(LinkList &L, int i)
{
    int j = 0;
    LNode *p, *tempNode;
    p = L;
    while((p->next) && (j < i-1)) // 查找第 i-1 个元素 p指向该结点
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i-1) // 判断插入位置是否合理
        return -1;
    tempNode = p->next; // 临时保存被删除结点的地址以备释放
    p->next = tempNode->next; // 改变删除结点前驱结点的指针域
    delete tempNode; // 释放删除结点空间
    return 1;
}

// 前插法插入
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

// 尾插法插入
void CreateList_R(LinkList &L, int n)
{
    LNode *p, *tailNode;
    tailNode = L;
    for(int i = 0; i < n; i++)
    {
        p = new LNode;
        cin>>p->data;
        p->next = NULL;
        tailNode->next = p; // 将新结点*p插入尾结点*tailNode后的数据域
        tailNode = p; // tailNode 指向新的尾结点 *p
    }
}

int main()
{
    // 定义链表 L
    LinkList L;
    // 初始化链表
    InitList(L);

    cout<<"前插法创建有5个元素的单链表"<<endl;
    CreateList_H(L, 5);
    cout<<"打印链表数据"<<endl;
    PrintList(L);

    cout<<"后插法创建有5个元素的单链表"<<endl;
    CreateList_R(L, 5);
    cout<<"打印链表数据"<<endl;
    PrintList(L);

    cout<<"在链表第三个位置插入数值为 100 的结点"<<endl;
    InsertLinkList(L, 3, 100);
    cout<<"打印插入元素后的链表数据"<<endl;
    PrintList(L);

    cout<<"删除第六个结点"<<endl;
    LinkListDelete(L, 6);
    cout<<"打印删除结点后链表数据"<<endl;
    PrintList(L);

    cout<<"查找元素数据为 100 所在链表中位置"<<endl;
    LocationElem(L, 100);

}

