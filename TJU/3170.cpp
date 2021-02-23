#include<stdio.h>

int is[100005];

int main()
{
	int n,q,i,j,now,k;
	while(scanf("%d%d",&n,&q)==2)
	{
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&now);
			for(k=0;k<now;k++)
				is[j+k]=i+1;
			j+=now;
		}
		for(i=0;i<q;i++)
		{
			scanf("%d",&now);
			printf("%d\n",is[now]);
		}
	}
	return 0;
}