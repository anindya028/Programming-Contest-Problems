#include<stdio.h>

int main()
{
	int n,mon[12],need[12],now,i,cs=0;

	while(scanf("%d",&n)==1 && n>=0)
	{
		for(i=0;i<12;i++)
			scanf("%d",&mon[i]);
		for(i=0;i<12;i++)
			scanf("%d",&need[i]);
		now=n;
		printf("Case %d:\n",++cs);
		for(i=0;i<12;i++)
		{
			if(now>=need[i])
				printf("No problem! :D\n"),now-=need[i];
			else
				printf("No problem. :(\n");
			now+=mon[i];
		}
	}	
	return 0;
}