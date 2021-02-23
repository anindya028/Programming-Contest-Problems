#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

#define size 10005

int got[size],low[size],high[size];

int main()
{
	int n,i,j;
	for(i=1;((i+1)*(i+1)*(i+1)-i*i*i)<size;i++)
		for(j=i+1;(j*j*j-i*i*i)<size;j++)
			if(!got[j*j*j-i*i*i])
				low[j*j*j-i*i*i]=i,high[j*j*j-i*i*i]=j,got[j*j*j-i*i*i]=1;
	while(scanf("%d",&n)==1 && n)
		if(got[n])
			printf("%d %d\n",high[n],low[n]);
		else
			printf("No solution\n");

	return 0;
}
