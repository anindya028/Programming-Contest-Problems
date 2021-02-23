#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 500
long pr[168];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
	long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
                {
			pr[j]=i*2+1;
			j++;
		}
	}
	return j;
}
int mu(long n)
{
	int nfact,i,count;
	for(i=count=0;i<168;i++)
	{
		if(pr[i]*pr[i]>n)break;
                nfact=0;
		while(n%pr[i]==0)
		{
			nfact++;
			if(nfact>1)
				return 0;
			n/=pr[i];
		}
		if(nfact)count++;
	}
	if(n>1)count++;
	if(count%2==0)return 1;
	else return -1;
}
void main()
{
	long num=gene(1000);
	long i,Mu[1000005],M[1000005],n;
	Mu[1]=M[1]=1;
	for(i=2;i<=1000000;i++)
	{
		M[i]=mu(i);
		Mu[i]=Mu[i-1]+M[i];
	}
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		printf("%8ld%8ld%8ld\n",n,M[n],Mu[n]);
	}
}