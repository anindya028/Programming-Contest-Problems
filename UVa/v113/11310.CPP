//Linear DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long long long 
//#define Long __int64

int main()
{
	int cs,i,n;
	Long ans[45];
	ans[0]=0;
	ans[1]=1;
	ans[2]=5;
	ans[3]=11;
	for(i=4;i<41;i++)
		ans[i]=ans[i-1]+4*ans[i-2]+2*ans[i-3];
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}













