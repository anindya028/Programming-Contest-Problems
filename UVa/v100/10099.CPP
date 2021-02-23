	#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max 105
#define inf 210000000
#define min(a,b) ((a<b)?a:b)
int main()
{
	int n,r,i,j,k,c1,c2,p,cs=0;
	int mat[Max][Max];
	while(scanf("%d%d",&n,&r)==2)
	{
		if(!n && !r)break;
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=-inf;
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&c1,&c2,&p);
			mat[c1][c2]=mat[c2][c1]=p;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(min(mat[i][k],mat[k][j])>mat[i][j])
						mat[i][j]=mat[j][i]=min(mat[i][k],mat[k][j]);
				}
		scanf("%d%d%d",&c1,&c2,&p);
		printf("Scenario #%d\n",++cs);
		if(p%(mat[c1][c2]-1)==0)printf("Minimum Number of Trips = %d\n\n",p/(mat[c1][c2]-1));
		else printf("Minimum Number of Trips = %d\n\n",p/(mat[c1][c2]-1)+1);
	}
	return 0;
}













