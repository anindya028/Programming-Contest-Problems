#include<stdio.h>
#include<string.h>

#define LL long long 
#define mem(a) memset(a,-1,sizeof(a))
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)

LL dp[205][21][12],num[205],g[205],n,d;

LL make(LL pos,LL now,LL rem)
{
	if(!rem)
		return !now;
	if(pos==n)
		return 0;
	if(dp[pos][now][rem]!=-1)
		return dp[pos][now][rem];
	dp[pos][now][rem]=make(pos+1,now,rem)+make(pos+1,(now+g[pos])%d,rem-1);
	return dp[pos][now][rem];
}

int main()
{
	int q,i,j,cs=0,m;
	while(scanf("%lld%d",&n,&q)==2)
	{
		if(!n && !q)
			break;
		Foro(i,n)
			scanf("%lld",&num[i]);
		printf("SET %d:\n",++cs);
		Foro(j,q)
		{
			scanf("%lld%d",&d,&m);
			Foro(i,n)
				g[i]= num[i]>=0?(num[i]%d):(d-(-num[i])%d);
			mem(dp);
			printf("QUERY %d: %lld\n",j+1,make(0,0,m));
		}
	}
	return 0;
}