//Matching
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define M 105
#define N 105
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
	int a[M],b[N],cs,cnt,m,n;
	scanf("%d",&cs);
	for(k=0;k<cs;k++)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<m;i++)
		{
			adj[i].clear();
			for(j=0;j<n;j++)
				if(!b[j])
					adj[i].push_back(j);
				else if(a[i] && b[j]%a[i]==0)
					adj[i].push_back(j);
		}
		for(i=0;i<n;i++)
			matchR[i]=-1;
		cnt=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				seen[j]=false;
			if(bpm(i))
				cnt++;
		}
		printf("Case %d: %d\n",k+1,cnt);
	}
	return 0;
}













