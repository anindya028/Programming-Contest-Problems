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

#define SIZE 15005
int ways[SIZE];
vector<int> adj[SIZE];

int main()
{
	int i,n,p,cs=0,j,u,ans;
	while(scanf("%d",&n)==1)
	{
		if(cs)
			printf("\n");
		cs++;
		Foro(i,n)
		{
			adj[i].clear(),ways[i]=0;
			scanf("%d",&p);
			Foro(j,p)
				scanf("%d",&u),adj[i].pb(u);
		}
		ways[0]=1;
		Foro(i,n)
			Forc(j,adj[i])
				ways[adj[i][j]]+=ways[i];
		ans=0;
		Foro(i,n)
			if(!SZ(adj[i]))
				ans+=ways[i];
		printf("%d\n",ans);
	}
	return 0;
}
