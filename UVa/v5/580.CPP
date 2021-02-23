#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[31],two[31],n,i;
	two[0]=1;
	for(i=1;i<31;i++)
		two[i]=two[i-1]*2;
	a[1]=2;
	a[2]=4;
	a[3]=7;
	for(i=4;i<31;i++)
		a[i]=a[i-1]+a[i-2]+a[i-3];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("%d\n",two[n]-a[n]);
	}
	return 0;
}













