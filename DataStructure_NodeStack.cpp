#include "main.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;

void InitStack(LinkStack& S);
Status StackEmpty(LinkStack S);
Status Push(LinkStack& S, SElemType x);
Status Pop(LinkStack& S, SElemType& x);
SElemType GetTop(LinkStack S);

void main() {
	LinkStack S;
	SElemType x;
	InitStack(S);
	if (StackEmpty(S)) {
		printf("表为空！\n");
	}
	else
	{
		printf("表不为空！\n");
	}
	printf("插入：");
	scanf("%d", &x);
	Push(S, x);
	if (StackEmpty(S)) {
		printf("表为空！\n");
	}
	else
	{
		printf("表不为空！\n");
	}
	Pop(S, x);
	printf("删除：%d\n", x);
	printf("插入：");
	scanf("%d", &x);
	Push(S, x);
	printf("栈顶元素：%d\n", GetTop(S));
}

void InitStack(LinkStack& S) {
	S = NULL;
}

Status StackEmpty(LinkStack S) {
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

Status Push(LinkStack& S, SElemType x) {
	LinkStack p = new StackNode;
	//LinkStack p = (StackNode*)malloc(sizeof(StackNode));
	p->data = x;
	p->next = S;
	S = p;
	return OK;
}

Status Pop(LinkStack& S, SElemType& x) {
	LinkStack p;
	if (S == NULL)
	{
		return ERROR;
	}
	x = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}
