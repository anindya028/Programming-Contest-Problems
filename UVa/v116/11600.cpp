#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

vector< pair<int,int> > edge;
int parent[35],rank[35];
///path-compression
void link(int a,int b)
{
	if(rank[a]>rank[b])
		parent[b]=a;
	else
	{
		parent[a]=b;
		if(rank[a]==rank[b])
			rank[b]=rank[b]+1;
	}
	return;
}
////finding the root of set
int find_set(int a)
{
	if(a!=parent[a])
		parent[a]=find_set(parent[a]);
	return parent[a];
}

map< pair< vector<int> , int > , double > mp;

int n;

double make(vector<int> now,int pos)
{
	if(now.size()==1)
		return 0.0;
	pair< vector<int> , int > got =make_pair(now,pos);
	if(mp.find(got)!=mp.end())
		return mp[got];
	mp[got]=1.0;
	int i,j;
	vector<int> next;
	for(i=0;i<now.size();i++)
	{
		if(i==pos)
			continue;
		next.clear();
		for(j=0;j<now.size();j++)
			if(j!=i && j!=pos)
				next.push_back(now[j]);
		next.push_back(now[i]+now[pos]);
		sort(next.begin(),next.end());
		for(j=0;j<next.size();j++)
			if(next[j]==now[i]+now[pos])
				break;
		mp[got]+=( make(next,j) * ( (now[i]+0.0) / (n-1) ) );
	}
	mp[got]/=(1 - (now[pos]-1.0)/(n-1));
	return mp[got];
}

int main()
{
	int t,cs,m,u,v,i;
	scanf("%d",&t);
	mp.clear();
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			rank[i]=0,parent[i]=i;
		edge.clear();
		for(i=0;i<m;i++)
			scanf("%d%d",&u,&v),
			edge.push_back(make_pair(u,v)),
			edge.push_back(make_pair(v,u));
		for(i=0;i<2*m;i++)
		{
			u=find_set(edge[i].first);
			v=find_set(edge[i].second);
			if(u!=v)
				link(u,v);
		}
		int cnt[35]={0};
		for(i=1;i<=n;i++)
			cnt[find_set(i)]++;
		vector<int> now;
		for(i=1;i<=n;i++)
			if(cnt[i])
				now.push_back(cnt[i]);
		sort(now.begin(),now.end());
		for(i=0;i<now.size();i++)
			if(now[i]==cnt[find_set(1)])
				break;
		printf("Case %d: %.8lf\n",cs+1,make(now,i));
	}
	return 0;
}