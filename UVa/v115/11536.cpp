#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))

int M[1005],A[105];

int query(int node,int b,int e,int i,int j)
{
	int p1,p2;
	if(i>e || j<b)
		return 1<<29;
	if(b>=i && e<=j)
		return M[node];
	p1=query(2*node,b,(b+e)/2,i,j);
	p2=query(2*node+1,(b+e)/2+1,e,i,j);
	return Min(p1,p2);
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
	M[node]=Min(M[2*node],M[2*node+1]);
}

int x[1000005];

int main()
{
	int t,i,n,m,k,cs=0;
	x[0]=1;
	x[1]=2;
	x[2]=3;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d%d%d",&n,&m,&k);
		if(k<=3)
		{
			printf("Case %d: %d\n",++cs,k);
			continue;
		}
		
		for(i=0;i<=5*k;i++)
			M[i]=1<<29;
		for(i=0;i<=k;i++)
			A[i]=1<<29;
		
		A[1]=0,A[2]=1,A[3]=2;
		update(1,0,k,1,0);
		update(1,0,k,2,1);
		update(1,0,k,3,2);
		
		int cnt=3,ans=1<<29;
		
		for(i=3;i<n;i++)
		{
			x[i]=(x[i-1]+x[i-2]+x[i-3])%m + 1;
			if(x[i]>k)
				continue;
			if(A[x[i]]==1<<29)
			{
				cnt++;
				A[x[i]]=i;
			}
			update(1,0,k,x[i],i);
			if(cnt==k)
			{
				int j=query(1,0,k,1,k);
				ans=Min(ans,i-j+1);
			}
		}

		if(ans==1<<29)
			printf("Case %d: sequence nai\n",++cs);
		else
			printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}
