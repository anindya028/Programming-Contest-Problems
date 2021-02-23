//Greedy Graph
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

bool comp(int a,int b)
{
	return a>b;
}

int main()
{
	int d[1005],n,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<n;i++)
		{
			sort(d+i+1,d+n,comp);
			for(j=i+1;j<n && d[i];j++)
				d[i]--,d[j]--;
		}
		for(i=0;i<n;i++)
			if(d[i])
				break;
		if(i==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
