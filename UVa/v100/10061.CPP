#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 400
struct prime
{
	unsigned m:1;
};
long pr[150];
prime p[size];
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
long m,n,b,*fact,digit,temp,zero,min,q,freq;
long fac[]  = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
#define PI (2.*acos(0.))
#define E	2.718281828
//long double a1,a2,a3,a4,a5;
void main()
{
	m=gene(size*2);
        long i,j;
	while(scanf("%ld%ld",&n,&b)==2)
	{
		if(n<=1)
		{
			printf("0 1\n");
			continue;
                }
		if(n>10){
			digit = (int)floor(0.5*log(2.*PI*n)/log((double)b) + n*(log((double)n) - 1.)/log(b));
		}
		else
			digit= (int)(floor(log((double)fac[n])/log((double)b)));
		digit++;
		fact=(long *)calloc(m,sizeof(long));
		for(i=0;b!=1;i++)
		{
			while(b%pr[i]==0)
			{
				fact[i]++;
				b/=pr[i];
			}
		}
		for(min=j=q=freq=zero=0;j<i;j++)
		{
			if(fact[j])
			{
				temp=n;
				min=0;
				while(temp)
				{
					min+=temp/=pr[j];
				}
				min/=fact[j];
				if(!zero)zero=min;
                                else if(min<zero)zero=min;
			}
		} 
		printf("%ld %ld\n",zero,digit);
                free(fact);
	}
}













