#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define MaxVal 30002
int prev[1000005];
int next[30005],g[30005];
int tree[30005];
vector< pair<int,int> > vq[30005];
int ans[200005];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum = (sum + tree[idx]);
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] = (tree[idx]+val);
		idx += (idx & -idx);
	}
}

int main()
{
	int n,i,q,j,k;
	while(scanf("%d",&n)==1)
	{
		memset(tree,0,sizeof(tree));
		memset(prev,0,sizeof(prev));
		memset(next,0,sizeof(next));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&g[i]);
			vq[i].clear();
			if(prev[g[i]])
				next[prev[g[i]]] = i;
			else
				update(i,1);
			prev[g[i]] = i;
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&j,&k);
			vq[j].push_back(make_pair(k,i));
		}

		for(i=1;i<=n;i++)
		{
			for(j=0;j<vq[i].size();j++)
				k = read(vq[i][j].first) - read(i-1),
				ans[vq[i][j].second] = k;
			
			update(i,-1);
			if(next[i])
				update(next[i],1);
		}

		for(i=0;i<q;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}