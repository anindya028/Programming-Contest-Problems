#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[168],fact[1000001];
prime p[500];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2].m)
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2].m=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i].m)
                {
			pr[j]=i*2+1;
			j++;
                }
	}
        return j;
}
int num(long n)
{
	int count=0,i;
        int root=ceil(sqrt(n));
	for(i=0;i<168&&n>1;i++)
	{
		if(pr[i]>root)break;
		while(n%pr[i]==0)
		{
			count++;
			n/=pr[i];
		}
	}
	if(n>1)count++;
	return count;
}
void gener(void)
{
	long i;
	for(i=2;i<=1000000;i++)
	{
		fact[i]=fact[i-1]+num(i);
	}
        return;
}
int main()
{
	long m=gene(size);
        long n;
	gener();
	while(scanf("%ld",&n)==1)
	{
		printf("%ld\n",fact[n]);
	}
	return 0;
}













