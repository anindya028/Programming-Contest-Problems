#include<stdio.h>

long long no[1000015];

int main()
{
	int i,n,cs=0;
	for(i=0;i<6;i++)
		no[i]=0;
	no[6]=no[7]=1;
	for(i=8;i<1000014;++i)
		no[i]=no[i-3]+(i-4)/2;
	while(scanf("%d",&n)==1 && n)
		printf("Case %d: %lld\n",++cs,no[n]);
}


