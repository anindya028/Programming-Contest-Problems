//Greedy
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
	int n,d,r,i,sum,mor[105],eve[105];
	while(scanf("%d%d%d",&n,&d,&r)==3)
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&mor[i]);
		for(i=0;i<n;i++)
			scanf("%d",&eve[i]);
		sort(mor,mor+n);
		sort(eve,eve+n,comp);
		for(i=sum=0;i<n;i++)
			if((mor[i]+eve[i])>d)
				sum+=(mor[i]+eve[i]-d);
		printf("%d\n",sum*r);
	}
	return 0;
}
