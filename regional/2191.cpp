#include<stdio.h>
#define SIZE 600005
int A[SIZE],M[SIZE];

void initialize(int node,int b,int e)
{
	if(b==e)
	{
		M[node]=A[b];
		return;
	}
	initialize(2*node,b,(b+e)/2);
	initialize(2*node+1,(b+e)/2+1,e);
	M[node]=M[2*node]+M[2*node+1];
}

int query(int node,int b,int e,int i,int j)
{
	int p1,p2;
	if(i>e || j<b)
		return 0;
	if(b>=i && e<=j)
		return M[node];
	p1=query(2*node,b,(b+e)/2,i,j);
	p2=query(2*node+1,(b+e)/2+1,e,i,j);
	return p1+p2;
}

void update(int node,int b,int e,int pos,int val)
{
	if(pos<b || pos>e)
		return;
	if(b==e)
	{
		M[node]=val;
		return;
	}
	update(2*node,b,(b+e)/2,pos,val);
	update(2*node+1,(b+e)/2+1,e,pos,val);
	M[node]=M[2*node]+M[2*node+1];
}

int main()
{
	int n,i,j,cs=0;
	char s[100];
	while(scanf("%d",&n)==1 && n)
	{
		if(cs)
			printf("\n");
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		initialize(1,0,n-1);
		printf("Case %d:\n",++cs);
		while(scanf("%s",s)==1 && s[0]!='E')
		{
			scanf("%d%d",&i,&j);
			if(s[0]=='M')
				printf("%d\n",query(1,0,n-1,i-1,j-1));
			else
				update(1,0,n-1,i-1,j);
		}
	}
	return 0;
}