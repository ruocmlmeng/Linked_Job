

#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//无序插入
	//Node * f = create_List();
	//Print_List(f);
	
	//有序插入
	Node * f2 = create_order_List();
	Print_List(f2);
	ElemType d;
	scanf("%d",&d);
	f2 = Delete_All_X(f2, d);
	Print_List(f2);
	destory_List(f2);
	return 0;
}
