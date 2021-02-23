#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;

#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define myabs(a) (((a)>0)?(a):-(a))
#define mem(a) memset(a,-1,sizeof(a))

struct player
{
	int tt,deg,ind,ben;
}p[10005];

bool operator<(player a,player b)
{
	return a.tt<b.tt;
}

bool comp(player a,player b)
{
	return a.ind<b.ind;
}

int dp[10005][6][6][3],child[10005][6][6][3],n;

int make(int now,int a,int b,int prev)
{
	int f=prev,t;
	if(!now || p[now].tt!=p[now-1].tt)
		f=0;
	if(now==n)
		return myabs(a-1)*10+myabs(b-1)*10;
	if(dp[now][a][b][f]!=-1)
		return dp[now][a][b][f];
	dp[now][a][b][f]=1000000000;
	if(f!=1)
	{
		t=myabs(a-p[now].deg)*10+make(now+1,p[now].deg,b,1);
		if(t<dp[now][a][b][f])
			dp[now][a][b][f]=t,child[now][a][b][f]=1;
	}
	if(f!=2)
	{
		t=myabs(b-p[now].deg)*10+make(now+1,a,p[now].deg,2);
		if(t<dp[now][a][b][f])
			dp[now][a][b][f]=t,child[now][a][b][f]=2;
	}
	return dp[now][a][b][f];
}

int main()
{
	int t,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Foro(i,n)
			scanf("%d%d",&p[i].tt,&p[i].deg),p[i].deg/=10,p[i].ind=i;
		sort(p,p+n);
		mem(dp);
		ans=make(0,1,1,0)+n*15;
		printf("%d\n",ans);
		int now=0,a=1,b=1,prev=0,f;
		while(now<n)
		{
			f=prev;
			if(!now || p[now].tt!=p[now-1].tt)
				f=0;
			p[now].ben=prev=child[now][a][b][f];
			if(prev==1)
				a=p[now].deg;
			else
				b=p[now].deg;
			now++;
		}
		sort(p,p+n,comp);
		Foro(i,n)
			printf("%d\n",p[i].ben);
	}
	return 0;
}