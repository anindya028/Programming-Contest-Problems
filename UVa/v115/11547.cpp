#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n= (((n*567)/9 + 7492)*235)/47 -498;
		printf("%d\n",(abs(n)%100)/10);
	}
	return 0;
}

