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
	int a,b,cs=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a && !b)break;
		printf("Case %d: %lld\n",++cs,(Long)(a*(a-1)/2)*(Long)(b*(b-1)/2));
	}
	return 0;
}













