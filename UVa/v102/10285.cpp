#include<stdio.h>
#include<string.h>

#define Max(a,b) (((a)>(b))?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))

int r,c,dp[105][105],s[105][105],mat[105][105];

bool isval(int i,int j)
{
	if(i<0 || i>=r || j<0 || j>=c || s[i][j])
		return 0;
	return 1;
}

int make(int i,int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	s[i][j]=1;
	int k=0;
	if(isval(i+1,j) && mat[i][j]>mat[i+1][j])
		k=make(i+1,j);
	if(isval(i-1,j) && mat[i][j]>mat[i-1][j])
		k=Max(k,make(i-1,j));
	if(isval(i,j+1) && mat[i][j]>mat[i][j+1])
		k=Max(k,make(i,j+1));
	if(isval(i,j-1) && mat[i][j]>mat[i][j-1])
		k=Max(k,make(i,j-1));
	dp[i][j]=k+1;
	s[i][j]=0;
	return dp[i][j];
}

int main()
{
	int t,i,j,ans;
	char name[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d%d",name,&r,&c);
		mem(dp,-1);
		ans=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf("%d",&mat[i][j]);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				ans=Max(ans,make(i,j));
		printf("%s: %d\n",name,ans);
	}
	return 0;
}