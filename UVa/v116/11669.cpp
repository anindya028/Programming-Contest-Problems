#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

char p[1000005];
int pr[80000],n;

int gene(void)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++] = i;
	return j;
}

struct fact
{
	int len;
	vector<int> pp;
}f[1000003];

bool operator<(fact &x,fact &y)
{
	if(x.len!=y.len)
		return x.len<y.len;
	int i;
	for(i=0;i<x.len;i++)
		if(x.pp[i]!=y.pp[i])
			return x.pp[i]<y.pp[i];
	return true;
}

#define inf 2000000000
#define maxs 1000002

vector<int> segment[4*maxs];
int interv[105],cnt;

void mergesort(int node,int left,int right)
{
	segment[node].clear();
	if(left==right)
	{
		segment[node].push_back(left);
		return;
	}

	int mid = (left+right)/2;
	mergesort(2*node,left,mid);
	mergesort(2*node+1,mid+1,right);

	segment[2*node].push_back(0);
	segment[2*node+1].push_back(0);
	
	int i,j=0,k=0;
	for(i=left;i<=right;i++)
		if(f[ segment[2*node][j] ] < f [ segment[2*node+1][k] ])
			segment[node].push_back(segment[2*node][j]),j++;
		else
			segment[node].push_back(segment[2*node+1][k]),k++;

	segment[2*node].pop_back();
	segment[2*node+1].pop_back();
}

void query(int node,int left,int right,int a,int b)
{
	if(b<left || a>right) return;
	if(left>=a && right<=b)
	{
		interv[cnt++] = node;
		return;
	}

	int mid = (left+right)/2;
	query(2*node,left,mid,a,b);
	query(2*node+1,mid+1,right,a,b);
}

bool comp(int x,int y)
{
	if(x==y)
		return x<y;
	return f[x]<f[y];
}

int main()
{
	int t,a,b,k,i,j,cs=0,u,v;
	n=1000000;
	vector<int>::iterator it;
	
	int m = gene();
	f[1].len = 0;
		
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		
		for(i=0;i<m && pr[i]*u<=n;i++)
		{
			v = pr[i]*u;
			if(f[v].len == 0)
			{
				j=0;
				while(j<f[u].len && f[u].pp[j]<=pr[i])
					f[v].pp.push_back(f[u].pp[j]),j++;
				f[v].pp.push_back(pr[i]);
				while(j<f[u].len)
					f[v].pp.push_back(f[u].pp[j]),j++;
				f[v].len = f[u].len + 1;
				q.push(v);
			}
		}
	}
	f[1].len = 1000, f[0].len = 2000;
/*	for(i=2;i<=n;i++)
	{
		f[i].pp.clear();
		if(!p[i])
		{
			f[i].len = 1;
			f[i].pp.push_back(i);
			continue;
		}
		int temp = i;
		for(j=0;j<m && pr[j]*pr[j]<=temp;j++)
			while(temp%pr[j]==0)
				f[i].pp.push_back(pr[j]),temp/=pr[j];
		if(temp!=1)
			f[i].pp.push_back(temp);
		f[i].len = f[i].pp.size();
	}
*/
	mergesort(1,1,n);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);

		cnt = 0;
		query(1,1,n,a,b);

		int lo=0,hi=segment[1].size()-1,mid,ans;
		while(lo<=hi)
		{
			mid = (lo+hi)/2;

			int sum = 0;
			for(i=0;i<cnt;i++)
			{
				it = upper_bound(segment[interv[i]].begin(),segment[interv[i]].end(),segment[1][mid],comp);
				sum += (it - segment[interv[i]].begin());
			}
			
			if(sum>=k)
				hi=mid-1,ans=mid;
			else
				lo=mid+1;
		}
		
		ans = segment[1][ans];
		printf("Case %d:",++cs);
		for(i=0;i<f[ans].len;i++)
			printf(" %d",f[ans].pp[i]);
		printf("\n");
	}
	return 0;
}