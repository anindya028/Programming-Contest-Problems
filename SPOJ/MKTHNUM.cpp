#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 2000000000
#define maxs 100005

int val[maxs],cnt;
vector<int> segment[4*maxs];
int interv[105];

void mergesort(int node,int left,int right)
{
	segment[node].clear();
	if(left==right)
	{
		segment[node].push_back(val[left]);
		return;
	}

	int mid = (left+right)/2;
	mergesort(2*node,left,mid);
	mergesort(2*node+1,mid+1,right);

	segment[2*node].push_back(inf);
	segment[2*node+1].push_back(inf);
	
	int i,j=0,k=0;
	for(i=left;i<=right;i++)
		if(segment[2*node][j]<segment[2*node+1][k])
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

int main()
{
	int n,m,a,b,k,i;
	vector<int>::iterator it;
	while(scanf("%d%d",&n,&m)==2)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&val[i]);

		mergesort(1,1,n);

		while(m--)
		{
			scanf("%d%d%d",&a,&b,&k);
			cnt = 0;
			query(1,1,n,a,b);

			int lo=-inf,hi=inf,mid,ans;
			while(lo<=hi)
			{
				mid = (lo+hi)/2;

				int sum = 0;
				for(i=0;i<cnt;i++)
				{
					it = upper_bound(segment[interv[i]].begin(),segment[interv[i]].end(),mid);
					sum += (it - segment[interv[i]].begin());
				}
				
				if(sum>=k)
					hi=mid-1,ans=mid;
				else
					lo=mid+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}