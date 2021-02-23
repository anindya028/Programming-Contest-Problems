//Number Theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define max 1048576
#define Long __int64
bool com[max];
long pr[500000];
bool p[max];
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
	int m=gene(max);
	int i,j,k,num,count;
	for(i=0;i<m;i++)
	{
		if((pr[i]*pr[i])>max)break;
		for(j=i;j<m;j++)
		{
			if((pr[i]*pr[j])<=max)
				com[pr[i]*pr[j]]=true;
			else break;
		}
	}
	while(scanf("%d",&k)==1)
	{
		for(i=count=0;i<k;i++)
		{
			scanf("%d",&num);
			if(com[num])count++;
		}
		printf("%d\n",count);
	}
	return 0;
}













