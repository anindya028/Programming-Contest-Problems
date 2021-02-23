#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 6005

unsigned long long w[MAX];

int nc = 11;
int coin[] = {1,2,4,10,20,40,100,200,400,1000,2000};

int main()
{
	double X;
	int n,i;

	w[0] = 1;
	
	for(i=0;i<nc;i++)
		for(n=1;n<MAX;n++)
			if(n-coin[i] >= 0)
				w[n]+=w[n-coin[i]];

	while(scanf("%lf",&X)==1)
	{
        	if(!X)break;
		n =(int)(X*20+.5);
		printf("%6.2lf%17llu\n",X,w[n]);
        }
	return 0;
}













