#include<stdio.h>

int pr[10005];
char p[10005];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

int main()
{
	int t,i,a,c,m=gene(10000);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&c);
		if(c%a)
		{
			printf("NO SOLUTION\n");
			continue;
		}
		int b=1;
		for(i=0;pr[i]*pr[i]<=c && i<m;i++)
			if(c%pr[i]==0)
			{
				int u=1,v=1;
				while(c%pr[i]==0)
					c/=pr[i],v*=pr[i];
				while(a%pr[i]==0)
					a/=pr[i],u*=pr[i];
				if(u!=v)
					b*=v;
			}
		if(c!=1 && a!=c)
			b*=c;
		printf("%d\n",b);
	}
	return 0;
}