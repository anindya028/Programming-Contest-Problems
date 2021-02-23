//Math-Complex number
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
struct comp
{
	Long a,b;
}c;
int flag;
comp mult(comp x,comp y)
{
	comp temp;
	temp.a=x.a*y.a-x.b*y.b;
	if(temp.a>(Long)(2147483647))flag=0;
	temp.b=x.a*y.b+x.b*y.a;
	return temp;
}
int main()
{
	int t,j,i;
	comp tem;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&c.a,&c.b);
		if(!c.b)
		{
			printf("1\n");
			continue;
		}
		tem=c;
		flag=1;
		for(j=2;;j++)
		{
			tem=mult(tem,c);
			if(!flag || !tem.b)
				break;
		}
		if(!flag)printf("TOO COMPLICATED\n");
		else printf("%d\n",j);
	}
	return 0;
}













