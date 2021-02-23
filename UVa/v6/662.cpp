#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
#define mem(a,b) memset(a,b,sizeof(a))
#define mab(a) (((a)>0)?(a):-(a))
#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))

pii cost[205][205],depo[205][35];
int n,rest[205],dp[205][35];

int make(int pos,int rem)
{
	if(pos==n)
		return 0;
	if(!rem)
		return inf;
	if(dp[pos][rem]!=-1)
		return dp[pos][rem];
	dp[pos][rem]=inf;
	int i,j;
	for(i=pos;i<n;i++)
	{
		j=cost[pos][i].first+make(i+1,rem-1);
		if(j<dp[pos][rem])
			dp[pos][rem]=j,depo[pos][rem].first=i,depo[pos][rem].second=cost[pos][i].second;
	}
	return dp[pos][rem];
}

int main()
{
	int i,j,k,p,ans,cs=0;
	while(scanf("%d%d",&n,&p)==2 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&rest[i]);
		sort(rest,rest+n);
		for(i=0;i<n;i++)
			for(j=i;j<n;j++)
			{
				int pos=i+(j-i+1)/2;
				int sum=0;
				for(k=i;k<=j;k++)
					sum+=mab(rest[pos]-rest[k]);
				cost[i][j].first=sum;
				cost[i][j].second=pos;
				pos--;
				sum=0;
				for(k=i;k<=j;k++)
					sum+=mab(rest[pos]-rest[k]);
				if(cost[i][j].first>sum)
					cost[i][j].first=sum,cost[i][j].second--;
			}
		mem(dp,-1);
		ans=make(0,p);
		printf("Chain %d\n",++cs);
		i=0,j=p,k=0;
		while(i<n)
		{
			if(depo[i][j].first==i)
				printf("Depot %d at restaurant %d serves restaurant %d\n",++k,i+1,i+1);
			else
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n",++k,depo[i][j].second+1,i+1,depo[i][j].first+1);
			i=depo[i][j].first+1;
			j--;
		}
		printf("Total distance sum = %d\n\n",ans);
	}
	return 0;
}