#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

int dp[55][55];

int make(int r,int c)
{
	if(!r && !c)
		return 0;
	if(dp[r][c]!=-1)
		return dp[r][c];
	set<int> now;
	int i,j;
	if(r>=1 && c>=1)
	{
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				now.insert( (make(i,c)^make(r,j)) );
	}
	else if(!c)
		for(i=0;i<r;i++)
			now.insert(make(i,c));
	else
		for(j=0;j<c;j++)
			now.insert(make(r,j));
	i=0;
	while(now.find(i)!=now.end())
		i++;
	dp[r][c]=i;
	return dp[r][c];
}

int main()
{
	int n,m,i,j,ans;
	char s[55][55];
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		ans=0;
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(i+j && s[i][j]=='#')
					ans=(ans ^ make(i,j));
		if(ans)
			printf("John\n");
		else
			printf("Jack\n");
	}
	return 0;
}