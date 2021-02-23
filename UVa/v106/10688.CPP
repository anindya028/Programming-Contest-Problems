//MCM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define Min(a,b) (((a)<(b))?(a):(b))
#define inf 1<<29
#define size 505

int memo[size][size];

int make(int st,int end)
{
	int a,b; 
	register int i;
	if(st>=end)
		return 0;
	if(memo[st][end]<inf)
		return memo[st][end];
	for(i=st;i<=end;i++)
	{
		a=make(st,i-1);
		b=make(i+1,end);
		memo[st][end]=Min(memo[st][end],a+b+i*(end-st+1));
	}
	return memo[st][end];
}

int main()
{	
	int i,j,n,k,t,cs;
	for(i=0;i<size;++i)
		for(j=0;j<size;++j)
			memo[i][j]=inf;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&k);
		printf("Case %d: %d\n",cs+1,make(k+1,n+k));
	}
	return 0;
}
