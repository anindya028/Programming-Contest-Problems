#include<stdio.h>

int main()
{
	int n,i,j,ans,t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;++cs)
	{
		scanf("%d",&n);
		for(i=ans=0;i<n;i++)
		{
			scanf("%d",&j);
			if(j>ans)
				ans=j;
		}
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}