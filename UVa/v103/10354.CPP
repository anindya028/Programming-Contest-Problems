//FW Tricky
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 210000000
int main()
{
	int mat[105][105],node[105],Mat[105][105];
	int i,j,k,n,r,bh,of,yh,m,d;
	while(scanf("%d%d%d%d%d%d",&n,&r,&bh,&of,&yh,&m)==6)
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				mat[i][j]=Mat[i][j]=inf;
			mat[i][i]=Mat[i][i]=0;
		}
		for(i=0;i<=n;i++)node[i]=1;
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&j,&k,&d);
			mat[j][k]=mat[k][j]=d;
			Mat[j][k]=Mat[k][j]=d;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if((mat[i][k]+mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=mat[i][k]+mat[k][j];
				}
		for(i=1;i<=n;i++)
			if((mat[bh][i]+mat[i][of])==mat[bh][of])
				node[i]=0;
		node[bh]=node[of]=0;
		for(k=1;k<=n;k++)
			if(node[k])
			for(i=1;i<=n;i++)
				if(node[i])
				for(j=1;j<=n;j++)
					if(node[j])
				{
					if((Mat[i][k]+Mat[k][j])<Mat[i][j])
						Mat[i][j]=Mat[j][i]=Mat[i][k]+Mat[k][j];
				}
		if(Mat[yh][m]>=inf || !node[yh] || !node[m] || bh==m || of==m || bh==yh || of==yh )printf("MISSION IMPOSSIBLE.\n");
		else printf("%d\n",Mat[yh][m]);
	}
	return 0;
}













