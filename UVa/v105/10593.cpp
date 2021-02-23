//good iterative dp
#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))

char s[505][505];

struct memo
{
	int left,up,sq;
	int dia;
}dp[505][505];

int main()
{
	int n,i,j,ans;
	while(scanf("%d",&n)==1)
	{

		for(i=0;i<n;i++)
			scanf("%s",s[i]);

		for(i=0;i<n+2;i++)
			for(j=0;j<n+2;j++)
				dp[i][j].dia=dp[i][j].left=dp[i][j].sq=dp[i][j].up=0;

		dp[0][0].left=dp[0][0].up=dp[0][0].sq=dp[0][0].dia=(s[0][0]=='x');
		for(i=1;i<n;i++)
		{
			if(s[0][i]=='x')
				dp[0][i].left=dp[0][i-1].left+1,dp[0][i].sq=dp[0][i].dia=dp[0][i].up=1;
			else
				dp[0][i].left=dp[0][i].sq=dp[0][i].up=dp[0][i].dia=0;
			if(s[i][0]=='x')
				dp[i][0].up=dp[i-1][0].up+1,dp[i][0].sq=dp[i][0].left=dp[i][0].dia=1;
			else
				dp[i][0].up=dp[i][0].sq=dp[i][0].left=dp[i][0].dia=0;
			if(s[i][1]=='x')
				dp[i][1].dia=1;
			else
				dp[i][1].dia=0;
		}
		if(s[0][1]=='x')
			dp[0][1].dia=1;
		else
			dp[0][1].dia=0;

		ans=0;
		//square counting begins
		for(i=1;i<n;i++)
			for(j=1;j<n;j++)
				if(s[i][j]=='x')
				{
					dp[i][j].left=dp[i][j-1].left+1;
					dp[i][j].up=dp[i-1][j].up+1;
					dp[i][j].sq=Min(dp[i-1][j-1].sq,Min(dp[i][j-1].left,dp[i-1][j].up))+1;
					ans+=dp[i][j].sq-1;
				}
				else
					dp[i][j].sq=dp[i][j].left=dp[i][j].up=0;
		//square counting ends

		//diamond counting begins
		for(j=2;j<n;j++)
			for(i=1;i<n;i++)
				if(s[i][j]=='x')
				{
					dp[i][j].dia=Min(dp[i-1][j-1].dia,Min(dp[i][j-1].dia,dp[i+1][j-1].dia));
					dp[i][j].dia=Min(dp[i][j].dia,dp[i][j-1].left/2);
					ans+=dp[i][j].dia;
					dp[i][j].dia++;
				}
				else
					dp[i][j].dia=0;
		//diamond counting ends
		printf("%d\n",ans);
	}
	return 0;
}