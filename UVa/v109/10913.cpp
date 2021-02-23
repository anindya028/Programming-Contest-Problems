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
#define inf 1<<30
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int given[77][77],dp[77][77][6][3],n,k;

bool valid(int r,int c)
{
	return (r>=0 && c>=0 && r<n && c<n);
}

int make(int r,int c,int neg,int dir)
{
	if(!r && !c)
		if(given[r][c]>=0 || neg)
			return given[r][c];
		else
			return -inf;
	if(!valid(r,c))
		return -inf;
	if(given[r][c]<0 && !neg)
		return -inf;
	if(given[r][c]<0)
		neg--;
	if(dp[r][c][neg][dir]!=-inf)
		return dp[r][c][neg][dir];
	int mn=given[r][c];
	
	if(!dir)
		mn+=Max(make(r-1,c,neg,0),Max(make(r,c-1,neg,1),make(r,c+1,neg,2)));
	else if(dir==1)
		mn+=Max(make(r-1,c,neg,0),make(r,c-1,neg,1));
	else
		mn+=Max(make(r-1,c,neg,0),make(r,c+1,neg,2));
	dp[r][c][neg][dir]=mn;
	return dp[r][c][neg][dir];
}

int main()
{
	int i,j,l,cs=0,sum;
	//freopen("10913.txt","w",stdout);
	while(scanf("%d%d",&n,&k)==2 && n)
	{
		sum=0;
		Foro(i,n)
			Foro(j,n)
			{
				scanf("%d",&given[i][j]);
				if(given[i][j]<0)
					sum+=given[i][j];
				Foro(l,k+1)
					dp[i][j][l][0]=dp[i][j][l][1]=dp[i][j][l][2]=-inf;
			}
		l=make(n-1,n-1,k,0);
		if(l<sum)
			printf("Case %d: impossible\n",++cs);
		else
			printf("Case %d: %d\n",++cs,l);
	}
	return 0;
}
