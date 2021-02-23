#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define LL long long
#define mem(a) memset(a,-1,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))

LL dp[1005][1005][2],inf;
int n,m,c;
typedef pair<int,int> pii;
pii pack[1005],box[1005];

bool comp(pii a,pii b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a.first>b.first;
}

LL make(int now,int pos,int is)
{
	if(pos==n)
		return 0;
	if(now==m)
		return inf;
	if(dp[now][pos][is]!=-1)
		return dp[now][pos][is];
	dp[now][pos][is]=inf;
	LL k;

	if(pack[now].first>=box[pos].first)
		k=pack[now].second*box[pos].second + c*(!is) + make(now,pos+1,1),
		dp[now][pos][is]=Min(dp[now][pos][is],k);
	
	k=make(now+1,pos,0);
	dp[now][pos][is]=Min(dp[now][pos][is],k);

	return dp[now][pos][is];
}

int main()
{
	int i,cs=0;
	LL ans;
	inf=1000000;
	inf*=inf;
	while(scanf("%d%d%d",&c,&m,&n)==3 && n)
	{
		mem(dp);
		for(i=0;i<m;i++)
			scanf("%d%d",&pack[i].first,&pack[i].second);
		for(i=0;i<n;i++)
			scanf("%d%d",&box[i].first,&box[i].second);
		sort(pack,pack+m,comp);
		sort(box,box+n,comp);
		ans=make(0,0,0);				
		if(ans==inf)
			printf("case %d: not possible\n",++cs);
		else
			printf("case %d: %lld\n",++cs,ans);
	}
	return 0;
}
