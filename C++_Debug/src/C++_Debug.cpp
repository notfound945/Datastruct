//============================================================================
// Name        : C++_Debug.cpp
// Author      : PHL
// Content	   : ���ݽṹ: ˳����ջ
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef int ElementType;

// ����ջ����ʽ�洢�ṹ
typedef struct StackNode {
	ElementType data;
	struct StackNode *next;
} StackNode, *LinkStack;

int InitLinkStack(LinkStack &LS) {
	LS = NULL;
	return 1;
}

// ��ջ
int Push(LinkStack &LS, ElementType e) {
	StackNode *p = new StackNode; // ����һ���½��
	if (!p)
		return -1;
	p->data = e;
	p->next = LS;
	LS = p;
	return 0;
}

// ��ջ
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

// ȡ��ջ��Ԫ��
ElementType getTop(LinkStack &LS) {
	if (LS != NULL)
		return LS->data;
	else
		return -1;
}

// ��ȡջ��С
int getVolume(LinkStack &LS)
{
	int accout = 0; // ������
	StackNode *LS_temp = LS; //��ʱ��ջ
	while(LS_temp)
	{
		accout++;
		LS_temp = LS_temp->next;
	}
	delete(LS_temp); // �ͷ���ʱ��ջ
	return accout;
}

int main() {
	StackNode *LS = new StackNode;
	InitLinkStack(LS);
	ElementType pushElement, popElement;
	cout << "����10��Ԫ��ѹ��ջ" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> pushElement;
		if (Push(LS, pushElement) == 0)
			cout << pushElement << " Ԫ�ز���ɹ�" << endl;
		else
			cout << pushElement << "Ԫ�ز���ʧ��" << endl;
	}

	cout<<"��ǰջ��С"<<endl;
	cout<<getVolume(LS)<<endl;

	cout << endl << "��ӡջ��Ԫ��" << endl;
	if (getTop(LS) == -1)
		cout << "��ջΪ��" << endl;
	else
		cout << "ջ��Ԫ��Ϊ " << getTop(LS) << endl;

	cout << endl << "����Ԫ��" << endl;
	while (LS) {
		Pop(LS, popElement);
		cout << popElement << " Ԫ���ѵ��� " << endl;
	}

	cout<<"��ǰջ��С"<<endl;
	cout<<getVolume(LS)<<endl;

	cout << endl << "��ӡջ��Ԫ��" << endl;
	if (getTop(LS) == -1)
		cout << "��ջΪ��" << endl;
	else
		cout << "ջ��Ԫ��Ϊ " << getTop(LS) << endl;
	return 0;
}
