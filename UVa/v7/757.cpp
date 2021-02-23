#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

int dp[200][30],parent[200][30],n,f[30],d[30],dist[30];

int make(int rem,int pos)
{
	if(pos==n || rem<=0)
		return 0;
	if(dp[rem][pos]!=-1)
		return dp[rem][pos];

	dp[rem][pos]=make(rem-dist[pos],pos+1);
	parent[rem][pos]=0;

	int i,j=0,now;
	for(i=1;i<=rem;i++)
	{
		now=f[pos]-d[pos]*(i-1);
		if(now>0)
			j+=now;
		now=j+make(rem-dist[pos]-i,pos+1);
		if(now>=dp[rem][pos])
			dp[rem][pos]=now,parent[rem][pos]=i;
	}
	return dp[rem][pos];
}

int main()
{
	int i,h,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		if(!n)
			break;
		if(cs)
			printf("\n");
		cs++;
		scanf("%d",&h);
		for(i=0;i<n;i++)
			scanf("%d",&f[i]);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		for(i=0;i<n-1;i++)
			scanf("%d",&dist[i]);
		dist[i]=0;
		mem(dp,-1),mem(parent,-1);
		int ans=make(h*12,0);
		int tt[30]={0};
		i=0,h*=12;
		while(i<n && h>0)
		{
			tt[i]=parent[h][i];
			h-=(parent[h][i]+dist[i]);
			i++;
		}
		printf("%d",tt[0]*5);
		for(i=1;i<n;i++)
			printf(", %d",tt[i]*5);
		printf("\nNumber of fish expected: %d\n",ans);
	}
	return 0;
}
