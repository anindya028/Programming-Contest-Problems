#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	
//#define Long __int64
#define Long long long 

Long calc(Long n)
{
	Long sum=0,i;
	if(n<=0)
		return 0;
	while(n)
	{
		sum+=(n/10)*45;
		for(i=(n/10)*10;i<=n;i++)
			sum+=i%10;
		n/=10;
	}
	return sum;
}

int main()
{
	int p,q;
	while(scanf("%d%d",&p,&q)==2 && p>=0 && q>=0)
		printf("%lld\n",calc(q)-calc(p-1));
	return 0;
}
