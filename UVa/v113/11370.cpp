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

#define myabs(a) (((a)>0)?(a):-(a))
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

double dp[205][205],h[205],err[205][205];
int n;

double make(int now,int rem)
{
	register int i;
	double mn=inf,d;
	if(now==(n-1))
		return 0;
	if(!rem)
		return err[now-1][n-1];
	if(dp[now][rem]>-1.)
		return dp[now][rem];
	for(i=now;i+rem<n;++i)
		d=err[now-1][i]+make(i+1,rem-1),mn=Min(d,mn);
	dp[now][rem]=mn;
	return dp[now][rem];
}

int main()
{
	register int i,j,k;
	int c,cs;
	double sum;
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d%d",&n,&c);
		Foro(i,n)
			scanf("%lf",&h[i]);
		Foro(i,n)
			Foro(j,n)
				dp[i][j]=-1.3;
		Foro(i,n)
		{
			For(j,i+1,n)
			{
				sum=0;
				For(k,i+1,j)
					sum+=myabs( h[i] + ( (h[j]-h[i])*(k-i) ) / (j-i) - h[k]);
				err[i][j]=sum;
			}
			err[i][i]=0;
		}
		printf("%.4lf\n",make(1,c-2)/n);
	}
	return 0;
}