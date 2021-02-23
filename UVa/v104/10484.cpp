//Number Theory
#include<stdio.h>

long long prime[30],total;
long long ans,count[30];

void generate()
{
	long long i,j,YES;
	prime[0]=2;
	total=0;

	for(i=3;i<=99;i+=2)
	{
		YES=1;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0)
			{YES=0; break;}

			if(YES)
			{
				total++;
				prime[total]=i;
			}
	}
}

int main()
{
	long long n,d,i,k,temp,CAN;

	generate();

	while(scanf("%lld%lld",&n,&d)!=EOF)
	{
		CAN=1;
		if(!n && !d) break;
		if(d<0) d=d*-1;

		if(n==0)
		{
			if(d>1) printf("0\n");
			else printf("1\n");
			continue;
		}

		for(i=0;i<=total;i++)
			count[i]=0;

		for(i=0;n>=prime[i] && i<=total;i++)
		{
			temp=n;
			while((long long)(temp/prime[i])!=0)
			{
				count[i]+=(long long)(temp/prime[i]);
				temp/=prime[i];
			}
		}

		temp=d;
		for(i=0;i<=total && temp>1;i++)
		{
			while(temp%prime[i]==0)
			{
				count[i]--;
				if(count[i]<0) {CAN=0; break;}
				temp=temp/prime[i];
			}
			if(!CAN) break;
		}
		if(temp>1) CAN=0;

		if(!CAN) {printf("0\n"); continue;}

		ans=1;

		for(i=0;i<=total;i++)
			if(count[i]>0)
				ans*=(count[i]+1);

		printf("%lld",ans);
		printf("\n");
	}
	return 0;
}
