#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define max 105
long tow1[max],tow2[max],n1,n2;
int lcs_len(void)
{
	int c[max][max]={0},b[max][max]={0};
	register int i,j;
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			if(tow1[i-1]==tow2[j-1])
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
		return c[n1][n2];

}
int main()
{
	int i,cs=0;
	while(scanf("%ld%ld",&n1,&n2)==2 && (n1&&n2))
	{
		for(i=0;i<n1;i++)scanf("%ld",&tow1[i]);
		for(i=0;i<n2;i++)scanf("%ld",&tow2[i]);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++cs,lcs_len());
	}
	return 0;
}













