
#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>

/*
	create_List: 创建一个无序链表
	返回值：
		第一个数据节点的指针
*/
Node * create_List(void)
{
	ElemType d;
	Node *f = NULL;
	while(1)
	{
		scanf("%d",&d);
		if(d == 0)
		{
			break;
		}
		Node * p = malloc(sizeof(Node));
		p->data = d;
		p->next = NULL;

		if(f == NULL)
		{
			f = p;
		}
		else
		{
			Node * l = f;
			while(l ->next)
			{
				l = l->next;
			}
			l->next = p;
		}
	}
	return f;

}

/*
	create_order_List:创建一个有序的单链表
	返回值：
		单链表第一个结点的指针
*/
Node * create_order_List(void)
{
	ElemType d;
	Node * f = NULL;//一直指向第一个结点的头指针
	while(1)
	{
		scanf("%d",&d);
		if(d == 0)
		{
			break;
		}
		Node * p = malloc(sizeof(Node));
		p->data = d;
		p->next = NULL;
		f = Insert_Node(f,p);
	}
	return f;
}

/*
	Insert_Node:将结点有序的插入单链表中
	@f:头结点的指针
	@p:待插入的结点
	返回值:
		第一个结点的指针
*/

Node*  Insert_Node(Node * f,Node * p)
{
	if(f == NULL)
	{
		//如果头指针指向的结点为空,就将p作为第一个结点
		return p;
	}
	if(p == NULL)
	{
		
		return f;
	}
	Node * pr = NULL;
	Node * pk = f;
	while(pk)
	{
		if(pk->data > p->data)
		{
			break;
		}
		pr = pk;
		pk = pk->next;
	}

	if(pk)
	{
		//头插
		if(pk == f)
		{
			p->next = f;
			f = p;
			
		}
		else // 中间插入
		{
				pr->next = p;
				p->next = pk;

		}
	}
	else//尾插
	{
		pr->next = p;

	}
	return f;
}

/*
	Delete_X:删除数据域为X的结点
	@f:头结点的指针
	@x:待删除的数据
	返回值:
		返回第一个结点指针
*/
Node* Delete_X(Node * f,ElemType x)
{
	if(f == NULL)
	{
		return f;
	}

	Node * pr = NULL;
	Node * px = f;
	while(px)
	{
		if(px->data == x)
		{
			break;
		}
		pr = px;
		px = px->next;
	}
	if(px == NULL)
	{
		//没找到
		return f;
	}
		

	//头删
	if(px == f)
	{
		f = f->next;
		px->next = NULL;
		free(px);
		return f;
	}
	else//中间删
	{
		pr->next = px->next;
		px->next = NULL;
		free(px);
		return f;
	}

	

}

/*
	Delete_All_X:删除所有数据域为x的结点
	@f:指向第一个结点的指针
	@x:要删除的那个数据域
	返回值:
		返回指向第一个结点的指针
*/
Node * Delete_All_X(Node * f,ElemType x)
{
	if(f == NULL)
	{
		return f;
	}
	Node * px = f;
	Node * ps = f;//记录指向要连续删除的下一个结点的指针
	Node * pr = NULL;
	while(1)
	{
		px = ps;
		while(px)
		{
			if(px->data == x)
			{
				break;
			}
			pr = px;
			px = px->next;
		}
		if(px == NULL)
		{
			return f;
		}
		ps = px->next;
		if(px == f)
		{
			f = f->next;
			px->next = NULL;
			free(px);
		}
		else
		{
			pr->next = px->next;
			px->next =NULL;
			free(px);
		}
	}
	return f;
}

/*
	destory_List:销毁链表
	@f:指向第一个结点的指针
	返回值
	无

*/
void destory_List(Node * f)
{
	if(f == NULL)
	{
		return ;
	}
	Node * px = f;
	while(px)
	{
		f = f->next;
		px->next = NULL;
		px = f;
		free(px);
	}
	free(f);
}

/*
	Print_List:打印链表
	@p:单链表的第一个结点的指针
	返回值：
		无
*/
void Print_List(Node * p)
{
	if(p == NULL)
	{
		printf("No Find list\n");
		return ;
	}
	while(p)
	{
		printf("%d-> ",p->data);
		p = p->next;
	}
	printf("NULL\n");

}
