#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max 15
#define inf 210000000
int main()
{
	int mat[Max][Max];
	int parent[Max][Max];
	int cur[Max];
	int i,j,k,n,e,w,s,t,cs=0;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&e);
			for(j=0;j<e;j++)
			{
				scanf("%d%d",&k,&w);
				mat[i][k]=w;
				parent[i][k]=i;
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
					{
						mat[i][j]=mat[i][k]+mat[k][j];
						parent[i][j]=parent[k][j];
					}
				}
		scanf("%d%d",&s,&t);
		j=t;
		cur[0]=t;
		for(i=1;parent[s][j]!=s;i++)
		{
			cur[i]=parent[s][j];
			j=cur[i];
		}
		cur[i]=s;
		printf("Case %d: Path =",++cs);
		for(j=i;j>=0;j--)
			printf(" %d",cur[j]);
		printf("; %d second delay\n",mat[s][t]);
	}
	return 0;
}













