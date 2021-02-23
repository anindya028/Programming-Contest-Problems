#include<stdio.h>
#include<algorithm>
#include<set>

using namespace std;

#define LL long long
#define pll pair<LL,LL>

int dr[] = {1,0,1,1};
int dc[] = {0,1,1,-1};

set< pll > setc, setn;

pll p[100005];

int main()
{
	int t,cs,n,k,i,j,u;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		setc.clear();
		setn.clear();

		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&p[i].first,&p[i].second);
			if(i%2)
				setn.insert(p[i]);
			else
				setc.insert(p[i]);
		}
		
		int f1 = 0, f2 = 0;
	//cross
		for(i=0;i<n && !f1;i+=2)
			for(j=0;j<4;j++)
			{
				int cnt = 1;
				pll next = p[i];
				for(u=0;u<k;u++)
				{
					next.first += dr[j];
					next.second += dc[j];
					if(setc.find(next)!=setc.end())
						cnt++;
					else
						break;
				}
				
				next = p[i];
				for(u=0;u<k;u++)
				{
					next.first -= dr[j];
					next.second -= dc[j];
					if(setc.find(next)!=setc.end())
						cnt++;
					else
						break;
				}
				
				if(cnt>=k)
					f1 = 1;
			}
//		nought
		for(i=1;i<n && !f2;i+=2)
			for(j=0;j<4;j++)
			{
				int cnt = 1;
				pll next = p[i];
				for(u=0;u<k;u++)
				{
					next.first += dr[j];
					next.second += dc[j];
					if(setn.find(next)!=setn.end())
						cnt++;
					else
						break;
				}
				
				next = p[i];
				for(u=0;u<k;u++)
				{
					next.first -= dr[j];
					next.second -= dc[j];
					if(setn.find(next)!=setn.end())
						cnt++;
					else
						break;
				}
				
				if(cnt>=k)
					f2 = 1;
			}
		
		if(f1 && f2)
			printf("Case %d: error\n",cs);
		else if(f1)
			printf("Case %d: crosses\n",cs);
		else if(f2)
			printf("Case %d: noughts\n",cs);
		else
			printf("Case %d: none\n",cs);
	}
	return 0;
}