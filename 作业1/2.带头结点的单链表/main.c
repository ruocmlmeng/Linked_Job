

#include "LinklistwithHead.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{

	Head * h = create_Head();
	create_List(h);
	Print_list(h);
	ElemType d;
	scanf("%d",&d);
	Delete_All_X(h, d);
	Print_list(h);
	destory_List(h);
	return 0;
}

