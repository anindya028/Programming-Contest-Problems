#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define max 7500
int nc=5;
int coin[]={1,5,10,25,50};
unsigned long long w[max];
int main()
{
	int n,i,j;
	w[0]=1;
	for(i=0;i<nc;i++)
		for(j=1;j<max;j++)
			if(j-coin[i] >= 0)
				w[j]+=w[j-coin[i]];
	while(scanf("%d",&n)==1)printf("%llu\n",w[n]);
	return 0;
}













