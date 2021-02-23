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

double dp[1<<17];
int n,two[20];

struct point
{
	double x,y;
}p[20];

double dis(point a,point b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

double make(bool taken[])
{
	int i,st=0,j;
	double ret=inf,d;
	Foro(i,2*n)
		if(!taken[i])
			st+=two[i];
	if(dp[st] > -1.)
		return dp[st];
	for(i=0;i<2*n && taken[i];i++);
	taken[i]=true;
	for(j=i+1;j<2*n;j++)
		if(!taken[j])
		{
			taken[j]=true;
			d=dis(p[i],p[j])+make(taken);
			ret=Min(ret,d);
			taken[j]=false;
		}
	dp[st]=ret;
	taken[i]=false;
	return ret;
}
	
int main()
{
	int i,cs=0;
	bool taken[25];
	char s[25];
	two[0]=1;
	For(i,1,19)
		two[i]=two[i-1]*2;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,2*n)
			scanf("%s%lf%lf",s,&p[i].x,&p[i].y);
		For(i,1,1<<(2*n))
			dp[i]=-1.;
		dp[0]=0.;
		Foro(i,2*n)
			taken[i]=false;
		printf("Case %d: %.2lf\n",++cs,make(taken));
	}
	return 0;
}