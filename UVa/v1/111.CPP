#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define max 100
int rank[max],r[max],n;
int lcs_len(void)
{
	int c[max][max]={0},b[max][max]={0};
	register int i,j;
	for(i=2;i<=n+1;i++)
	{
		for(j=2;j<=n+1;j++)
		{
			if(rank[i-1]==r[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else c[i][j]=c[i][j-1];
		}
	}
		return c[n+1][n+1];

}
int main()
{
	int i,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		rank[temp]=i;
	}
	while(scanf("%d",&temp)==1)
	{
		r[temp]=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&temp);
			r[temp]=i+1;
		}
		printf("%d\n",lcs_len());
	}
	return 0;
}













