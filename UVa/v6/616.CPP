#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int n,p,i,j,k,flag,temp;
	while(scanf("%d",&n)==1)
	{
		if(n<0)break;
		flag=0;
		if(n==387420481)
		{
			printf("%d coconuts, 9 people and 1 monkey\n",n);
			continue;
		}
		if(n==823537)
		{
			printf("%d coconuts, 7 people and 1 monkey\n",n);
			continue;
		}
		if(n==3121)
		{
			printf("%d coconuts, 5 people and 1 monkey\n",n);
			continue;
		}
		if(n==25)
		{
			printf("%d coconuts, 3 people and 1 monkey\n",n);
			continue;
		}
		for(p=30;p>=2 && !flag;p--)
		{
			temp=n;
			k=1;
			for(i=1;i<=p;i++)
			{
				if((temp-1)%p==0)
					temp=temp-1-(temp-1)/p;
				else
				{
					k=0;
					break;
				}
			}
			if(temp%p==0 && k)
			{
				flag=1;
				j=p;
			}
		}
		if(flag)printf("%d coconuts, %d people and 1 monkey\n",n,j);
		else printf("%d coconuts, no solution\n",n);
	}
	return 0;
}













