#include<stdio.h>
#include<string.h>

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29
#define mem(a,b) memset(a,b,sizeof(a))

int p[35],n,m,now;
int dp[102][32];

int make(int pos,int w)
{
	if(!now || pos>=n)
		return 0;
	if(w>=m)
		return inf;
	if(dp[pos][w]!=-1)
		return dp[pos][w];
	dp[pos][w]=make(pos,w+1);
	int v=inf;
	if(p[w]>=now)
		v=p[w]+make(pos+p[w]/now,w+1);
	dp[pos][w]=Min(dp[pos][w],v);
	return dp[pos][w];
}

int main()
{
	int i,j,l;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		l=-1;
		for(i=0;i<m;i++)
			scanf("%d",&p[i]),l=Max(l,p[i]);
		for(j=l;;j--)
		{
			mem(dp,-1);
			now=j;
			i=make(0,0);
			if(i!=inf)
				break;
		}
		printf("%d %d\n",now,i);
	}
	return 0;
}