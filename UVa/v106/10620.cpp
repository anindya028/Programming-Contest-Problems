#include <stdio.h>
int main()
{
	int i, S, x, y, dx, dy;
    while (scanf("%d%d%d%d%d",&S,&x,&y,&dx,&dy)==5) 
    {
		if(!S) 
			return 0;
        for(i=0; i< 2000000 && (x%S == 0 || y%S == 0 || x%(2*S)/S == y%(2*S)/S); i++) 
		{
			x+= dx;
			y+= dy;
		}
		if (i < 2000000) 
			printf("After %d jumps the flea lands at (%d, %d).\n", i,x,y);
		else
			printf("The flea cannot escape from black squares.\n");
    }
   return 0;
}
