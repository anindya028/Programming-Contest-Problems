#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long 
int main()
{
	Long n;
	int cs=0;
	while(scanf("%lld",&n)==1)
	{
		if(!n)break;
		if(n%2)printf("Case %d: %lld\n",++cs,((n+3)*(n+3)+24)/48);
		else printf("Case %d: %lld\n",++cs,(n*n+24)/48);
	}
	return 0;
}













