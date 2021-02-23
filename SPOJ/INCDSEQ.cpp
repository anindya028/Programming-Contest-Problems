#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define MaxVal 10002
#define mod 5000000
int g[10005];
int tree[52][10005];

int read(int kk,int idx){
	int sum = 0;
	while (idx > 0){
		sum = (sum + tree[kk][idx])%mod;
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int kk,int idx ,int val){
	while (idx <= MaxVal){
		tree[kk][idx] = (tree[kk][idx]+val)%mod;
		idx += (idx & -idx);
	}
}

int main()
{
	int n,k,i,j;
	while(scanf("%d%d",&n,&k)==2)
	{
	//	memset(tree,0,sizeof(tree));
		set<int> now;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&g[i]);
			now.insert(g[i]);
		}
		vector<int> vi(now.begin(),now.end());
		vector<int>::iterator it;

		for(i=1;i<=n;i++)
		{
			it = lower_bound(vi.begin(),vi.end(),g[i]);
			int u,v = it - vi.begin();
			int w = read(1,v+1) - read(1,v);
			update(1,v+1,1-w);
			for(j=2;j<=k;j++)
				w = (read(j,v+1) - read(j,v) + mod)%mod,
				u = read(j-1,v),
				update(j,v+1,(u-w+mod)%mod);
		}	

		printf("%d\n",read(k,vi.size()));
	}
	return 0;
}