#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 1000001

double first[size];
long int second[size];

int main()
{
	double a;
	long int b,n,i,test;
	a=5.0;b=-1;
	first[1]=a;
	second[1]=b;
	for(i=2;i<size;i++)
	{
		a/=2.0;
		if(a<1.0)
		{
			b=b-1;
			a*=10.0;
		}
		first[i]=a;
		second[i]=b;
	}
	while(scanf("%d",&n)==1)
	{
		printf("2^-%ld = %.3lfe%ld\n",n,first[n],second[n]);
	}
	return 0;
}













