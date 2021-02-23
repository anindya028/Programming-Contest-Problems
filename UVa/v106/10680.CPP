#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000
struct prime
{
	unsigned m:1;
};
long pr[78498];
long prod[78498];
prime p[size/2];
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
	prod[167]=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i].m)
                {
			pr[j]=i*2+1;
                        if(j>=168)prod[j]=(prod[j-1]*pr[j])%10;
			j++;
                }
	}
        return j;
}
long binsearch(long n,long m)
{
	long low=168,high=m-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(pr[mid]<=n)low=mid;
		else high=mid-1;
	}
	return prod[low];
}
int main()
{
	long m=gene(size);
	long n,digit,fact2,fact5,fact,i;
        double a,b=log(2),c=log(5);
	long f2[]={6,2,4,8};
	long f3[]={1,3,9,7};
	long f7[]={1,7,9,3};
        long f9[]={1,9};
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		if(n<3)
		{
			printf("%ld\n",n);
			continue;
		}
		digit=1;
		a=log(n);
		fact2=floor(a/b);
		fact5=floor(a/c);
		if(fact2>fact5)digit=f2[(fact2-fact5)%4];
		else if(fact5>fact2)
		{
			printf("5\n");
			continue;
                }
		for(i=1;pr[i]<=1000;i++)
		{
			if(i==2)continue;
                        if(pr[i]>n)break;
			fact=floor(log(n)/log(pr[i]));
			if(pr[i]%10==3)digit=(digit*f3[fact%4])%10;
			else if(pr[i]%10==7)digit=(digit*f7[fact%4])%10;
			else if(pr[i]%10==9)digit=(digit*f9[fact%2])%10;
		}
		if(n>1000)
		{
			digit=(digit*binsearch(n,m))%10;
		}
		printf("%ld\n",digit);
        }
	return 0;
}













