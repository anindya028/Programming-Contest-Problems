#include<stdio.h>
#include<stdlib.h>
#include<math.h>
union{
   long data;
   char bit[4];
}x, y;
int main()
{
	while(scanf("%ld", &x.data)==1)
	{

   // swap 0th and 3rd bytes
   y.bit[3]=x.bit[0];
   y.bit[0]=x.bit[3];

   // swap 1st and 2nd bytes
   y.bit[1]=x.bit[2];
   y.bit[2]=x.bit[1];

   printf("%ld converts to %ld\n", x.data, y.data);
	}
	return 0;
}













