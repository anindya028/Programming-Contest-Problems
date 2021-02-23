#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;

#define mod 10000007

map<int,int> dp[255];
int num[255];

int main()
{
	int t,n,i,j,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]),dp[i].clear();
		int ans=n;
		for(i=1;i<n;i++)
			for(j=0;j<i;j++)
			{
				int dif=num[i]-num[j];
				if(dp[i].find(dif)==dp[i].end())
				{
					if(dp[j].find(dif)==dp[j].end())
						dp[i][dif]=1,
						ans=(ans+1)%mod;
					else
						dp[i][dif]=(dp[j][dif]+1)%mod,
						ans=(ans+dp[j][dif]+1)%mod;
				}
				else
				{
					if(dp[j].find(dif)==dp[j].end())
						dp[i][dif]=(dp[i][dif]+1)%mod,
						ans=(ans+1)%mod;
					else
						dp[i][dif]=(dp[i][dif]+dp[j][dif]+1)%mod,
						ans=(ans+dp[j][dif]+1)%mod;
				}
			}
			printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}