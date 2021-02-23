#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,t,a,b,count,j,temp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		temp=n;
		count=0;
		for(j=2;(j*j)<=temp && count<2;j++)
		{
			if(temp%j==0)
			{
				if(!count)a=j;
				else b=j;
				count++;
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n",i+1,n,a,n/a,b,n/b);
	}
	return 0;
}













