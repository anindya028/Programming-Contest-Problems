#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int n,num[18];
int dp[1<<17];

bool comp(int a,int b)
{
	return a>b;
}

int make(int state)
{
	if(state==((1<<n)-1))
		return 0;
	if(dp[state]!=-1)
		return dp[state];
	int i,j,k,temp;
	Foro(i,n)
		if(!(state & 1<<i))
			break;
	For(j,i+1,n)
		if(!(state & 1<<j))
			For(k,j+1,n)
				if(!(state & 1<<k))
					temp=make(state | 1<<i | 1<<j | 1<<k)+((num[i]+num[j]+num[k])>=20),
					dp[state]=Max(dp[state],temp);
	return dp[state];
}

int main()
{
	int i,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n)
			scanf("%d",&num[i]);
		sort(num,num+n,comp);
		n-=(n%3);
		Foro(i,1<<n)
			dp[i]=-1;
		printf("Case %d: %d\n",++cs,make(0));
	}
	return 0;
}