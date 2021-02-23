#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 210000000
int main()
{
	int mat[105][105],i,j,k,flag,t,n,l,m;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=inf;
		for(i=1;i<n;i++)
			for(j=1;j<=i;j++)
			{
				scanf("%d",&mat[i+1][j]);
				mat[j][i+1]=mat[i+1][j];
			}
		for(k=flag=1;k<=n && flag;k++)
			for(i=1;i<=n && flag;i++)
				for(j=1;j<=n && flag;j++)
				{
					if(mat[i][j]>(mat[i][k]+mat[k][j]) && i!=k && k!=j && mat[i][j]!=inf)
						flag=0;
					else if(k!=i && k!=j && mat[i][j]==(mat[i][k]+mat[k][j]))
						mat[i][j]=mat[j][i]=inf;
				}
		printf("Case #%d:\n",l+1);
		if(!flag)
		{
			printf("Need better measurements.\n\n");
			continue;
		}
		m=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(mat[i][j]!=inf)
					m++;
		printf("%d\n",m);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(mat[i][j]!=inf)
					printf("%d %d %d\n",i,j,mat[i][j]);
		printf("\n");
	}
	return 0;
}













