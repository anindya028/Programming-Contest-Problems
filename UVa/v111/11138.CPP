//Matching
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define M 505
#define N 505
list<int> adj[M];
bool seen[N];
int matchL[M],matchR[N];

bool bpm(int u)
{
	list<int>::iterator it;
	for(it=adj[u].begin();it!=adj[u].end();it++)
	{
		if(seen[*it])continue;
		seen[*it]=true;
		
		if(matchR[*it]<0 || bpm(matchR[*it]))
		{
			matchR[*it]=u;
			return true;
		}
	}
	return false;
}


int main()
{
	register int i,j,k;
	int cs,t,m,n,cnt;
	scanf("%d",&cs);
	for(k=0;k<cs;k++)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
		{
			adj[i].clear();
			for(j=0;j<n;j++)
			{
				scanf("%d",&t);
				if(t)
					adj[i].push_back(j);
			}
		}
		for(i=0;i<n;i++)
			matchR[i]=-1;
		for(i=cnt=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				seen[j]=false;
			if(bpm(i))cnt++;
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",k+1,cnt);
	}
	return 0;
}













