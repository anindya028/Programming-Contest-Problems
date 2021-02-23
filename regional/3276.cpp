#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define mabs(a) (((a)>0)?(a):-(a))

int sr[20],sc[20],tr[20],tc[20],n;

int dp[1<<16];

int dist(int a,int b,int c,int d)
{
	return mabs(a-c)+mabs(b-d);
}

int make(int now,int cnt)
{
	if(cnt==n)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	int i,j;
	dp[now]=1<<29;
	for(i=0;i<n;i++)
		if(!(now & 1<<i))
			j= dist(sr[cnt],sc[cnt],tr[i],tc[i]) + make(now | 1<<i,cnt+1),
			dp[now]=Min(dp[now],j);
	return dp[now];
}

int main()
{
	int i,j,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&sr[i],&sc[i]),sr[i]--,sc[i]--;
		int ans=1<<29;
		//row
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				tr[j]=i,tc[j]=j;
			mem(dp,-1);
			j=make(0,0);
			ans=Min(ans,j);
		}
		//col
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				tr[j]=j,tc[j]=i;
			mem(dp,-1);
			j=make(0,0);
			ans=Min(ans,j);
		}
		for(j=0;j<n;j++)
			tr[j]=tc[j]=j;
		mem(dp,-1);
		j=make(0,0);
		ans=Min(ans,j);
		for(j=0;j<n;j++)
			tr[j]=j,tc[j]=n-j-1;
		mem(dp,-1);
		j=make(0,0);
		ans=Min(ans,j);
		printf("Board %d: %d moves required.\n\n",++cs,ans);
	}
	return 0;
}