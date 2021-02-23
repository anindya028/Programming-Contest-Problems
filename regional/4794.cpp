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

typedef pair<int,int> pii;

int n;
int a[20],mp[1<<16];
int dp[1<<16][105];

int make(int now,int x,int sum)
{
	int cnt=0,i,j,y=sum/x,b,c;
	for(i=0;i<n;i++)
		if(now & 1<<i)
			cnt++;
	if(cnt==1)
		return 1;
	if(dp[now][x]!=-1)
		return dp[now][x];
	dp[now][x]=0;
	for(i=now & (now-1);i;i=now & (i-1))
	{
		b=mp[i];
		c=sum-b;

		if(b%x==0 && b/x<y && (y-b/x)*x==c)
			dp[now][x]|= (make(i,x,b) & make(now-i,x,c));
		if(dp[now][x])
			return dp[now][x];
		if(b%y==0 && b/y<x && (x-b/y)*y==c)
			dp[now][x]|= (make(i,y,b) & make(now-i,y,c));
		if(dp[now][x])
			return dp[now][x];
	}
	return dp[now][x];
}

int main()
{
	int i,x,y,sum,cs=0,j;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%d%d",&x,&y);
		for(i=sum=0;i<n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		if(sum!=x*y)
		{
			printf("Case %d: No\n",++cs);
			continue;
		}
		mem(dp,-1);
	//	mem(mp,0);
		for(i=1;i<(1<<n);i++)
			for(j=mp[i]=0;j<n;j++)
				if(i & 1<<j)
					mp[i]+=a[j];
		if(make((1<<n)-1,x,sum))
			printf("Case %d: Yes\n",++cs);
		else
			printf("Case %d: No\n",++cs);
	}
	return 0;
}