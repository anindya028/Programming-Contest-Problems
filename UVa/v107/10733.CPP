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
	while(scanf("%lld",&n)==1  && n)
		printf("%lld\n",(n*n*n*n*n*n+3*n*n*n*n+12*n*n*n+8*n*n)/24);
	return 0;
}













