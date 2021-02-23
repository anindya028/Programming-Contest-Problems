#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 100000000
#define max(a,b)  ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
int main()
{
	int mat[105][105],i,j,k,sum,c1,c2,m,count,cs=0;
	while(scanf("%d%d",&c1,&c2)==2)
	{
		if(!c1 && !c2)break;
		for(i=1;i<105;i++)
			for(j=1;j<105;j++)
				mat[i][j]=inf;
		mat[c1][c2]=1;
		m=max(c1,c2);
		while(scanf("%d%d",&c1,&c2)==2)
		{
			if(!c1 && !c2)break;
			mat[c1][c2]=1;
			if(max(c1,c2)>m)
				m=max(c1,c2);
		}
		for(k=1;k<=m;k++)
			for(i=1;i<=m;i++)
				for(j=1;j<=m;j++)
					mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
		count=sum=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				if(mat[i][j]<inf && i!=j)
				{
					count++;
					sum+=mat[i][j];
				}
		printf("Case %d: average length between pages = %.3lf clicks\n",++cs,(double)sum/(double)count);
	}
	return 0;
}













