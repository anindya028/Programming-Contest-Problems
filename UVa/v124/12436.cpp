#include<stdio.h>
#include<algorithm>

using namespace std;

#define LL long long
#define SIZE 250000

struct nod{
    LL val,lazy;
	int inc,dec;			//lazy
	char type;				//type->0 set, type->1 plus
}seg[4*SIZE+5];

LL sum(int a,int b)
{
	LL v = b - a + 1;
	return ((v*(v+1))/2);
}

void assign(int node,int lo,int hi,LL v,int i,int d,int f)
{
	seg[node].val = seg[node].val*f + v*(hi-lo+1);
	seg[node].val += (sum(lo,hi)*(i+d));
	seg[node].lazy = seg[node].lazy*f + v;
	seg[node].inc = seg[node].inc*f + i;
	seg[node].dec = seg[node].dec*f + d;
	seg[node].type *= f;
}

void release(int node,int lo,int hi)
{
	if(seg[node].lazy==0 && seg[node].inc==0 && seg[node].dec==0 && seg[node].type==1)
		return;
	int mid = (lo+hi)/2;
//	int v = seg[node].lazy;
	LL vleft = seg[node].lazy + (LL)(hi-mid)*seg[node].dec;
	LL vright = seg[node].lazy + (LL)(mid-lo+1)*seg[node].inc;

	assign(2*node,lo,mid,vleft,seg[node].inc,seg[node].dec,seg[node].type);
	assign(2*node+1,mid+1,hi,vright,seg[node].inc,seg[node].dec,seg[node].type);

	seg[node].lazy = seg[node].inc = seg[node].dec = 0;
	seg[node].type = 1;
}

void update(int node,int lo,int hi,int a,int b,int v,int i,int d,int f)
{
	if(b<lo || a>hi)
		return;
	if(a<=lo && b>=hi)
	{
		if(a<lo)
			v += ((lo-a)*i);
		if(b>hi)
			v += ((b-hi)*d);
		assign(node,lo,hi,v,i,d,f);
		return;
	}

	release(node,lo,hi);
	int mid = (lo+hi)/2;

	update(node*2, lo, mid, a, b, v, i, d, f);
	update(node*2 + 1, mid+1, hi, a, b, v, i, d, f);

	seg[node].val = seg[node*2].val + seg[node*2+1].val;
}

LL query(int node,int lo,int hi,int a,int b)
{
	if(b<lo || a>hi)
		return 0;
	if(a<=lo && b>=hi)
		return seg[node].val;

	release(node,lo,hi);

	int mid = (lo+hi)/2;
	LL L = query(node*2, lo, mid, a, b);
	LL R = query(node*2 + 1, mid + 1, hi, a, b);

	return L+R;
}

void build(int node,int lo,int hi)
{
	seg[node].val = seg[node].lazy = seg[node].inc = seg[node].dec = 0;
	seg[node].type = 1;
	
	if(lo==hi)
		return;

	int mid = (lo+hi)/2;
    
    build(2*node, lo, mid);
    build(2*node+1, mid+1, hi);
}

int main()
{
//	freopen("rip_final.in","r",stdin);
//	freopen("rip_logn.out","w",stdout);
	build(1,1,SIZE);
	int m,st,nd,x,cs=0;
	char s[20];
	scanf("%d",&m);
	while(m--)
	{
	//	cs++;
		scanf("%s%d%d",s,&st,&nd);
		if(st<1 || nd>SIZE)
			while(1)
				printf("Wrong Input\n");
		if(s[0]=='C')
		{
			scanf("%d",&x);
			update(1,1,SIZE,st,nd,x,0,0,0);
		}
		else if(s[0]=='A')
			update(1,1,SIZE,st,nd,0,1,0,1);
		else if(s[0]=='B')
			update(1,1,SIZE,st,nd,0,0,1,1);
		else
			printf("%lld\n",query(1,1,SIZE,st,nd));
	}
	return 0;
}