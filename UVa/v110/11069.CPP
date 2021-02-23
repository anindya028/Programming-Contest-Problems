//Linear DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int ans[77],i,n;
	ans[1]=1;
	ans[2]=ans[3]=2;
	for(i=4;i<77;i++)
		ans[i]=ans[i-2]+ans[i-3];
	while(scanf("%d",&n)==1)
		printf("%d\n",ans[n]);
	return 0;
}













