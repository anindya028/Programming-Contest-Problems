#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define MaxVal 10003 
#define mod 1000000
pair<int,int> vpi[10005];

int tree[2][52][10005];

int read(int is,int kk,int idx){
	int sum = 0;
	while (idx > 0){
		sum = (sum + tree[is][kk][idx])%mod;
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int is,int kk,int idx ,int val){
	while (idx <= MaxVal){
		tree[is][kk][idx] = (tree[is][kk][idx]+val)%mod;
		idx += (idx & -idx);
	}
}

bool comp(int x,int y)
{
	return x>y;
}

int main()
{
	int t,cs,i,n,k,j;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&k);
		memset(tree,0,sizeof(tree));
		set<int> now;
		
		for(i=0;i<n;i++)
			scanf("%d%d",&vpi[i].first,&vpi[i].second),
			now.insert(vpi[i].second);
		
		sort(vpi,vpi+n);
		vector<int> g(now.begin(),now.end());
		
		vector<int> le;
		for(i=0;i<g.size();i++)
			le.push_back(g[i]);
		reverse(le.begin(),le.end());
		int m = g.size();
		
		vector<int>::iterator it[2];
		for(i=0;i<n;i++)
		{
			it[0] = lower_bound(g.begin(),g.end(),vpi[i].second);
			it[1] = lower_bound(le.begin(),le.end(),vpi[i].second,comp);
			
			int u[2],v[2],w[2];
			v[0] = it[0] - g.begin();
			u[0] = read(0,0,v[0]+1) - read(0,0,v[0]);
			update(0,0,v[0]+1,1-u[0]);
			
			v[1] = it[1] - le.begin();
			u[1] = read(1,0,v[1]+1) - read(1,0,v[1]);
			update(1,0,v[1]+1,1 - u[1]);

			u[0] = ( read(0,0,v[0]) + read(0,1,v[0]))%mod;
			w[0] = ( read(0,1,v[0]+1) - read(0,1,v[0]) + mod)%mod;
			update(0,1,v[0]+1, (u[0] - w[0] + mod)%mod);

			u[1] = ( read(1,0,v[1]) + read(1,1,v[1]))%mod;
			w[1] = ( read(1,1,v[1]+1) - read(1,1,v[1]) + mod )%mod;
			update(1,1,v[1]+1, (u[1] - w[1] + mod)%mod); 
			
			for(j=2;j<=k+1;j++)
			{
				u[0] = (read(0,j,v[0]) + read(1,j-1,m) - read(1,j-1,v[1]+1) + mod)%mod;
				w[0] = (read(0,j,v[0]+1) - read(0,j,v[0]) + mod)%mod;
				update(0,j,v[0]+1, ( u[0] - w[0] + mod )%mod );
				
				u[1] = (read(1,j,v[1]) + read(0,j-1,m) - read(0,j-1,v[0]+1) + mod)%mod;
				w[1] = (read(1,j,v[1]+1) - read(1,j,v[1]) + mod)%mod;
				update(1,j,v[1]+1,( u[1] - w[1] + mod )%mod );
			}
		}

		int ans = ( read(0,k+1,g.size()) + read(1,k+1,g.size()) )%mod;
	
		if(!k)
			ans = ( ans + n + 1)%mod;
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}