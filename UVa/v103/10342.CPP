//finding second shortest path->floyd-warshall
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1000000000
#define min(a,b) ((a<b)?(a):(b))
int main()
{
	int mat[105][105][2],i,j,k,n,r,q,c1,c2,cost,l,cs=0;
	while(scanf("%d%d",&n,&r)==2)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				mat[i][j][0]=mat[i][j][1]=inf;
			mat[i][i][0]=0;
		}
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&c1,&c2,&cost);
			mat[c1][c2][0]=mat[c2][c1][0]=cost;
		}
		for(l=0;l<2;l++)
			for(k=0;k<n;k++)
				for(i=0;i<n;i++)
					for(j=0;j<n;j++)
					{
						if(mat[i][k][0]+mat[k][j][0]<mat[i][j][0])
						{
							mat[i][j][1]=mat[j][i][1]=mat[i][j][0];
							mat[i][j][0]=mat[j][i][0]=mat[i][k][0]+mat[k][j][0];
						}
						if(mat[i][k][0]+mat[k][j][0]>mat[i][j][0])
							mat[i][j][1]=mat[j][i][1]=min(mat[i][j][1],mat[i][k][0]+mat[k][j][0]);
						mat[i][j][1]=mat[j][i][1]=min(mat[i][j][1],mat[i][k][0]+mat[k][j][1]);
						mat[i][j][1]=mat[j][i][1]=min(mat[i][j][1],mat[i][k][1]+mat[k][j][0]);
						mat[i][j][1]=mat[j][i][1]=min(mat[i][j][1],mat[i][k][1]+mat[k][j][1]);
					}
		scanf("%d",&q);
		printf("Set #%d\n",++cs);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&c1,&c2);
			if(c1>=n || c2>=n)printf("?\n");
			else if(mat[c1][c2][1]>=inf)printf("?\n");
			else printf("%d\n",mat[c1][c2][1]);
		}
	}
	return 0;
}













