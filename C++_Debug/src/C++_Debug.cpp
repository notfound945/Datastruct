//============================================================================
// Name        : C++_Debug.cpp
// Author      : PHL
// Content	   : 数据结构: 顺序链栈
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef int ElementType;

// 定义栈的链式存储结构
typedef struct StackNode {
	ElementType data;
	struct StackNode *next;
} StackNode, *LinkStack;

int InitLinkStack(LinkStack &LS) {
	LS = NULL;
	return 1;
}

// 入栈
int Push(LinkStack &LS, ElementType e) {
	StackNode *p = new StackNode; // 创建一个新结点
	if (!p)
		return -1;
	p->data = e;
	p->next = LS;
	LS = p;
	return 0;
}

// 出栈
int Pop(LinkStack &LS, ElementType &e) {
	StackNode *p = new StackNode;
	if (LS == NULL)
		return -1;
	e = LS->data;
	p = LS;
	LS = p->next;
	delete (p);
	return 0;
}

// 取得栈顶元素
ElementType getTop(LinkStack &LS) {
	if (LS != NULL)
		return LS->data;
	else
		return -1;
}

// 获取栈大小
int getVolume(LinkStack &LS)
{
	int accout = 0; // 计数器
	StackNode *LS_temp = LS; //临时链栈
	while(LS_temp)
	{
		accout++;
		LS_temp = LS_temp->next;
	}
	delete(LS_temp); // 释放临时链栈
	return accout;
}

int main() {
	StackNode *LS = new StackNode;
	InitLinkStack(LS);
	ElementType pushElement, popElement;
	cout << "输入10个元素压入栈" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> pushElement;
		if (Push(LS, pushElement) == 0)
			cout << pushElement << " 元素插入成功" << endl;
		else
			cout << pushElement << "元素插入失败" << endl;
	}

	cout<<"当前栈大小"<<endl;
	cout<<getVolume(LS)<<endl;

	cout << endl << "打印栈顶元素" << endl;
	if (getTop(LS) == -1)
		cout << "链栈为空" << endl;
	else
		cout << "栈顶元素为 " << getTop(LS) << endl;

	cout << endl << "弹出元素" << endl;
	while (LS) {
		Pop(LS, popElement);
		cout << popElement << " 元素已弹出 " << endl;
	}

	cout<<"当前栈大小"<<endl;
	cout<<getVolume(LS)<<endl;

	cout << endl << "打印栈顶元素" << endl;
	if (getTop(LS) == -1)
		cout << "链栈为空" << endl;
	else
		cout << "栈顶元素为 " << getTop(LS) << endl;
	return 0;
}
