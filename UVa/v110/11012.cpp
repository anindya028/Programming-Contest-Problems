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

struct point
{
	int x,y,z;
}p[100005];

int main()
{
	int cs,t,n,i,ans,mx,mn;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d",&n);
		Foro(i,n)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		mx=0,mn=inf,ans=0;
		Foro(i,n)
			mx=Max(mx,p[i].x+p[i].y+p[i].z),mn=Min(mn,p[i].x+p[i].y+p[i].z);
		ans=Max(ans,mx-mn);
		mx=0,mn=inf;
		Foro(i,n)
			mx=Max(mx,p[i].x-p[i].y-p[i].z),mn=Min(mn,p[i].x-p[i].y-p[i].z);
		ans=Max(ans,mx-mn);
		mx=0,mn=inf;
		Foro(i,n)
			mx=Max(mx,p[i].x-p[i].y+p[i].z),mn=Min(mn,p[i].x-p[i].y+p[i].z);
		ans=Max(ans,mx-mn);
		mx=0,mn=inf;
		Foro(i,n)
			mx=Max(mx,p[i].x+p[i].y-p[i].z),mn=Min(mn,p[i].x+p[i].y-p[i].z);
		ans=Max(ans,mx-mn);
		printf("Case #%d: %d\n",cs+1,ans);
	}
	return 0;
}
