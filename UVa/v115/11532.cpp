#include<stdio.h>
#include<algorithm>

using namespace std;

#define LL long long
#define pii pair<int,LL>

LL two[55];
pii dp[55][55][2][2];

pii make(int p,int q,int prev,int pr)
{
	if(!p && !q)
		return make_pair(0,0);
	if(dp[p][q][prev][pr].first!=-1)
		return dp[p][q][prev][pr];
	dp[p][q][prev][pr].first=-1;
	if(q)
	{
		dp[p][q][prev][pr]=make(p,q-1,0,prev);
		if(prev && pr)
			dp[p][q][prev][pr].first++;
	}
	if(p)
	{
		pii temp=make(p-1,q,1,prev);
		if(!prev)
			temp.first++;
		temp.second+=two[p+q-1];
		if(temp.first>dp[p][q][prev][pr].first)
			dp[p][q][prev][pr]=temp;
	}
	return dp[p][q][prev][pr];
}

int main()
{
	int t,p,q;
	int i;
	two[0]=1;
	for(i=1;i<=53;i++)
		two[i]=two[i-1]*2;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&p,&q);

		if(p+q==1)
		{
			if(p)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		memset(dp,-1,sizeof(dp));
		
		pii p1=make_pair(-1,0),p2=make_pair(-1,0);

		if(q)
			p1=make(p,q-1,0,0);
		if(p)
		{
			p2=make(p-1,q,1,1);
			p2.second+=two[p+q-1];
		}
		
		if(p1.first>=p2.first)
			printf("%lld\n",p1.second);
		else
			printf("%lld\n",p2.second);
	}
	return 0;
}