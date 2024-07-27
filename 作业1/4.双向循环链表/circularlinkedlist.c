

#include "circularlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
/*

	create_Link:创建数据结点,将头结点指向数据节点
	返回值:
		头结点的指针
*/
Head * create_Link()
{
	
	
	ElemType d;
	Head * h =create_Head();
	while(1)
	{
		scanf("%d",&d);
		if(d == 0)
		{
			break;
		}
		BiNode * p = malloc(sizeof(BiNode));
		p->data = d;
		p->next = NULL;
		p->prev = NULL;
		add_Node(h, p);
	}
	return h;
}


/*
	create_Head: 创建头结点
	返回值:
		头结点的指针
*/
Head * create_Head(void)
{
	Head * h = malloc(sizeof(Head));
	h->first = NULL;
	h->last = NULL;
	h->num = 0;
	return h;
}

/*
	add_Node:添加数据域结点
	@h:头结点的指针
	@p:添加的结点
	返回值:
		无
*/
void add_Node(Head * h,BiNode * p)
{
	if(h == NULL || p == NULL)
	{
		return ;
	}

	//如果链表中没有数据结点,则p将作为第一个也是最后一个
	if(h->first == NULL)
	{
		h->first = p;
		h->last = p;
		p->next = p;
		h->last->next = h->first;
		h->first->prev =h->last;
		h->num++;
		return ;
	}

	//然后插入的结点就是,头插,尾插,中间插
	BiNode * pk = h->first;
	ElemType flag = 0; // 0代表尾插 1代表头插
	do
	{
		if(pk->data > p->data)
		{
			flag = 1;
			break;
		}
		pk = pk->next;
	}while(pk!=h->first);
	//当pk指向头结点的指向相同时候,这里面就分为头插和尾插
	if(pk == h->first)
	{
		//头插
		if(flag == 1)
		{
			p->next =pk;
			pk->prev = p;
			h->first = p;
		}
		else // 尾插
		{
			h->last->next = p;
			p->prev = h->last;
			h->last = p;
		}
		h->last->next = h->first;
		h->first->prev = h->last;

	}
	else //中间插
	{
		p->next = pk;
		p->prev = pk->prev; 
		pk->prev->next = p;
		pk->prev = p;

	}
	h->num++;
	return ;
}

/*
	Print_Link : 打印数据域结点
	@h:头结点指针
	返回值:
		无
	
*/
void Print_Link(Head * h)
{
	if(h == NULL)
	{
		printf("No Find Link\n");
		return ;
	}

	if(h->first == NULL)
	{
		printf("No Find Node\n");
	}
	printf("数据域结点的个数为:%d\n",h->num);
	BiNode * p = h->first;
	do
	{
		printf("%d->",p->data);
		p = p->next;
	}while(p!=h->first);
	printf("NULL \n");
}
/*
	Delete_X:删除数据域为X的结点
	@h:头结点指针
	@p:要删除的数
	返回值:
		无
*/
void Delete_X(Head * h,ElemType x)
{
	if(h == NULL || h->first == NULL)
	{
		return ;
	}

	BiNode * px = h->first;
	ElemType flag = 0;// 0 没找到 1 找到了
	do
	{
		if(px->data == x)
		{
			flag = 1;
			break;
		}
		px = px->next;
	}while(px!=h->first);

	//没找到
	if(flag == 0)
	{
		return ;
	}

	if(px == h->first)
	{
		if(h->first == h->last)
		{
			h->first=h->last =NULL;
			px->next = px->prev = NULL;
		}
		else
		{
			h->first = px->next;
			px->prev = NULL;
			h->first->prev = h->last;
			h->last->next =h->first;
		}
			
	}
	else if(px == h->last)
	{
		h->last = px->prev;
		px->prev = NULL;
		h->last->next = h->first;
		h->first->prev = h->last;
	}
	else
	{
		px->prev->next = px->next;
		px->next->prev = px->prev;
		px->prev = NULL;
		px->next = NULL;
		
	}
	
	h->num--;
	return ;
}

/*
	Delete_All_X:删除数据域为x的所有结点
	@h:头结点指针
	返回值:
		无
*/
void Delete_All_X(Head * h,ElemType x)
{

	if(h == NULL || h->first == NULL)
		{
			return ;
		}
	
	BiNode * px = h->first;
	BiNode * ps = h->first;
	ElemType flag = 0;// 0 没找到 1 找到了
	while(1)
	{
		px = ps;
		flag = 0;
		do
		{
			if(px->data == x)
			{
				flag = 1;
				break;
			}
			px = px->next;
		}while(px!=h->first);
	
		//没找到
		if(flag == 0)
		{
			return ;
		}
		ps = px->next;
		if(px == h->first)
		{
			if(h->first == h->last)
			{
				h->first=h->last =NULL;
				px->next = px->prev = NULL;
			}
			else
			{
				h->first = px->next;
				px->prev = NULL;
				h->first->prev = h->last;
				h->last->next =h->first;
			}
				
		}
		else if(px == h->last)
		{
			h->last = px->prev;
			px->prev = NULL;
			h->last->next = h->first;
			h->first->prev = h->last;
		}
		else
		{
			px->prev->next = px->next;
			px->next->prev = px->prev;
			px->prev = NULL;
			px->next = NULL;
			
		}
		
		h->num--;



	}

}

/*
	destory_Link: 销毁双向循环链表的数据域结点
	@h:头结点的指针
	返回值:
		无
*/
void destory_Link(Head * h)
{
	BiNode * px = h->last;
	//先将结点一个一个摘下来,再释放
	while(px)
	{
		h->last = h->last->prev;
		if(h->last)
		{
			h->last->next = NULL;
		}
		else
		{
			h->first = NULL;
		}
		//将这个结点断开
		px->prev = NULL;
	}
	

}
