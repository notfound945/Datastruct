/*
    SeqStack.cpp
    ���ݽṹ��˳��ջ
*/

#include <iostream>

using namespace std;

// ����˳��ջ����󳤶�
#define MAXSIZE 20

// ͨ�����ͱ�ʶ��
typedef int ElemType;

// ����˳��ջ�Ĵ洢�ṹ
typedef struct {
	ElemType data[MAXSIZE]; //�洢ջ������Ԫ�ص�����
	int base; //ջ��
	int top; //ջ��
}SeqStack;

// ��ʼ��˳��ջ
void initSeqStack(SeqStack *S);
// ��ջ����
int Push(SeqStack *S, int e);
// ��ջ����
int Pop(SeqStack *S, int e);
// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(SeqStack *S);

// ��ʼ��˳��ջ
void initSeqStack(SeqStack *S) {
	S->base  = -1;
	S->top = S->base; // ջ����ջ��ָ�붼ָ��ͬһ�洢��Ԫ
};

/*��ջ���� ���ƶ�ջ��ָ�� ����ջ����*/
int Push(SeqStack *S, int e) {
	if(S->top - S->base == MAXSIZE )
    {
        return -1; //SeqStack������������ջ
    }else {
		S->top++;
		S->data[S->top] = e;
		return 1;
	}
}

/*��ջ���� �Ƚ�����ȡ�� ���ƶ�ջ��ָ��*/
int Pop(SeqStack *S, ElemType *e) {
	if(S->top == S->base)
		return -1; // ˳��ջ�ѿ� û�����ݿ��Գ�ջ
	else {
		*e = S->data[S->top];
		S->top--;
		return 1;
	}
}

/*�ж�˳��ջ�Ƿ�Ϊ��*/
bool isEmpty(SeqStack *S)
{
	if(S->top-S->base == 0) {
		return false; // ջΪ�� ���� 0
	}else {
		return true; // ���� ���� 1
	}
}

/*����ջ��Ԫ�صĸ���*/
int Size(SeqStack *S)
{
    return S->top + 1;
}

/*����ջ��Ԫ��*/
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

    int pushElement;// ��ջԪ��
    SeqStack *S; // ����˳���
	initSeqStack(S); // ��ʼ��ջ
    cout<<" ջ����Ϊ 10 "<<endl;
	cout<<" ����3��Ԫ��ѹ�뵽ջ "<<endl;
    // ��ջ
    for(int i = 0; i < 3; i++)
    {
        cin>>pushElement;
        if(Push(S, pushElement) == 1)
            cout<<pushElement<<" Ԫ��ѹ��ɹ�\n"<<endl;
        else
            cout<<pushElement<<" Ԫ��ѹ��ʧ��\n"<<endl;
    }
    cout<<" ��ջ�Ĵ�СΪ"<<Size(S)<<endl;

    /*
    // ��ջ
	ElemType *element = new ElemType; // ���յ���Ԫ��
	while (isEmpty(S)) {
		Pop(S, element);
		cout<<" ����Ԫ�� "<< *element<<endl;
	}
    cout<<S->base<< "  "<<S->top<<endl;
	cout<<" ջ�Ƿ�Ϊ�� "<<isEmpty(S)<<endl;
	*/
    //cout<<endl<<" �ٴ�ѹ��ջ ";
    for(int i = 2; i < 10 ; i++)
    //while(true)
    {
        cin>>pushElement;
        if(Push(S, pushElement) == 1)
            cout<<pushElement<<" Ԫ��ѹ��ɹ�\n"<<endl;
        else
            cout<<pushElement<<" Ԫ��ѹ��ʧ��\n"<<endl;
    }

/*
    // ��ջ
	while (isEmpty(S)) {
		Pop(S, element);
		cout<<" ����Ԫ�� "<< *element<<endl;
	}
    cout<<S->base<< "  "<<S->top<<endl;
	cout<<" ջ�Ƿ�Ϊ�� "<<isEmpty(S);*/
    return 0;
}
