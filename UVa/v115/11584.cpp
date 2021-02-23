#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Min(a,b) (((a)<(b))?(a):(b))
#define mem(a) memset(a,-1,sizeof(a))

int n;
char s[1005];
int pal[1005][1005],dp[1005];

int ispal(int st,int nd)
{
	if(st>=nd)
		return 1;
	if(pal[st][nd]!=-1)
		return pal[st][nd];
	if(s[st]==s[nd])
		pal[st][nd]=ispal(st+1,nd-1);
	else
		pal[st][nd]=0;
	return pal[st][nd];
}

int make(int pos)
{
	int i,j;
	if(pos==n)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	dp[pos]=100000;
	if(ispal(pos,n-1))
		dp[pos]=1;
	for(i=pos;i<n;i++)
		if(ispal(pos,i))
			j=1+make(i+1),dp[pos]=Min(dp[pos],j);
	return dp[pos];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s),n=strlen(s);
		mem(pal);
		mem(dp);
		printf("%d\n",make(0));
	}
	return 0;
}