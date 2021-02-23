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

#define SIZE 205

vector<int> adj[SIZE];
int col[SIZE];

int bfs(int s)
{
	queue<int> q;
	int i,k,cnt1=0,cnt2=0;
	q.push(s);
	col[s]=1;
	cnt1=1;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		Forc(i,adj[k])
		{
			if(col[adj[k][i]] && col[adj[k][i]]==col[k])
				return -1;
			if(col[adj[k][i]])
				continue;
			if(col[k]==1)
				col[adj[k][i]]=2,cnt2++;
			else
				col[adj[k][i]]=1,cnt1++;
			q.push(adj[k][i]);
		}
	}
	if(!cnt2) return cnt1;
	return Min(cnt1,cnt2);
}

int main()
{
	int t,cs,i,v,e,p,q,tot;
	scanf("%d",&t);
	For(cs,0,t)
	{
		scanf("%d%d",&v,&e);
		tot=0;
		Foro(i,v)
			col[i]=0,adj[i].clear();
		Foro(i,e)
		{
			scanf("%d%d",&p,&q);
			adj[p].pb(q);
			adj[q].pb(p);
		}
		Foro(i,v)
		{
			if(!col[i])
			{
				p=bfs(i);
				if(p==-1)
				{
					tot=-1;
					break;
				}
				else
					tot+=p;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
