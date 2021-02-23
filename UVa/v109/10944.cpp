#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define mem(a) memset(a,-1,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

int dp[1<<16][16],n;
int x[16],y[16];

int make(int now,int pos)
{
	if(now==((1<<n) -1))
		return Max(abs(x[pos]-x[0]),abs(y[pos]-y[0]));
	if(dp[now][pos]!=-1)
		return dp[now][pos];
	dp[now][pos]=100000000;
	int i,t;
	Foro(i,n)
		if(!(now & 1<<i))
		{
			t=Max(abs(x[pos]-x[i]),abs(y[pos]-y[i]));
			t+=make(now | 1<<i,i);
			dp[now][pos]=Min(dp[now][pos],t);
		}
	return dp[now][pos];
}

int main()
{
	int i,r,c,j;
	char s[20][20];
	while(scanf("%d%d",&r,&c)==2)
	{
		Foro(i,r)
			scanf("%s",s[i]);
		n=1;
		Foro(i,r)
			Foro(j,c)
				if(s[i][j]=='L')
					x[0]=i,y[0]=j;
				else if(s[i][j]=='#')
					x[n]=i,y[n]=j,n++;
		mem(dp);			
		printf("%d\n",make(1,0));
	}
	return 0;
}