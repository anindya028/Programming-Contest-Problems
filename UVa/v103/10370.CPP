#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	int n,i=0,j,m,*s;
	scanf("%d",&n);
	double p,sum,mean,count;
	for(;i<n;i++)
	{
		sum=0.0;
		scanf("%d",&m);
		s=(int *)malloc(m*sizeof(int));
		for(j=0;j<m;j++)
		{
			scanf("%d",&s[j]);
			sum+=s[j];
		}
		mean=sum/m,count=0.0;
		for(j=0;j<m;j++)
		{
			if(s[j]>mean)count++;
		}
		p=count*100/m;
		printf("%.3lf%%\n",p);
		free(s);
	}

}













