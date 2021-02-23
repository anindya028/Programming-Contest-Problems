#include<stdio.h>

int main()
{
	int n,cs=0;
	while(scanf("%d",&n)==1 && n)
		printf("Case %d: %d\n",++cs,n/2);
	return 0;
}
