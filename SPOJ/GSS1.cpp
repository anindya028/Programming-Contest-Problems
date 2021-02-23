#include<stdio.h>

#define inf (1<<29)
#define Max(a,b) ((a)>(b)?(a):(b))
int g[50005];

struct state
{
	int left,right,mx,sum;
	state(){}
	state(int _left,int _right,int _mx,int _sum)
	{
		left = _left, right = _right, mx = _mx, sum = _sum;
	}
}tree[200005];

void init(int node,int lo,int hi)
{
	if(lo==hi)
	{
		tree[node].sum = tree[node].mx = g[lo];
		tree[node].left = tree[node].right = g[lo];
		return;
	}
	int mid = (lo+hi)/2;
	init(2*node,lo,mid);
	init(2*node+1,mid+1,hi);

	tree[node].left = Max(tree[2*node].left,tree[2*node].sum+tree[2*node+1].left);
	tree[node].right = Max(tree[2*node+1].right,tree[2*node].right+tree[2*node+1].sum);
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
	tree[node].mx = Max(tree[2*node].mx,tree[2*node+1].mx);
	tree[node].mx = Max(tree[node].mx,tree[2*node].right+tree[2*node+1].left);
}

state query(int node,int lo,int hi,int i,int j)
{
	if(hi<i || lo>j)
	{
		state ret(-inf,-inf,-inf,0);
		return ret;
	}
	if(lo>=i && hi<=j)
		return tree[node];
	
	int mid = (lo+hi)/2;
	state q1 = query(2*node,lo,mid,i,j);
	state q2 = query(2*node+1,mid+1,hi,i,j);

	state ret;
	ret.sum = q1.sum + q2.sum;
	ret.left = Max(q1.left,q1.sum+q2.left);
	ret.right = Max(q2.right,q1.right+q2.sum);
	ret.mx = Max(q1.mx,q2.mx);
	ret.mx = Max(ret.mx,q1.right+q2.left);

	return ret;
}

int main()
{
	int n,i,m,u,v;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&g[i]);

		init(1,0,n-1);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			printf("%d\n",query(1,0,n-1,u-1,v-1).mx);
		}
	}
	return 0;
}