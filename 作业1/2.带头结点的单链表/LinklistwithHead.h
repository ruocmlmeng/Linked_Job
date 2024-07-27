
#ifndef __LinklistwithHead_H__
#define __LinklistwithHead_H__

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}Node;

typedef struct Head
{
	Node * first;
	Node * last;
	ElemType num;
}Head;

Head * create_Head(void);

void create_List(Head * h);

void add_Node(Head * h,Node * p);

void Delete_X(Head *h, ElemType x);

void Delete_All_X(Head * h,ElemType x);

void destory_List(Head * h);

void Print_list(Head * h);

#endif