#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))

int data[10005],data1[10005];

int less(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(data1[mid]<key)
			low=mid;
		else
			high=mid-1;
	}
	if(data1[low]<key)
		return low;
	else
		return -1;
}

struct hehe
{
	int len,idx;
}m[40005],zero;

bool operator>(hehe a,hehe b)
{
	if(a.len==b.len)
		return a.idx<b.idx;
	return a.len>b.len;
}

int lis[10005],parent[10005];

hehe query(int node,int b,int e,int i,int j)
{
	hehe p1,p2;
	if(i>e || j<b)
		return zero;	
	if(b>=i && e<=j)
		return m[node];
	p1=query(2*node,b,(b+e)/2,i,j);
	p2=query(2*node+1,(b+e)/2+1,e,i,j);
	return Max(p1,p2);
}

void update(int node,int b,int e,int pos,hehe val)
{
	if(pos<b || pos>e)
		return;
	if(b==e)
	{
		m[node]=val;
		return;
	}
	update(2*node,b,(b+e)/2,pos,val);
	update(2*node+1,(b+e)/2+1,e,pos,val);
	m[node]=Max(m[2*node],m[2*node+1]);
}

int main()
{
	int i,j,n,q,length,cs=0;
	zero.len=0;
	while(scanf("%d%d",&n,&q)==2 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&data[i]),data[i]*=-1,data1[i]=data[i];
		sort(data1,data1+n);
		reverse(data,data+n);
		for(i=0;i<4*n;i++)
			m[i].len=m[i].idx=0;
		for(i=0;i<n;i++)
		{
			j=less(data[i],n);
			hehe temp,val;
			if(j!=-1)
				temp=query(1,0,n-1,0,j),
				lis[i]=1+temp.len,
				parent[i]=temp.idx,
				val.idx=i,val.len=lis[i],
				update(1,0,n-1,j+1,val);
			else
				lis[i]=1,parent[i]=i,
				val.idx=i,val.len=lis[i],
				update(1,0,n-1,0,val);
		}

		printf("Set %d:\n",++cs);
		
		for(i=0;i<q;i++)
		{
			scanf("%d",&length);
			printf("  Subset %d:\n",i+1);
			vector<int> vv;
			j=0;
			int k;
			for(k=n-1;k>=0 && length;k--)
				if(lis[k]>=length)
				{
					if(!j)
						vv.push_back(data[k]),j++,length--;
					else if(vv[j-1]>data[k])
						vv.push_back(data[k]),j++,length--;
				}

			if(!j)
			{
				printf("    Impossible\n");
				continue;
			}
			
			printf("    %d",-vv[0]);
			for(k=1;k<vv.size();k++)
				printf(" %d",-vv[k]);
			printf("\n");
		}

	}
	return 0;
}