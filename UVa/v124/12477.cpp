#include<stdio.h>
#include<algorithm>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define SIZE 1000005
#define inf 2100000000
#define LL long long

int A[SIZE];

struct nod{
    int val,lazy;
	int mn,mx;
	LL sq_sum;
	char type;				//type->0 set, type->1 plus
}seg[4*SIZE];

void assign(int node,LL x,int lo,int hi,int f)
{
	seg[node].sq_sum = seg[node].sq_sum*f + 2*seg[node].val*x*f + x*x*(hi-lo+1);
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

	seg[node].sq_sum = seg[2*node].sq_sum + seg[2*node+1].sq_sum;
    seg[node].val = seg[2*node].val + seg[2*node+1].val;
	seg[node].mn = Min(seg[2*node].mn,seg[2*node+1].mn);
	seg[node].mx = Max(seg[2*node].mx,seg[2*node+1].mx);
}

pair< pair<LL,int> , pair<int,int> > query(int node,int lo,int hi,int a, int b)
{
	if(lo>b || hi<a) return make_pair(make_pair(0,0),make_pair(inf,-inf));
	if(lo>=a && hi<=b)
		return make_pair(make_pair(seg[node].sq_sum,seg[node].val),
						make_pair(seg[node].mn,seg[node].mx));

	release(node,lo,hi);

	int mid=(lo+hi)/2;
	pair< pair<LL,int> , pair<int,int> > l=query(2*node,lo,mid,a,b);
	pair< pair<LL,int> , pair<int,int> > r=query(2*node+1,mid+1,hi,a,b);
	pair< pair<LL,int> , pair<int,int> > ret;
	ret.first.first = l.first.first + r.first.first;
	ret.first.second = l.first.second + r.first.second;
	ret.second.first = Min(l.second.first,r.second.first);
	ret.second.second = Max(l.second.second,r.second.second);
	return ret;
}

void build(int node, int left, int right){
    if( left == right){
		seg[node].sq_sum = ((LL)A[left])*((LL)A[left]);
		seg[node].mn = A[left];
		seg[node].mx = A[left];
        seg[node].val = A[left];
        seg[node].lazy = 0;
		seg[node].type = 1;
        return;
    }

    int mid = (left+right)/2;

    build(2*node, left, mid);
    build(2*node+1, mid+1, right);

	seg[node].sq_sum = seg[2*node].sq_sum + seg[2*node+1].sq_sum;
	seg[node].val = seg[2*node].val + seg[2*node+1].val;
	seg[node].mn = Min(seg[2*node].mn,seg[2*node+1].mn);
	seg[node].mx = Max(seg[2*node].mx,seg[2*node+1].mx);
    seg[node].lazy = 0;
	seg[node].type = 1;
}

LL gcd(LL a,LL b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

int main()
{
//	freopen("dis.in","r",stdin);
//	freopen("dis.out","w",stdout);
	int t,q,a,b,c,n,i,f,cs = 0;

	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",++cs);

		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);

		build(1,1,n);
		while(q--)
		{
			scanf("%d%d%d",&f,&a,&b);
			if(f<2)
			{
				scanf("%d",&c);
				update(1,1,n,a,b,c,f);
			}
			else
			{
				pair< pair<LL,int> , pair<int,int> > got = query(1,1,n,a,b);
				int range = b - a + 1;
				LL lob = range*got.first.first - ((LL)got.first.second)*((LL)got.first.second);
				LL hor = ((LL)range)*((LL)range);
				LL g = gcd(lob,hor);
				lob /= g;
				hor /= g;

				range = got.second.second - got.second.first;
				if(range < 0)
					range *= -1;
				printf("%lld/%lld %d\n",lob,hor,range);
			}
		}
	}
	return 0;
}