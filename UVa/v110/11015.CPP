//FW
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define inf 10000000
#define min(a,b) ((a<b)?(a):(b))
int main()
{
	int mat[50][50],i,j,k,sum,min,minc,n,m,c,cs=0;
	char s[50][50];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			scanf("%s",s[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				mat[i][j]=inf;
			mat[i][i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&j,&k,&c);
			mat[j][k]=mat[k][j]=min(c,mat[j][k]);
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(mat[i][k]+mat[k][j]<mat[i][j])
						mat[i][j]=mat[j][i]=mat[i][k]+mat[k][j];
		for(i=1,min=inf;i<=n;i++)
		{
			sum=0;
			for(j=1;j<=n;j++)
				sum+=mat[i][j];
			if(sum<min)
			{
				min=sum;
				minc=i;
			}
		}
		printf("Case #%d : %s\n",++cs,s[minc]);
	}
	return 0;
}













