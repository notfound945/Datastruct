/*
    SeqStack.cpp
    数据结构：顺序栈
*/

#include <iostream>

using namespace std;

// 定义顺序栈的最大长度
#define MAXSIZE 20

// 通用类型标识符
typedef int ElemType;

// 定义顺序栈的存储结构
typedef struct {
	ElemType data[MAXSIZE]; //存储栈中数据元素的数组
	int base; //栈底
	int top; //栈顶
}SeqStack;

// 初始化顺序栈
void initSeqStack(SeqStack *S);
// 入栈函数
int Push(SeqStack *S, int e);
// 出栈函数
int Pop(SeqStack *S, int e);
// 判断栈是否为空
bool isEmpty(SeqStack *S);

// 初始化顺序栈
void initSeqStack(SeqStack *S) {
	S->base  = -1;
	S->top = S->base; // 栈顶与栈底指针都指向同一存储单元
};

/*入栈函数 先移动栈顶指针 再入栈数据*/
int Push(SeqStack *S, int e) {
	if(S->top - S->base == MAXSIZE )
    {
        return -1; //SeqStack已满，不能入栈
    }else {
		S->top++;
		S->data[S->top] = e;
		return 1;
	}
}

/*出栈函数 先将数据取出 再移动栈顶指针*/
int Pop(SeqStack *S, ElemType *e) {
	if(S->top == S->base)
		return -1; // 顺序栈已空 没有数据可以出栈
	else {
		*e = S->data[S->top];
		S->top--;
		return 1;
	}
}

/*判断顺序栈是否为空*/
bool isEmpty(SeqStack *S)
{
	if(S->top-S->base == 0) {
		return false; // 栈为空 返回 0
	}else {
		return true; // 否则 返回 1
	}
}

/*返回栈中元素的个数*/
int Size(SeqStack *S)
{
    return S->top + 1;
}

/*返回栈顶元素*/
bool GetTop(SeqStack *S, int element)
{
    if(S->top != -1)
    {
        element = S->data[S->top];
        return 1;
    } else
        return 0;
}

int main()
{

    int pushElement;// 入栈元素
    SeqStack *S; // 定义顺序表
	initSeqStack(S); // 初始化栈
    cout<<" 栈容量为 10 "<<endl;
	cout<<" 输入3个元素压入到栈 "<<endl;
    // 入栈
    for(int i = 0; i < 3; i++)
    {
        cin>>pushElement;
        if(Push(S, pushElement) == 1)
            cout<<pushElement<<" 元素压入成功\n"<<endl;
        else
            cout<<pushElement<<" 元素压入失败\n"<<endl;
    }
    cout<<" 此栈的大小为"<<Size(S)<<endl;

    /*
    // 出栈
	ElemType *element = new ElemType; // 接收弹出元素
	while (isEmpty(S)) {
		Pop(S, element);
		cout<<" 弹出元素 "<< *element<<endl;
	}
    cout<<S->base<< "  "<<S->top<<endl;
	cout<<" 栈是否为空 "<<isEmpty(S)<<endl;
	*/
    //cout<<endl<<" 再次压入栈 ";
    for(int i = 2; i < 10 ; i++)
    //while(true)
    {
        cin>>pushElement;
        if(Push(S, pushElement) == 1)
            cout<<pushElement<<" 元素压入成功\n"<<endl;
        else
            cout<<pushElement<<" 元素压入失败\n"<<endl;
    }

/*
    // 出栈
	while (isEmpty(S)) {
		Pop(S, element);
		cout<<" 弹出元素 "<< *element<<endl;
	}
    cout<<S->base<< "  "<<S->top<<endl;
	cout<<" 栈是否为空 "<<isEmpty(S);*/
    return 0;
}
