#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX(a,b) ((a>b)?a:b)
int main()
{
	int t,i,j,len,n,num,min,s,max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&len,&n);
		s=max=0;
		min=100000000;
		for(j=0;j<n;j++)
		{
			scanf("%d",&num);
			if(num<min)min=num;
			if(num>max)max=num;
			if(num<=(len/2))
			{
				if(num>s)
					s=num;
			}
			else
			{
				if((len-num)>s)
					s=len-num;
			}
		}
		printf("%d %d\n",s,MAX(len-min,max));
	}
	return 0;
}













