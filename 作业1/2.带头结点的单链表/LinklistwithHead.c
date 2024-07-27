
#include "LinklistwithHead.h"
#include <stdio.h>
#include <stdlib.h>

/*
	create_Head:创建一个头结点
	返回值:
		头结点的指针
*/
Head * create_Head(void)
{
	Head * h = malloc(sizeof(Head));
	h->first = NULL;
	h->last = NULL;
	h->num =0;
	return h;
}

/*
	create_List:创建链表
	@h:头结点的指针
	返回值:
	无
*/
void create_List(Head * h)
{
	ElemType d;
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
		add_Node(h,p);
	}

}
/*
	add_Node:往链表中添加结点
	@h:头结点的指针
	@p:待插入的链表
	返回值:
		无
*/
void add_Node(Head * h,Node * p)
{
	if(h == NULL || p==NULL)
	{
		return ;
	}
	//当链表没有结点的时候,插入第一个结点
	if(h->first == NULL)
	{
		h->first = p;
		h->last = p;
		h->num++;
		return ;
	}
	Node * pr = NULL;
	Node * pk = h->first;
	//printf("%d\n",__LINE__);
	while(pk)
	{
		if(pk->data > p->data)
		{
			break;
		}
		pr = pk;
		pk = pk->next;
	}



	if(pk == h->first)
	{
		p->next = h->first;
		h->first = p;	
	}
	else if(pr == h->last)
	{
		h->last->next = p;
		h->last = p;
	}
	else
	{
		pr->next = p;
		p->next = pk;
	}
	h->num++;
	return ;
	
}

void Delete_X(Head *h, ElemType x)
{
	if(h == NULL)
	{
		return ;
	}
	Node * pr = NULL;
	Node * px = h->first;
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
		return ;
	}

	if(px == h->first)
	{
		if(h->first == h->last)
		{
			h->first = NULL;
			h->last = NULL;
		}else
		{
			h->first =px->next;
			px->next = NULL;

		}
		free(px);
	}
	else if(px == h->last)
	{
		h->last = pr;
		pr->next = NULL;
		free(px);
	}
	else
	{
		pr->next = px->next;
		px->next = NULL;
		free(px);
	}
	h->num--;
	return ;

}

void Delete_All_X(Head * h,ElemType x)
{
	if(h == NULL)
	{
		return ;
	}
	Node * px = h->first;
	Node * ps = h->first;
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
			return ;
		}
		ps = px->next;
		if(px == h->first)
		{
			if(h->first == h->last)
			{
				h->last = NULL;
				h->first = NULL;
			}
			else
			{
				h->first = px->next;
				px->next = NULL;
				
			}
			free(px);
		}
		else if(px == h->last)
		{
			h->last = pr;
			pr->next =NULL;
			free(px);
		}
		else
		{
			pr->next = px->next;
			px->next = NULL;
			free(px);
		}
		h->num--;
		
	}
	return ;
}

void destory_List(Head * h)
{
	if(h == NULL)
	{
		return ;
	}
	Node * p = h->first;
	while(p)
	{
		h->first = p->next;
		p->next = NULL;
		p = h->first;
		if(h->first == h->last)
		{
			h->first = h->last = NULL;
		}
		free(p);
	}
	free(h);
	return ;

}

void Print_list(Head * h)
{
	if(h == NULL)
	{
		printf("No Find List\n");
		return ;
	}
	if(h->first == NULL)
	{
		printf("No Find Node\n");
	}
	printf("单链表中的结点个数为:%d\n",h->num);
	Node * p = h->first;
	while(p)
	{
		printf("%d-> ",p->data);
		p = p->next;
	}
	printf("NULL\n");
}
