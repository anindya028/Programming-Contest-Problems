#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int n,m,num[1005];

bool possible(int lim)
{
	int i,now=0,mon=1;
	for(i=0;i<n;i++)
		if(now+num[i]<=lim)
			now+=num[i];
		else
			now=num[i],mon++;
	if(mon<=m)
		return true;
	return false;
}

int main()
{
	int i,lo,hi,mid;
	while(scanf("%d%d",&n,&m)==2)
	{
		lo=0,hi=0;
		Foro(i,n)
			scanf("%d",&num[i]),lo=Max(lo,num[i]),hi+=num[i];
		if(m>=n)
		{
			printf("%d\n",lo);
			continue;
		}
		while((hi-lo)>3)
		{
			mid=(lo+hi)/2;
			if(possible(mid))
				hi=mid;
			else
				lo=mid;
		}
		for(i=lo;i<=hi;i++)
			if(possible(i))
			{
				lo=i;
				break;
			}
		printf("%d\n",lo);
	}
	return 0;
}