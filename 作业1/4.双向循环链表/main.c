#include "circularlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Head *h = create_Link();
	Print_Link(h);
	ElemType d;
	scanf("%d",&d);
	Delete_All_X(h,d);
	Print_Link(h);
	destory_Link(h);

	return 0;
}

