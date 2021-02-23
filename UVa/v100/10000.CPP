//Floyd-Warshall Longest Path
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max 105
#define inf 21000000
int main()
{
	int mat[Max][Max];
	int n,s,t,cs=0;
	register int i,j,k;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		scanf("%d",&s);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=-inf;
			//why? !
		while(scanf("%d%d",&i,&j)==2 && i && j)
			mat[i][j]=1;
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])>mat[i][j])
						mat[i][j]=mat[i][k]+mat[k][j];
				}
		for(i=1,j=0;i<=n;i++)
		{
			if(mat[s][i]>j)
			{
				j=mat[s][i];
				t=i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cs,s,j,t);
	}
	return 0;
}













