#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

int dp[30][35],adj[30][2],is[30];

int make(int pos,int rem)
{
	if(is[pos] && !rem)
		return 1;
	if(!rem)
		return 0;
	if(dp[pos][rem]!=-1)
		return dp[pos][rem];
	dp[pos][rem]=make(adj[pos][0],rem-1)+make(adj[pos][1],rem-1);
	return dp[pos][rem];
}

int main()
{
	int n,m,i;
	char s[5],u[5],v[5],c[5];
	while(scanf("%d",&n)==1)
	{
		mem(dp,-1),mem(is,0);
		for(i=0;i<n;i++)
			scanf("%s%s%s%s",s,u,v,c),
			adj[s[0]-'A'][0]=u[0]-'A',
			adj[s[0]-'A'][1]=v[0]-'A',
			is[s[0]-'A']= c[0]=='x';
		scanf("%d",&m);
		printf("%d\n",make(0,m));
	}
	return 0;
}
