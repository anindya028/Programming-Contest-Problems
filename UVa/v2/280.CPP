#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 10000000
int main()
{
	int mat[105][105],i,j,k,n,m,c[105],node[105][105];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=inf;
		while(scanf("%d",&i)==1 &&  i)
		{
			while(scanf("%d",&j)==1 && j)
				mat[i][j]=1;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(mat[i][k]+mat[k][j]<mat[i][j])
						mat[i][j]=mat[i][k]+mat[k][j];
		for(i=1;i<=n;i++)
		{
			c[i]=0;
			for(j=1,k=0;j<=n;j++)
				if(mat[i][j]>=inf)
				{
					c[i]++;
					node[i][k]=j;
					k++;
				}
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&k);
			printf("%d",c[k]);
			for(j=0;j<c[k];j++)
				printf(" %d",node[k][j]);
			printf("\n");
		}
	}
	return 0;
}













