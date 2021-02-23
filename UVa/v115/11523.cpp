
#include<stdio.h>
#include<string>
#include<map>
using namespace std;

#define inf 1e9
#define Min(a,b) (((a)<(b))?(a):(b))

int dp[105][105],given[105];

int make(int st,int nd)
{
	if(st>=nd)
		return 0;
	int k;
	if(dp[st][nd]!=-1)
		return dp[st][nd];
	dp[st][nd]=inf;
	for(k=st;k<nd;k++)
		if(given[k]==given[st])
			dp[st][nd]=Min(dp[st][nd],Min(1+make(st+1,nd),make(st+1,k)+make(k,nd)));
	return dp[st][nd];
}

int main()
{
	char s[100];
	string ss;
	map<string,int> mp;
	int i,j,n,t,cs,k,ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		mp.clear();
		scanf("%d",&n);
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s),ss=s;
			if(s[0]<92)
			{
				given[i]=-1;
				continue;
			}
			if(mp.find(ss)!=mp.end())
				given[i]=mp[ss];
			else
			{
				mp[ss]=k;
				given[i]=k;
				k++;
			}
		}
		for(i=0;i<n+1;i++)
			for(j=0;j<n+1;j++)
				dp[i][j]=-1;
		if(given[0]==-1)
			i=1;
		else
			i=0;
		given[n]=-1;
		for(ans=0;i<n;)
		{
			for(j=i;j<=n;j++)
			{
				if(given[j]==-1)
				{
					ans+=make(i,j);
					i=j+1;
					break;
				}
			}
		}
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}