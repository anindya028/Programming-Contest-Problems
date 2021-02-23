#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
int main(void)
{
	int n,*p,j=0,i,sum,mean,move;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		p=(int *)malloc(n*sizeof(int));
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		mean=sum/n,move=0;
		for(i=0;i<n;i++)
		{
			if(p[i]<mean)move+=(mean-p[i]);
		}
		printf("Set #%d\n",j+1);
		printf("The minimum number of moves is %d.\n\n",move);
		j++;
                free(p);
	}
	return 0;
}













