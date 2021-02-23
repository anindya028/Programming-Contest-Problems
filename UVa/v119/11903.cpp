#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))

int mat[15][15],n;
int dp[1<<14][14][14];

int make(int now,int prev,int rem)
{
	if(rem<0)
		return 0;
	if(now==((1<<n)-1))
		return !rem;
	if(dp[now][prev][rem]!=-1)
		return dp[now][prev][rem];
	dp[now][prev][rem]=0;
	int i,j;
	for(i=0;i<n;i++)
		if(!(now & 1<<i))
			j=make( now | 1<<i,i,rem-mat[i][prev]),
			dp[now][prev][rem]+=j;
	return dp[now][prev][rem];
}

int main()
{
	int i,t,cs,k,q,r,j,m,u;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&n,&k,&q);
		mem(mat,0);
		mem(dp,-1);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
				scanf("%d",&u),u--,mat[i][u]=1;
		}

		printf("Case %d:\n",cs+1);
		for(i=0;i<q;i++)
		{
			scanf("%d",&r);
			if(k)
				u=r/k;
			else
				u=n+1;
			int ans=0;
			for(j=0;j<=u && j<=n-1;j++)
				ans+=make(0,n,j);
			printf("%d\n",ans);
		}
	}
	return 0;
}