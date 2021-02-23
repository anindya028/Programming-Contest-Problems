#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int is[1005],dp[12][12][1005];
vector<int> denom;

void make(int pos,int rem,int sum)
{
	is[sum]=1;
	if(pos==denom.size())
		return;
	if(dp[pos][rem][sum]!=-1)
		return; 
	dp[pos][rem][sum]=0;
	int i;
	for(i=0;i<=rem;i++)
		make(pos+1,rem-i,sum+i*denom[pos]);
}

int main()
{
	int s,i,j,k,p,mx,n,l;
	vector<int> ff;
	while(scanf("%d",&s)==1 && s)
	{
		scanf("%d",&n);
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p);
			denom.clear();
			for(j=0;j<p;j++)
				scanf("%d",&k),denom.push_back(k);
			sort(denom.begin(),denom.end());
			mem(dp,-1);
			mem(is,0);
			make(0,s,0);
			for(j=0;is[j];j++);
			if(j-1>mx || (j-1==mx && (denom.size()<ff.size() || (denom.size()==ff.size() && denom[l-1]<ff[l-1]) )) )
				mx=j-1,ff=denom,l=ff.size();
		}
		printf("max coverage = %3d :",mx);
		for(i=0;i<ff.size();i++)
			printf("%3d",ff[i]);
		printf("\n");
	}
	return 0;
}
