#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;


#define M 105//number of pigeon
#define N 105//number of holes
list<int> adj[M];//adjacency list of the graph
bool seen[N];//which holes are engaged
int matchL[M],matchR[N];//matchL->which pigeon is in which hole,matchR->vice versa

struct point
{
	double x,y;
}gopher[M],hole[N];

#define eps 1e-10
#define myabs(a) (((a)>0)?(a):-(a))
inline double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool bpm(int u)
{
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		if(seen[*i])continue;
		seen[*i]=true;
		
		if(matchR[*i]<0 || bpm(matchR[*i]))//this is the dfs!!!!!!
		{
			matchL[u]=*i;
			matchR[*i]=u;
			return true;
		}
	}
	return false;
}

int main()
{
	register int i,j;
	int cnt,n,m;
	double s,v;
	while(scanf("%d%d%lf%lf",&m,&n,&s,&v)==4)
	{
		for(i=0;i<m;i++)
		{
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
			adj[i].clear();
		}
		for(i=0;i<n;i++)
			scanf("%lf%lf",&hole[i].x,&hole[i].y);
		//building the graph
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(dist(gopher[i],hole[j])<(v*s) || (dist(gopher[i],hole[j])-v*s)<eps)
					adj[i].push_back(j);
		
		//memset(matchL,-1,sizeof(matchL));
		//memset(matchR,-1,sizeof(matchR));
		for(i=0;i<n;i++)
			matchR[i]=-1;
		cnt=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				seen[j]=false;
			if( bpm(i) )cnt++;
		}
		printf("%d\n",m-cnt);
	}
	return 0;
}


