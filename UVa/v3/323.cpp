#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define myabs(a) (((a)>0)?(a):-(a))
#define mem(a,b) memset(a,b,sizeof(a))

int n,m,dd[205],pp[205],parent[203][23][823],dp[203][23][823];

int main() 
{
	int i,j,cs=0,k,dif,sum;
	vector<int> ans;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=1;i<=n;i++)
			scanf("%d%d",&pp[i],&dd[i]);
		
		ans.clear();
		mem(dp,-1),mem(parent,-1);
		dp[0][0][400]=0;

		for(i=1;i<=n;i++)
			for(j=0;j<i && j<=m;j++)
				for(k=0;k<=800;k++)
					if(dp[i-1][j][k]>=0)
					{
						dif=k;
						dif+=(dd[i]-pp[i]);
						
						if(dp[i-1][j][k]>=dp[i][j][k])
						{
							dp[i][j][k]=dp[i-1][j][k],parent[i][j][k]=0;
			//				printf(">>%d %d %d %d\n",i,j,k,dp[i][j][k]);
						}

						if(dp[i-1][j][k]+pp[i]+dd[i]>=dp[i][j+1][dif])
						{
							dp[i][j+1][dif]=dp[i-1][j][k]+pp[i]+dd[i],parent[i][j+1][dif]=1;
			//				printf(">>>%d %d %d %d\n",i,j+1,dif,dp[i][j+1][dif]);
						}
					}
		
		dif=100000,sum=0;
		for(k=0;k<=800;k++)
			if(dp[n][m][k]!=-1)
				if(myabs(k-400)<dif || (myabs(k-400)==dif && dp[n][m][k]>sum))
					dif=myabs(k-400),j=k,sum=dp[n][m][k];
		
		printf("Jury #%d\n",++cs);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(sum-(j-400))/2,(sum+(j-400))/2);
		
		k=j;
		i=n,j=m;
		while(i)
		{
			if(parent[i][j][k])
			{
				ans.push_back(i);
				j--;
				k-=(dd[i]-pp[i]);
			}
			i--;
		}
		for(i=ans.size()-1;i>=0;i--)
			printf(" %d",ans[i]);
		printf("\n\n");
	}
	return 0;
}