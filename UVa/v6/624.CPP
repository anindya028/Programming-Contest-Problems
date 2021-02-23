#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int c,n,cd[50],i,j,sum,max,t;
	while(scanf("%d%d",&c,&n)==2)
	{
		for(i=0;i<n;i++)
			scanf("%d",&cd[i]);
		max=0;
		for(i=1;i<=(1<<n);i++)
		{
			for(j=sum=0;j<n;j++)
				if(i & 1<<j)
				{
					sum+=cd[j];
				}
			if(sum>max && sum<=c)
			{
				max=sum;
				t=i;
			}
		}
		for(j=0;j<n;j++)
			if(t & 1<<j)
				printf("%d ",cd[j]);
		printf("sum:%d\n",max);
	}
	return 0;
}













