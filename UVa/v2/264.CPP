#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,a,b,c;
	while(scanf("%d",&t)==1)
	{
		n=(int)floor((-1+sqrt(1.+8.*t))/2.);
		if((n*(n+1)/2)>=t)
			n--;
		if(n%2==0)
		{
			c=n*(n+1)/2;
			a=(n+1)-(t-c-1);
			b=n+2-a;
			printf("TERM %d IS %d/%d\n",t,a,b);
		}
		else
		{
			c=c=n*(n+1)/2;
			a=t-c;
			b=n+2-a;
			printf("TERM %d IS %d/%d\n",t,a,b);
		}
	}
	return 0;
}













