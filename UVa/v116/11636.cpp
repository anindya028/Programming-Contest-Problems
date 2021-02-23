#include<stdio.h>
#include<math.h>

int main()
{
	int n,cs=0;
	while(scanf("%d",&n)==1 && n>0)
		printf("Case %d: %.0lf\n",++cs,ceil(log((double)n)/log(2.0)));
	return 0;
}