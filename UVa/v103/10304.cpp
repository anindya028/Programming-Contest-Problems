#include<stdio.h>

#define sz 255

int f[sz],cum[sz];
int dp[sz][sz],mid[sz][sz];

int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&f[i]);
			if(!i) cum[i] = f[i];
			else cum[i] = cum[i-1] + f[i];
		}
		
		for(k=1;k<=n;k++)
		{
			for(i=0;i+k<=n;i++)
			{
				int L = i, R = i+k-1;
				if(k<2)
				{
					dp[L][R] = 0;
					mid[L][R] = i;
					continue;
				}
				
				int st = mid[L][R-1], nd = mid[L+1][R];
				dp[L][R] = 1<<29;
				for(j=st;j<=nd;j++)
				{
					int a = j? (L ? cum[j-1] - cum[L-1] : cum[j-1]) : 0;
					int b = cum[R] - cum[j];
					int c = (j? dp[L][j-1] : 0) + (j+1>R? 0 : dp[j+1][R]) + a + b;
					
					if(c < dp[L][R])
					{
						dp[L][R] = c;
						mid[L][R] = j;
					}
				}

			//	printf("%d %d %d\n",L,R,dp[L][R]);
			}
		}

		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
