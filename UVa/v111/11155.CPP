#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
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

#define Size 10005
int seq[Size],cum[Size],prev[Size],cnt[Size];

int main()
{
	int i,n,m,a,b,c,t,cs,ans;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&m,&n);
		seq[0]=a;
		cum[0]=a;
		memset(prev,-1,sizeof(prev));
		if(!(a%m))
		{
			prev[0]=0;
			cnt[0]=1;
		}
		else
		{
			prev[seq[0]%m]=1;
			cnt[0]=0;
		}
		For(i,1,n)
		{
			seq[i]=(seq[i-1]*b+c)%m+1;
			cum[i]=cum[i-1]+seq[i];
			if(!(cum[i]%m))
			{
				if(prev[0]!=-1)
					cnt[i]=cnt[prev[0]]+1;
				else
					cnt[i]=1;
				prev[0]=i;
			}
			else
			{
				if(prev[cum[i]%m]!=-1)
					cnt[i]=cnt[prev[cum[i]%m]]+1;
				else
					cnt[i]=0;
				prev[cum[i]%m]=i;
			}
		}
		ans=0;
		For(i,0,n)
			ans+=cnt[i];
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}
