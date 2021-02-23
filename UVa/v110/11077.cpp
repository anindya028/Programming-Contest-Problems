#include<stdio.h>
#include<stdlib.h>
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
#define mem(a) memset(a,0,sizeof(a))
#define LL unsigned long long

LL dp[25][25];

LL make(int n,int k)
{
	if(!k)
		return 1;
	if(n==k)
		return 0;
	if(dp[n][k])
		return dp[n][k];
	dp[n][k]=(n-1)*make(n-1,k-1)+make(n-1,k);
	return dp[n][k];
}

int main()
{
	int n,k;
	mem(dp);
	while(scanf("%d%d",&n,&k)==2 && n)
		printf("%llu\n",make(n,k));
	return 0;
}
