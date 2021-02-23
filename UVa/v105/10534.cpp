#include<stdio.h>
#include<algorithm>
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

int lis[10005],m[2][40005],lds[10005];

int query(int node,int b,int e,int i,int j,int f)
{
	int p1,p2;
	if(i>e || j<b)
		return 0;
	if(b>=i && e<=j)
		return m[f][node];
	p1=query(2*node,b,(b+e)/2,i,j,f);
	p2=query(2*node+1,(b+e)/2+1,e,i,j,f);
	return Max(p1,p2);
}

void update(int node,int b,int e,int pos,int val,int f)
{
	if(pos<b || pos>e)
		return;
	if(b==e)
	{
		m[f][node]=Max(m[f][node],val);
		return;
	}
	update(2*node,b,(b+e)/2,pos,val,f);
	update(2*node+1,(b+e)/2+1,e,pos,val,f);
	m[f][node]=Max(m[f][2*node],m[f][2*node+1]);
}

int main()
{
	int n,i,j,ans,temp;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&data[i]),data1[i]=data[i];
		sort(data1,data1+n);
		for(i=0;i<40005;i++)
			m[0][i]=m[1][i]=0;
		for(i=0;i<n;i++)
		{
			j=less(data[i],n);
			if(j!=-1)
				lis[i]=1+query(1,0,n-1,0,j,0),update(1,0,n-1,j+1,lis[i],0);
			else
				lis[i]=1,update(1,0,n-1,0,lis[i],0);
		}
		i=0,j=n-1;
		while(i<j)
			temp=data[i],data[i]=data[j],data[j]=temp,i++,j--;
		for(i=0;i<n;i++)
		{
			j=less(data[i],n);
			if(j!=-1)
				lds[i]=1+query(1,0,n-1,0,j,1),update(1,0,n-1,j+1,lds[i],1);
			else
				lds[i]=1,update(1,0,n-1,0,lds[i],1);
		}
		i=0,j=n-1;
		while(i<j)
			temp=lds[i],lds[i]=lds[j],lds[j]=temp,i++,j--;
		ans=0;
		for(i=0;i<n;i++)
			j=2*Min(lis[i],lds[i])-1,
			ans=Max(ans,j);
		printf("%d\n",ans);
	}
	return 0;
}