#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define M 105		//Number of gopher/pigeons
#define N 105		//Number of holes

struct point
{
	double x,y;
}gopher[M],hole[N];	// 0-indexing : (0) - (M-1), (0) - (N-1)

vector<int> adj[M];	//adjacency list for each gopher/pigeon
bool seen[N];		//visited array for dfs	
int matched[N];		//matched[i] = j denotes j-th gopher is in i-th hole

double dist2(int i, int j)
{
	return ( (gopher[i].x - hole[j].x)*(gopher[i].x - hole[j].x) + (gopher[i].y - hole[j].y)*(gopher[i].y - hole[j].y) );
}

bool dfs(int u)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(seen[v]) continue;
		seen[v] = true;

		if(matched[v]<0 || dfs(matched[v]))
		{
			matched[v] = u;
			return true;
		}
	}
	return false;
}

int bpm(int m,int n,double d)	// m - number of gopher (left), n - number of holes (right)
{
	int i,j;
	for(i=0;i<m;i++)			// making adjacency list
	{
		adj[i].clear();
		for(j=0;j<n;j++)
			if(dist2(i,j) < d*d + 1e-10)
				adj[i].push_back(j);
	}

	int count = 0;
	for(i=0;i<n;i++)			// initially all holes are free
		matched[i] = -1;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)		//initialization for dfs
			seen[j] = false;
		if(dfs(i))
			count++;
	}
	return count;
}

int main()
{
	int t,n,m,k,i,j;
	scanf("%d",&t);
	for(int cs = 0; cs < t ; cs++)
	{
		scanf("%d%d%d",&m,&n,&k);

		for(i=0;i<m;i++)
			scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&hole[i].x,&hole[i].y);

		double lo = 0, hi = 0, mid;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				double vv = dist2(i,j);
				if(vv > hi)
					hi = vv;
			}

		hi = sqrt(hi);
		int vvv = 50;
		j = 0;
		while(vvv--)
		{
			mid = (hi+lo)/2;
			i = bpm(m,n,mid);
			if(i >= m-k)
				j = 1, hi = mid;
			else
				lo = mid;
		}
		if(j)
			printf("Case #%d:\n%.3lf\n\n",cs+1,mid);
		else
			printf("Case #%d:\nToo bad.\n\n",cs+1);
	}
	return 0;
}