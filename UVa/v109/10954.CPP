#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int num,n,i,a,b,sum,cost;
	priority_queue<int> p;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=cost=0;i<n;i++)
		{
			scanf("%d",&num);
			p.push(-num);
		}
		while(1)
		{
			a=p.top();
			p.pop();
			b=p.top();
			p.pop();
			sum=a+b;
			cost+=(-sum);
			if(p.empty())
				break;
			p.push(sum);
		}
		printf("%d\n",cost);
	}
	return 0;
}













