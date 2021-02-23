#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1000000000
int main()
{
	int mat[252][252][2],i,j,k,q,n,m,d,t,cs,l;
	scanf("%d",&cs);
	for(l=0;l<cs;l++)
	{
		if(l)printf("\n");
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				mat[i][j][0]=mat[i][j][1]=inf;
			mat[i][i][0]=mat[i][i][1]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&j,&k,&t,&d);
			if(t<mat[j][k][0] || (mat[j][k][0]==t && d<mat[j][k][1]))
			{
				mat[j][k][0]=mat[k][j][0]=t;
				mat[j][k][1]=mat[k][j][1]=d;
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					t=mat[i][k][0]+mat[k][j][0];
					d=mat[i][k][1]+mat[k][j][1];
					if(t<mat[i][j][0] || (t==mat[i][j][0] && d<mat[i][j][1]))
					{
						mat[i][j][0]=mat[j][i][0]=t;
						mat[i][j][1]=mat[j][i][1]=d;
					}
				}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&j,&k);
			if(mat[j][k][0]==inf)printf("No Path.\n");
			else printf("Distance and time to reach destination is %d & %d.\n",mat[j][k][1],mat[j][k][0]);
		}
	}
	return 0;
}













