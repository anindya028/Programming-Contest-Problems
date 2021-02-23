#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define inf 10000000
#define min(a,b) ((a<b)?(a):(b))
int main()
{
	int mat[50][50],node[50],i,j,k,n,m,s,t,ps,pt,cs=0,count;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<=35;i++)
		{
			for(j=0;j<=35;j++)
				mat[i][j]=inf;
			mat[i][i]=0;
		}
		for(i=m=0;i<n;i++)
		{
			scanf("%d%d",&s,&t);
			ps=pt=-1;
			for(j=0;j<m;j++)
				if(node[j]==s)
				{
					ps=j;
					break;
				}
			if(ps<0)
			{
				node[m]=s;
				ps=m;
				m++;
			}
			for(j=0;j<m;j++)
				if(node[j]==t)
				{
					pt=j;
					break;
				}
			if(pt<0)
			{
				node[m]=t;
				pt=m;
				m++;
			}
			if(ps!=pt)mat[ps][pt]=mat[pt][ps]=1;
		}
		for(k=0;k<m;k++)
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
					mat[i][j]=min(mat[i][k]+mat[k][j],mat[i][j]);
		while(scanf("%d%d",&s,&t)==2)
		{
			if(!s && !t)break;
			for(j=0;j<m;j++)
				if(node[j]==s)
				{
					ps=j;
					break;
				}
			for(j=count=0;j<m;j++)
				if(mat[ps][j]>t)
					count++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cs,count,s,t);
		}
	}
	return 0;
}













