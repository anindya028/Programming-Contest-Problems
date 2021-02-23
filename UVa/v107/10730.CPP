#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int x[10000],y[10000];

int main()
{
	int i,j,k,n,flag;
	while(scanf("%d:",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			y[x[i]]=i;
		}
		for(i=0,flag=1;i<n && flag;i++)
			for(j=i+1;j<n;j++)
			{
				k=2*x[j]-x[i];
				if(k<0 || k>=n)continue;
				if(y[k]>j)
					flag=0;
			}
		if(!flag)printf("no\n");
		else printf("yes\n");
	}

	return 0;
}













