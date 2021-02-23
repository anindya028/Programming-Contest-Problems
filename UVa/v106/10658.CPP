#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long unsigned long long
int main()
{
	Long ans[70];
	int i,n,t;
	ans[0]=ans[1]=0;
	ans[2]=1;
	ans[3]=3;
	for(i=4;i<66;i++)
	{
		ans[i]=ans[i-3]+((Long)1<<(i-2))+((Long)1<<(i-3));
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("%llu\n",ans[n]);
	}
	return 0;
}













