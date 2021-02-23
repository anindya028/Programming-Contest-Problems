#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 50000
//#define Long __int64
//#define Long long long
long pr[9592];
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
int main()
{
	long m=gene(size*2);
        long i;
        long long n;
	while(scanf("%lld",&n)==1)
	{
		if(n<0)break;
		if(n<4)
		{
			printf("    %lld\n\n",n);
                        continue;
		}
		for(i=0;i<m;i++)
		{
			if(pr[i]*pr[i]>n)break;
			while(n%pr[i]==0)
			{
				printf("    %ld\n",pr[i]);
				n/=pr[i];
			}
		}
		if(n>1)printf("    %lld\n",n);
		printf("\n");
	}
	return 0;
}













