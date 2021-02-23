#include<stdio.h>

#define LL long long
LL dp[40][40];
LL make(int a,int b)
{
	if(!a || !b) return 1;
	if(dp[a][b])
		return dp[a][b];
	dp[a][b]=make(a-1,b)+make(a,b-1);
	return dp[a][b];
}

LL calc(int a,int b,int c)
{
	return make(a,b)*make(a+b,c);
}

int main()
{
	int t,a,b,c,i,j,k,n;
	int pr[]={2,3,5,7,11,13,17,19,23,29,31,37};
	int phi[45];
	phi[1]=1;
	for(i=2;i<41;i++)
	{
		j=i;
		for(k=0;k<12;k++)
			if(i%pr[k]==0)
				j/=pr[k],j*=(pr[k]-1);
		phi[i]=j;
	}
	scanf("%d",&t);
	LL ans;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		n=a+b+c;
		for(i=1;i<=n;i++)
			if(n%i==0 && a%i==0 && b%i==0 && c%i==0)
				ans+=(phi[i]*calc(a/i,b/i,c/i));
		if(n%2)
		{
			if((a-1)%2==0 && b%2==0 && c%2==0)
				ans+=(n*calc((a-1)/2,b/2,c/2));
			if((b-1)%2==0 && a%2==0 && c%2==0)
				ans+=(n*calc((b-1)/2,a/2,c/2));
			if((c-1)%2==0 && a%2==0 && b%2==0)
				ans+=(n*calc((c-1)/2,a/2,b/2));
		}
		else
		{
			if(a%2==0 && b%2==0 && c%2==0)
				ans+=(n/2)*calc(a/2,b/2,c/2);
			
			if(a>=2 && (a-2)%2==0 && b%2==0 && c%2==0)
				ans+=(n/2)*calc((a-2)/2,b/2,c/2);
			if(b>=2 && (b-2)%2==0 && a%2==0 && c%2==0)
				ans+=(n/2)*calc((b-2)/2,a/2,c/2);
			if(c>=2 && (c-2)%2==0 && a%2==0 && b%2==0)
				ans+=(n/2)*calc((c-2)/2,a/2,b/2);
			
			if((a-1)%2==0 && (b-1)%2==0 && c%2==0)
				ans+= n*calc((a-1)/2,(b-1)/2,c/2);
			if((a-1)%2==0 && (c-1)%2==0 && b%2==0)
				ans+= n*calc((a-1)/2,(c-1)/2,b/2);
			if((b-1)%2==0 && (c-1)%2==0 && a%2==0)
				ans+= n*calc((b-1)/2,(c-1)/2,a/2);
		}
		printf("%lld\n",ans/(2*n));
	}
	return 0;
}