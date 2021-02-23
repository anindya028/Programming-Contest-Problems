#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 47000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[5000],num;
prime p[size/2];
int gcd(int m,int n)
{
	if(!m)return n;
	return gcd((n%m),m);
}
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
long gener(long n)
{
	long i,*fact,j,max=0;
	fact=(long *)calloc(num,sizeof(long));
	for(i=0,j=0;i<num;i++)
	{
		if(pr[i]*pr[i]>n)break;
		while(n%pr[i]==0)
		{
			fact[i]++;
			n/=pr[i];
		}
		if(fact[i])
		{
			max=gcd(max,fact[i]);
		}
	}
	if(n>1)return 1;
	return max;
}
void main()
{
	long n,max,temp;
        num=gene(size);
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		if(n==-2147483648)
		{
			printf("31\n");
			continue;
                }
		temp=labs(n);
		max=gener(temp);
		if(n<0)
		{
			while(max%2==0)
			{
				max/=2;
			}
		}
		printf("%d\n",max);
	}

}













