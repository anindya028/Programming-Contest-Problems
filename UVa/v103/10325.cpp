#include<stdio.h>

#define LL long long

LL gcd(LL n,LL m)
{
	if(!m)return n;
	return gcd(m,(n%m));
}

LL lcm(LL a,LL b)
{
	LL ret=(a/gcd(a,b))*b;
	return ret;
}

int main()
{
	int n,m,i,j,ans,num[20];
	while(scanf("%d%d",&n,&m)==2)
	{
		for(i=0;i<m;i++)
			scanf("%d",&num[i]);
		for(i=ans=0;i<(1<<m);i++)
		{
			int cnt=0;
			LL temp=1;
			for(j=0;j<m;j++)
				if(i & 1<<j)
				{
					temp=lcm(temp,num[j]);
					cnt++;
				}
			if(cnt%2)
				ans-=(n/temp);
			else
				ans+=(n/temp);
		}
		printf("%d\n",ans);
	}
	return 0;
}