//Adhoc
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

int num[20005];

bool comp(int a,int b )
{
	return a>b;
}

int main()
{
	
	int n,i,sum,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n,comp);
		for(sum=0,i=2;i<n;i+=3)
			sum+=num[i];
		printf("%d\n",sum);
	}
	return 0;
}
