#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	__int64 n;
	while(scanf("%I64d",&n)==1)printf("%I64d\n",3*(2*(((n+1)/2)*(n+1)/2)-1-2));
	return 0;
}













