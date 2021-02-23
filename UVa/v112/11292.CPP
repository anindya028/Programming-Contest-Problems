#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	int d[20005],h[20005],i,j,sum,n,m,count;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)break;
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<m;i++)
			scanf("%d",&h[i]);
		sort(d,d+n);
		sort(h,h+m);
		for(i=j=sum=count=0;i<m && j<n;i++)
		{
			if(h[i]<d[j])continue;
			else
			{
				j++;
				count++;
				sum+=h[i];
			}
		}
		if(count==n)printf("%d\n",sum);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}













