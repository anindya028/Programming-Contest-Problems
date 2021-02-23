#include<stdio.h>
#include<algorithm>

using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))

pair<int,int> g[10];
int n;

bool check(double val)
{
	int i;
	double prev = g[0].first;
	for(i=1;i<n;i++)
	{
		if(prev+val-1e-6>g[i].second)
			return false;
		prev = Max(prev+val,g[i].first);
	}
	return true;
}

bool ok(double val)
{
	sort(g,g+n);
	do
	{
		if(check(val))
			return true;
	}while(next_permutation(g,g+n));
	return false;
}

int main()
{
	int i,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&g[i].first,&g[i].second),
			g[i].first *= 60, g[i].second *= 60;
		
		double lo = 0.0, hi = 1440*60.0 + 5.0,mid;
		while(hi-lo>1e-3)
		{
			mid = (lo+hi)/2;

			if(ok(mid))
				lo=mid;
			else
				hi=mid;
		}
		//printf("%lf\n",mid);
		int ans = (int)(mid+0.5);
		printf("Case %d: %d:%.2d\n",++cs,ans/60,ans%60);
	}
	return 0;
}