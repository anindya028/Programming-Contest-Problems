#include<stdio.h>

int main()
{
	int cs,T,c,d;
	scanf("%d",&T);
	for( cs = 1; cs<=T; cs++)
	{
		scanf("%d%d",&c,&d);
		printf("Case %d: %.2lf\n",cs, c + (d*5)/9.00);
	}
	return 0;
}