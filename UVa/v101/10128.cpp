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

int dp[15][15][15];

int make(int n,int p,int q)
{
	if((p+q-1)>n || !p || !q)
		return 0;
	if((p+q-1)==n && (p==1||q==1))
		return 1;
	if(dp[n][p][q]!=-1)
		return dp[n][p][q];
	dp[n][p][q]=make(n-1,p,q)*(n-2)+make(n-1,p-1,q)+make(n-1,p,q-1);
	return dp[n][p][q];
}

int main()
{
	int i,j,k,n,cs,t,p,q;
	Foro(i,14)
		Foro(j,14)
			Foro(k,14)
				dp[i][j][k]=-1;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d%d",&n,&p,&q);
		printf("%d\n",make(n,p,q));
	}
	return 0;
}