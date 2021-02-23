#include<stdio.h>

int main()
{
	int x,y,z,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&x,&y,&z);
		int now=x+y,d=0;
		while(now>=z)
		{
			d+=now/z;
			now=now/z+now%z;
		}
		printf("%d\n",d);
	}
	return 0;
}
