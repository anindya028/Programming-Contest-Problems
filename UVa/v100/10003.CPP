//DP O(n^3) MCM
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define min(a,b) ((a<b)?(a):(b))
#define inf 2000000000
int l,n,cut[70],cost[70][70];
int det(int i,int j)
{
	if(!i && j==n)
		return l;
	else if(!i)
		return cut[j];
	else if(j==n)
		return l-cut[i-1];
	else return cut[j]-cut[i-1];
}
int find(int i,int j)
{
	int k,m=inf;
	if(i>j || j<i)
		return 0;
	if(cost[i][j]<inf)
		return cost[i][j];
	if(i==j)
	{
		if(j!=n)cost[i][j]=det(i,j);
		else cost[i][j]=0;
		return cost[i][j];
	}
	for(k=i;k<j;k++)
	{
		cost[k][k]=0;
		m=min(m,(find(i,k)+find(k+1,j)+det(i,j)));
		cost[k][k]=inf;
	}
	cost[i][j]=m;
	return cost[i][j];
}
int main()
{
	int i,j;
	while(scanf("%d",&l)==1)
	{
		if(!l)break;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				cost[i][j]=inf;
		for(i=0;i<n;i++)
			scanf("%d",&cut[i]);
		printf("The minimum cutting is %d.\n",find(0,n));
	}
	return 0;
}













