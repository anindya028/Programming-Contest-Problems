#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	int n,i,temp;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		if(n==1)
		{
			printf("Discarded cards:\nRemaining card: 1\n");
			continue;
		}
		for(i=1;i<=n;i++)
			q.push(i);
		printf("Discarded cards: 1");
		q.pop();
		for(i=2;i<n;i++)
		{
			temp=q.front();
			q.pop();
			printf(", %d",q.front());
			q.pop();
			q.push(temp);
		}
		printf("\nRemaining card: %d\n",q.front());
		q.pop();
	}
	return 0;
}













