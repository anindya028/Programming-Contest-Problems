//DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int t[10005][105];
#define myabs(a) ((a>0)?(a):-(a))
int main()
{
	int m,n,i,j,k,num[10005],a;
	scanf("%d",&m);
	for(a=0;a<m;a++)
	{
		scanf("%d%d",&n,&k);
		for(j=1;j<=n;j++)
			scanf("%d",&num[j]);
		for(i=1;i<=n;i++)
			for(j=0;j<=k;j++)
				t[i][j]=0;
		j=myabs(num[1])%k;
		t[1][j]=1;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(t[i-1][j])
				{
					t[i][(j+myabs(num[i])%k)%k]=1;
					t[i][(j+k-myabs(num[i])%k)%k]=1;
				}
			}
		}
		if(t[n][0])printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}













