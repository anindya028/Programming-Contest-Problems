#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

int main()
{
	int n,i;
	double p,q;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		q=log(4);
		for(i=1960;i<=n;i+=10)
			q*=2;
		i=1;
		p=0;
		while(p<q)
		{
			i++;
			p+=log(i);
		}
		printf("%d\n",i-1);
	}
	return 0;
}
