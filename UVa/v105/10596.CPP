#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
	int deg[205],i,flag,u,v,n,r;
	while(scanf("%d%d",&n,&r)==2)
	{
		for(i=0;i<n;i++)
			deg[i]=0;
		for(i=0;i<r;i++)
		{
			scanf("%d%d",&u,&v);
			deg[u]++;
			deg[v]++;
		}
		flag=1;
		for(i=0;i<n;i++)
			if(deg[i]%2 || deg[i]==0)
			{
				flag=0;
				break;
			}
		if(flag)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}
	return 0;
}

