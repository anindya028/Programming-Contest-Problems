#include<stdio.h>

#define inf 1<<30
#define Min(a,b) (((a)<(b))?(a):(b))

int mn[20005],coin[105],n;

int main()
{
	int i,t,p,ans,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&p,&n);
		for(i=0;i<n;i++)
			scanf("%d",&coin[i]);
		for(i=1;i<20005;i++)
			mn[i]=inf;
		mn[0]=0;
		for(i=0;i<n;i++)
			for(j=20000;j>=0;j--)
				if(mn[j]!=inf)
					if(j+coin[i]<=20000)
						mn[j+coin[i]]=Min(mn[j]+1,mn[j+coin[i]]);
		for(i=p;i<=20000;i++)
			if(mn[i]!=inf)
			{
				ans=i;
				break;
			}
		printf("%d %d\n",ans,mn[ans]);
	}
	return 0;
}