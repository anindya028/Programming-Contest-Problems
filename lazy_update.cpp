/*
ID: anindya1
PROG: balloc
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include <algorithm>
#include <vector>
#include<set>
#include<map>
#include<queue>
#include<cassert>
using namespace std;

#define inf 1<<29
#define pii pair<int,int>
#define SIZE 100005

int cap[100005];
pii range[100005];
struct node{
    int val, lazy;
}seg[4*SIZE];


void assign(int node,int x)
{
	seg[node].val += x;
    seg[node].lazy += x;
}

void release(int node)
{
	if(seg[node].lazy==0) return;
	assign(2*node,seg[node].lazy);
	assign(2*node+1,seg[node].lazy);
	seg[node].lazy = 0;
}

void update(int node,int lo,int hi,int a, int b, int val)
{
	if(lo>b || hi<a) return;
	if(lo>=a && hi<=b)
	{
		assign(node,val);
		return ;
	}

	release(node);

	int mid=(lo+hi)/2;
	update(2*node,lo,mid,a,b, val);
	update(2*node+1,mid+1,hi,a,b, val);
	
    seg[node].val = std::min(seg[2*node].val , seg[2*node+1].val);
}

int query(int node,int lo,int hi,int a, int b)
{
	if(lo>b || hi<a) return inf;
	if(lo>=a && hi<=b) return seg[node].val;

	release(node);

	int mid=(lo+hi)/2;
	int l=query(2*node,lo,mid,a,b);
	int r=query(2*node+1,mid+1,hi,a,b);

	return std::min(l,r);
}

void build(int node, int left, int right){
    if( left == right){
        seg[node].val = cap[left];
        seg[node].lazy = 0;
        return;
    }
    
    int mid = (left+right)/2;
    
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);
    
    seg[node].val = std::min(seg[2*node].val, seg[2*node+1].val);
    seg[node].lazy = 0;
}

bool comp(pii a,pii b)
{
    if( a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int n,m,i;
    
    freopen("balloc.in", "r", stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&cap[i]);
        for(i=0;i<m;i++)
            scanf("%d%d",&range[i].first,&range[i].second);
        sort(range,range+m,comp);
        
        build(1, 1, n );
        
        int ans=0;
        
        for(i=0;i<m;i++)
        {
            int v = query(1,1,n,range[i].first,range[i].second);
            if(v>0)
            {
                ans++;
                update(1,1,n,range[i].first,range[i].second,-1);
            }
        }
        
        printf("%d\n",ans);
    }
    return 0;
}