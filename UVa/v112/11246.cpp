#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,sum,flag,t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&k);
		sum=n;
		flag=1;
		while(n)
		{
			if(flag)
			{
				sum-=n/=k;
				flag=0;
			}
			else
			{
				sum+=n/=k;
				flag=1;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}













