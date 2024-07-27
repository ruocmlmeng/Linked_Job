
#ifndef __Linklist_H__
#define __Linklist_H__

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}Node;

//创建一个无序链表
Node * create_List(void);

//创建一个有序的链表
Node * create_order_List(void);

//将结点有序的插入单链表中
Node*  Insert_Node(Node * f,Node * p);

//删除数据域为X的一个结点
Node * Delete_X(Node * f,ElemType x);

//删除所有数据域为x的结点
Node * Delete_All_X(Node * f,ElemType x);

void destory_List(Node * f);


//打印创建的链表
void Print_List(Node * p);


#endif
