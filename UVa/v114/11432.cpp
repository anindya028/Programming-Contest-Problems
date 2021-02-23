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

#define Long long long
//#define Long __int64
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

Long memo[34][34][34][34][2];
int D,G;

Long make(int d1,int d2,int g1,int g2,int st)
{
	if(g1<0 || g2<0)
		return 0;
	if(g1==0 && g2==0)
		return 0;
	if((st==0 && !d1) || (st==1 && !d2))
		return 1;
	else if(!d1 || !d2)
		return 0;
	if(memo[d1][d2][g1][g2][st]!=-1)
		return memo[d1][d2][g1][g2][st];
	memo[d1][d2][g1][g2][st]=make(d1-1,d2,G,g2-1,st)+make(d1,d2-1,g1-1,G,st);
	return memo[d1][d2][g1][g2][st];
}

int main()
{
	int cs=0,i,j,k,l;
	Foro(i,34)
		Foro(j,34)
			Foro(k,34)
				Foro(l,34)
					memo[i][j][k][l][0]=memo[i][j][k][l][1]=-1;
	while(scanf("%d%d",&D,&G)==2)
	{
		if(D<0 || G<0)
			break;
		if(!D && !G)
		{
			printf("Case %d: 1\n",++cs);
			continue;
		}
		printf("Case %d: %lld\n",++cs,make(D-1,D,G,G-1,0)+make(D,D-1,G-1,G,1));
	}
	return 0;
}
