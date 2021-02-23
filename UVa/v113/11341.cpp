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

int dp[15][105],l[15][105],n;

int make(int cor,int rem)
{
	int i,ret=-inf,got;
	if(rem<=0)
		return -inf;
	if(cor==(n-1))
		return l[cor][rem-1];
	if(dp[cor][rem]!=-inf)
		return dp[cor][rem];
	for(i=1;i<=(rem-(n-cor-1));i++)
		got=l[cor][i-1]+make(cor+1,rem-i),ret=Max(ret,got);
	dp[cor][rem]=ret;
	return dp[cor][rem];
}

int main()
{
	int m,i,j,t,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		Foro(i,n)
			Foro(j,m)
			{
				scanf("%d",&l[i][j]);
				if(l[i][j]<5)
					l[i][j]=-inf;
			}
		Foro(i,n+3)
			Foro(j,m+3)
				dp[i][j]=-inf;
		
		ans=make(0,m);
		if(ans<0)
			printf("Peter, you shouldn't have played billiard that much.\n");
		else
			printf("Maximal possible average mark - %.2lf.\n",(double)(ans)/(double)(n)+eps);
	}
	return 0;
}