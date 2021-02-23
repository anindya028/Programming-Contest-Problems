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

int adj[105][105];

struct tripplet
{
	int a,b,c;
}t[1000005];

int main()
{
	int i,j,k,n,cnt;
	while(scanf("%d",&n)==1)
	{
		cnt=0;
		Fore(i,1,n)
			Fore(j,1,n)
				scanf("%d",&adj[i][j]);
		Fore(i,1,n)
			Fore(j,1,n)
			{
				if(i==j)
					continue;
				Fore(k,1,n)
				{
					if(k==i || k==j)
						continue;
					if(i<j && j<k && adj[i][j] && adj[j][k] && adj[k][i])
						t[cnt].a=i,t[cnt].b=j,t[cnt].c=k,cnt++;
					if(i>j && j>k && adj[i][j] && adj[j][k] && adj[k][i])
						t[cnt].a=i,t[cnt].b=j,t[cnt].c=k,cnt++;
					if(i<j && j<k && !adj[i][j] && !adj[j][i] && !adj[j][k] && !adj[k][j] && !adj[k][i] && !adj[i][k])
						t[cnt].a=i,t[cnt].b=j,t[cnt].c=k,cnt++;
				}
			}
		printf("%d\n",cnt);
		Foro(i,cnt)
			printf("%d %d %d\n",t[i].a,t[i].b,t[i].c);
	}
	return 0;
}
