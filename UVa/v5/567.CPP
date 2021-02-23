#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 21000000
int mat[25][25];
int main()
{
	int i,j,k,x,n,cs=0;
	while(scanf("%d",&x)==1)
	{
		for(i=0;i<24;i++)
			for(j=0;j<24;j++)
				mat[i][j]=inf;
		for(i=0;i<x;i++)
		{
			scanf("%d",&k);
			mat[1][k]=mat[k][1]=1;
		}
		for(i=2;i<20;i++)
		{
			scanf("%d",&x);
			for(j=0;j<x;j++)
			{
				scanf("%d",&k);
				mat[i][k]=mat[k][i]=1;
			}
		}
		for(k=1;k<=20;k++)
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=mat[i][k]+mat[k][j];
				}
		scanf("%d",&n);
		printf("Test Set #%d\n",++cs);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			printf("%2d to %2d: %d\n",j,k,mat[j][k]);
		}
		printf("\n");
	}
	return 0;
}













