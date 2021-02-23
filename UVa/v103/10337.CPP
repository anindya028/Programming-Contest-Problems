//Classic DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
#define Min(a,b) (((a)<(b))?(a):(b))
#define inf 1<<28
int cost[1005][12],g[1005][12],x;

int make(int m,int n)
{
	if(m==x)
	{
		if(n==0)
			return 0;
		else
			return inf;
	}
	if(cost[m][n])
		return cost[m][n];
	if(n==0)
		cost[m][n]=Min(30-g[m][n]+make(m+1,n),60-g[m][n+1]+make(m+1,n+1));
	else if(n==9)
		cost[m][n]=Min(30-g[m][n]+make(m+1,n),20-g[m][n-1]+make(m+1,n-1));
	else 
		cost[m][n]=Min(Min(30-g[m][n]+make(m+1,n),60-g[m][n+1]+make(m+1,n+1)),20-g[m][n-1]+make(m+1,n-1));
	return cost[m][n];
}

int main()
{
	int i,j,t,cs;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		x/=100;
		for(i=0;i<x;i++)
			for(j=0;j<10;j++)
				cost[i][j]=0;
		for(j=9;j>=0;j--)
			for(i=x-1;i>=0;i--)
				scanf("%d",&g[i][j]);
		printf("%d\n\n",make(0,0));
	}
	return 0;
}

