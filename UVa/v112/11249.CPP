#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int *lose,i,j,k,t,a,b,q;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d%d",&k,&q);
		lose=(int *)calloc(100005,sizeof(int));
		lose[1]=1+k+1;
		lose[lose[1]]=1;
		a=1;
		for(i=2;i<100005;i++)
		{
			if(lose[i])continue;
			lose[i]=lose[a]+(i-a)+k+1;
			if(lose[i]<100005)lose[lose[i]]=i;
			a=i;
		}
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&a,&b);
			if(lose[a]==b)printf("LOSING\n");
			else printf("WINNING\n");
		}
		printf("\n");
		free(lose);
	}
	return 0;
}













