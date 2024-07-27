

#ifndef __circularlinkedlist_H__
#define __circularlinkedlist_H__

typedef int ElemType;

typedef struct BiNode
{
	ElemType data;
	struct BiNode * next;
	struct BiNode * prev;
}BiNode;

typedef struct Head
{
	BiNode * first;
	BiNode * last;
	ElemType num;
}Head;

//创建链表
Head * create_Link();

//创建头结点
Head * create_Head(void);

//插入数据结点
void add_Node(Head * h,BiNode * p);

//删除数据域为x的结点
void Delete_X(Head * h,ElemType x);

//删除数据域为x的所有结点
void Delete_All_X(Head * h,ElemType x);


void destory_Link(Head * h);

//打印结点
void Print_Link(Head * h);
#endif