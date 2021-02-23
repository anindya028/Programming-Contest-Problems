#include<stdio.h>

int main()
{

	unsigned long long m,n,temp,ans;
	while(scanf("%llu%llu",&m,&n)==2 && m && n)
	{
		if(n>m)
		{
			temp=m;
			m=n;
			n=temp;
		}
		if(n==1)
			ans=m*(m-1);
		else
		{
			ans=m*n*(n-1);
			ans+=n*m*(m-1);
			ans+=2*(m-n+1)*n*(n-1);
			ans+=4*( ((n-1)*n*(2*n-1))/6 - (n*(n-1))/2 );
		}
		printf("%llu\n",ans);
	}
	return 0;
}