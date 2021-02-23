#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max 105
#define inf 210000000
#define max(a,b) ((a>b)?a:b)
int main()
{
	int c,s,q,i,j,k,c1,c2,d,cs=0;
	int mat[Max][Max];
	while(scanf("%d%d%d",&c,&s,&q)==3)
	{
		if(!c && !s && !q)break;
		if(cs)printf("\n");
		for(i=0;i<=c;i++)
			for(j=0;j<=c;j++)
				mat[i][j]=inf;
		for(i=0;i<s;i++)
		{
			scanf("%d%d%d",&c1,&c2,&d);
			mat[c1][c2]=mat[c2][c1]=d;
		}
		for(k=1;k<=c;k++)
			for(i=1;i<=c;i++)
				for(j=1;j<=c;j++)
				{
					if(max(mat[i][k],mat[k][j])<mat[i][j])
						mat[i][j]=mat[j][i]=max(mat[i][k],mat[k][j]);
				}
		printf("Case #%d\n",++cs);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&c1,&c2);
			if(mat[c1][c2]==inf)printf("no path\n");
			else printf("%d\n",mat[c1][c2]);
		}
	}
	return 0;
}













