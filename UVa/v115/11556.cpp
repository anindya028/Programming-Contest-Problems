#include<stdio.h>

int main()
{
	long long n,b,i,two[60];
	two[0]=1;
	for(i=1;i<60;i++)
		two[i]=two[i-1]*2;
	while(scanf("%lld%lld",&n,&b)==2)
		if(n<two[b+1])
			printf("yes\n");
		else
			printf("no\n");
	return 0;
}
