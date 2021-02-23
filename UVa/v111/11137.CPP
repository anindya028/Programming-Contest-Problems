//Coin Change
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define max 10005
int nc=21;
int coin[21];
long long w[max];
int main()
{
	int n,i,j;
	for(i=1;i<22;i++)
		coin[i-1]=i*i*i;
	w[0]=1;
	for(i=0;i<nc;i++)
		for(j=1;j<max;j++)
			if(j-coin[i] >= 0)
				w[j]+=w[j-coin[i]];
	while(scanf("%d",&n)==1)
		printf("%lld\n",w[n]);
	return 0;
}













