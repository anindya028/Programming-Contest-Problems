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
	if(hi<i || lo>j || j<i)
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
	int t,n,i,q,x1,y1,x2,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&g[i]);
		init(1,0,n-1);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
			x1--,y1--,x2--,y2--;
			int ans = -inf;
			if(y1<x2)
			{
				ans = query(1,0,n-1,x1,y1).right + query(1,0,n-1,x2,y2).left;
				if(y1+1<x2)
					ans += query(1,0,n-1,y1+1,x2-1).sum;
			}
			else
			{
				state aa = query(1,0,n-1,x2,y1);
				state bam = query(1,0,n-1,x1,x2-1);
				state dan = query(1,0,n-1,y1+1,y2);
				ans = Max(ans,aa.mx);
				ans = Max(ans,bam.right+aa.left);
				ans = Max(ans,aa.right+dan.left);
				ans = Max(ans,bam.right+aa.sum+dan.left);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}