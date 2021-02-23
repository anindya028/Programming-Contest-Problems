#include<stdio.h>
#include<algorithm>

using namespace std;

#define pii pair<int,int>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))

pii job[1005];

bool comp(pii a,pii b)
{
	int t1= Max(a.first + a.second , a.first + b.first + b.second);
	int t2= Max(b.first + b.second , b.first + a.first + a.second);
	return t1<t2;
}

int main()
{
	int n,i,b,j,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&b,&j),job[i]=make_pair(b,j);
		
		sort(job,job+n,comp);
		
		int ans=job[0].first+job[0].second,cum=job[0].first;
		for(i=1;i<n;i++)
		{
			cum+=job[i].first;
			ans=Max(ans,cum+job[i].second);
		}
		
		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}
