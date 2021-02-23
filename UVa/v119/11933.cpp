#include<stdio.h>

int main()
{
	int n,a,b,i;
	while(scanf("%d",&n)==1 && n)
	{
		a = b = 0;
		int ok=0;
		for(i=0;i<31;i++)
			if(n & 1<<i)
			{
				if(ok)
					b+=(1<<i);
				else
					a+=(1<<i);
				ok = 1-ok;
			}
		printf("%d %d\n",a,b);
	}
	return 0;
}