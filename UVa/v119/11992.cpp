#include<stdio.h>
#include<algorithm>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define SIZE 1000005
#define inf 2000000000
#define LL long long

struct nod{
    int val,lazy;
	int mn,mx;
	char type;				//type->0 set, type->1 plus
}seg[4*SIZE];

void assign(int node,int x,int lo,int hi,int f)
{
	seg[node].val = seg[node].val*f + x*(hi-lo+1);
    seg[node].lazy = seg[node].lazy*f + x;
	seg[node].mn = seg[node].mn*f + x;
	seg[node].mx = seg[node].mx*f + x;
	seg[node].type *= f;
}

void release(int node,int lo,int hi)
{
	if(seg[node].lazy==0 && seg[node].type == 1) return;
	int mid = (lo+hi)/2;
	assign(2*node,seg[node].lazy,lo,mid,seg[node].type);
	assign(2*node+1,seg[node].lazy,mid+1,hi,seg[node].type);
	seg[node].lazy = 0;
	seg[node].type = 1;
}

void update(int node,int lo,int hi,int a, int b, int val,int f)
{
	if(lo>b || hi<a) return;
	if(lo>=a && hi<=b)
	{
		assign(node,val,lo,hi,f);
		return ;
	}

	release(node,lo,hi);

	int mid=(lo+hi)/2;
	update(2*node,lo,mid,a,b, val,f);
	update(2*node+1,mid+1,hi,a,b, val,f);
	
    seg[node].val = seg[2*node].val + seg[2*node+1].val;
	seg[node].mn = Min(seg[2*node].mn,seg[2*node+1].mn);
	seg[node].mx = Max(seg[2*node].mx,seg[2*node+1].mx);
}

pair< pair<int,int> , int > query(int node,int lo,int hi,int a, int b)
{
	if(lo>b || hi<a) return make_pair(make_pair(0,inf),0);
	if(lo>=a && hi<=b) return make_pair(make_pair(seg[node].val,seg[node].mn),seg[node].mx);

	release(node,lo,hi);

	int mid=(lo+hi)/2;
	pair< pair<int,int> , int > l=query(2*node,lo,mid,a,b);
	pair< pair<int,int> , int > r=query(2*node+1,mid+1,hi,a,b);
	pair< pair<int,int> , int > ret;
	ret.first.first = l.first.first + r.first.first;
	ret.first.second = Min(l.first.second,r.first.second);
	ret.second = Max(l.second,r.second);
	return ret;
}

void build(int node, int left, int right){
    if( left == right){
		seg[node].mn = 0;
		seg[node].mx = 0;
        seg[node].val = 0;
        seg[node].lazy = 0;
		seg[node].type = 1;
        return;
    }
    
    int mid = (left+right)/2;
    
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);
    
    seg[node].val = seg[2*node].val + seg[2*node+1].val;
	seg[node].mn = Min(seg[2*node].mn,seg[2*node+1].mn);
	seg[node].mx = Max(seg[2*node].mx,seg[2*node+1].mx);
    seg[node].lazy = 0;
	seg[node].type = 1;
}

int main()
{
	int n,r,c,q,r1,c1,r2,c2,v,is,i;	
	
	while(scanf("%d%d%d",&r,&c,&q)==3)
	{
		n = r*c;
		build(1,1,n);

		while(q--)
		{
			scanf("%d",&is);
			if(is==1)
			{
				scanf("%d%d%d%d%d",&r1,&c1,&r2,&c2,&v);
				for(i=r1;i<=r2;i++)	
					update(1,1,n,(i-1)*c+c1,(i-1)*c+c2,v,1);
			}
			else if(is==2)
			{
				scanf("%d%d%d%d%d",&r1,&c1,&r2,&c2,&v);
				for(i=r1;i<=r2;i++)
					update(1,1,n,(i-1)*c+c1,(i-1)*c+c2,v,0);
			}
			else
			{
				scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
				pair< pair<int,int> , int > ans , got;
				ans = make_pair(make_pair(0,inf),0);
				for(i=r1;i<=r2;i++)
				{
					got = query(1,1,n,(i-1)*c+c1,(i-1)*c+c2);
					ans.first.first += got.first.first;
					ans.first.second = Min(ans.first.second,got.first.second);
					ans.second = Max(ans.second,got.second);
				}
				printf("%d %d %d\n",ans.first.first,ans.first.second,ans.second);
			}
		}
	}
	return 0;
}
