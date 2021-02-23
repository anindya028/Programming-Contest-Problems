#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1<<29
#define size 105
#define Min(a,b) (((a)<(b))?(a):(b))

int main()
{
	int mat[size][size],i,j,k,t,cs,u,v,n,m,c,found,f,flag,mx;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				mat[i][j]=mat[j][i]=inf;
			mat[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			mat[u][v]=mat[v][u]=Min(c,mat[u][v]);
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					mat[i][j]=mat[j][i]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		found=-1;
		for(i=1,f=0;i<=n;i++)
		{
			
			if(mat[i][1]==mat[i][2] && mat[i][2]==mat[i][3] && mat[i][3]==mat[i][4] && mat[i][4]==mat[i][5])
			{
				flag=1;
				mx=0;
				for(j=1;j<=n;j++)
				{
					if(mat[i][j]>=inf)
						flag=0;
					if(mat[i][j]>mx)
						mx=mat[i][j];
				}
				if(flag)
					if(found==-1 || (found>0 && mx<found))
						found=mx;
			}
		}
		printf("Map %d: %d\n",cs+1,found);
	}
	return 0;
}













