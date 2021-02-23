#include<stdio.h>

int fact[10005];

int main()
{
	int i,j,n,m;
	for(i=2;i<=10000;i++)
	{
		int ok=0;
		for(j=2;j*j<=i;j++)
			if(i%j==0)
			{
				ok=1;
				fact[i]=fact[i/j]+1;
				break;
			}
		if(!ok)
			fact[i]=1;
	}
	int t,cs,a;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		int ans=0;
		for(i=0;i<n;i++)
		{
			int sum=0;
			for(j=0;j<m;j++)
				scanf("%d",&a),
				sum+=fact[a];
			ans^=sum;
		}
		if(ans)
			printf("Case #%d: YES\n",cs+1);
		else
			printf("Case #%d: NO\n",cs+1);
	}
	return 0;
}