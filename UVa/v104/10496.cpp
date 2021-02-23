#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define mem(a) memset(a,-1,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))

int dp[1<<13][13],n;
int x[15],y[15];

int make(int now,int pos)
{
	if(now==((1<<n) -1))
		return (abs(x[pos]-x[0])+abs(y[pos]-y[0]));
	if(dp[now][pos]!=-1)
		return dp[now][pos];
	dp[now][pos]=100000000;
	int i,t;
	Foro(i,n)
		if(!(now & 1<<i))
		{
			t=abs(x[pos]-x[i])+abs(y[pos]-y[i]);
			t+=make(now | 1<<i,i);
			dp[now][pos]=Min(dp[now][pos],t);
		}
	return dp[now][pos];
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		n++;
		For(i,1,n)
			scanf("%d%d",&x[i],&y[i]);
		mem(dp);
		printf("The shortest path has length %d\n",make(1,0));
	}
	return 0;
}