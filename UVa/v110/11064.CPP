//Number Theory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define size 25000
bool p[size];
long pr[10000];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j,k=0;
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
int main()
{
	long num=gene(size*2);
	long n,*fact,factor,i,j,b;
        long double count,countby;
	while(scanf("%ld",&n)==1)
	{
		if(n<6)
		{
			printf("0\n");
			continue;
		}
		fact=(long *)calloc(num,sizeof(long));
		for(i=j=0,countby=factor=1,count=b=n;i<num && b>1;i++)
		{
			if(pr[i]*pr[i]>b)break;
			while(b%pr[i]==0)
			{
                        	fact[i]++;
				b/=pr[i];
			}
			if(fact[i])
			{
				count*=(pr[i]-1);
				countby*=pr[i];
				factor*=(fact[i]+1);
			}
		}
		if(b>1)
		{
			factor*=2;
			count*=(b-1);
			countby*=b;
		}
		printf("%ld\n",n-factor+1-(long)(count/countby));
		free(fact);
	}
	return 0;
}













