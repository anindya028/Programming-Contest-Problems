//Twin Prime
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 10000000
typedef unsigned long int myint;
long pr[1500000];
long p1[100000],p2[100000];
bool p[size];
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
			if((pr[j]-pr[j-1])==2&&k<100000)
			{
				p1[k]=pr[j-1];
				p2[k]=pr[j];
				k++;
			}
			j++;
                }
	}
        return j;
}
void main()
{
	long n;
	long m=gene(size*2);
	while(scanf("%ld",&n)==1)
	{
		printf("(%ld, %ld)\n",p1[n-1],p2[n-1]);
        }
}













