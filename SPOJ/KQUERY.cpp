#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define MaxVal 30002
int tree[30005];

pair<int,int> vnt[300005];
int u[200005],v[200005],ans[200005];

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
	int n,i,k,q;
	while(scanf("%d",&n)==1)
	{
		memset(tree,0,sizeof(tree));
		for(i=1;i<=n;i++)
			scanf("%d",&vnt[i-1].first),vnt[i-1].second=i;
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&k);
			vnt[n+i-1].first = k;
			vnt[n+i-1].second = n+i;
		}
		sort(vnt,vnt+n+q);

		for(i=n+q-1;i>=0;i--)
		{
			if(vnt[i].second<=n)
				update(vnt[i].second,1);
			else
				k = vnt[i].second-n,
				ans[k] = read(v[k]) - read(u[k] - 1);
		}

		for(i=1;i<=q;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}