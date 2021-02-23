#include<stdio.h>
#include<string.h>
#include<math.h>
int fact[10005];
void gene(void)
{
	fact[0]=1;
	int i;
	for(i=1;i<=10000;i++)
	{
		fact[i]=fact[i-1]*i;
		while(fact[i]%10==0)
		{
			fact[i]/=10;
		}
		fact[i]%=100000;
	}
	return;
}
int main()
{
	gene();
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%5d -> %d\n",n,fact[n]%10);
	}
	return 0;
}