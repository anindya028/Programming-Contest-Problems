#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
__int64 ans[60];
int main()
{
	int i,n;
	ans[0]=ans[1]=1;
	for(i=2;i<52;i++)
		ans[i]=ans[i-1]+ans[i-2];
	while(scanf("%d",&n)==1 && n)printf("%I64d\n",ans[n]);
	return 0;
}













