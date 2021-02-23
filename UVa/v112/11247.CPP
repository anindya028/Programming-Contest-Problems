#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
Long low,high,mid,m,x,ans;
Long binsearch()
{
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(mid*(100-x)<((m-1)*100))low=mid;
		else high=mid-1;
	}
	if(low*(100-x)<((m-1)*100))return low;
	else return 0;
}
int main()
{
	while(scanf("%lld%lld",&m,&x)==2)
	{
		if(!m && !x)break;
		if(!x || x==100 || m==1)
		{
			printf("Not found\n");
			continue;
		}
		low=m;
		high=m*200;
		ans=binsearch();
		if(!ans)
			printf("Not found\n");
		else printf("%lld\n",ans);
	}
	return 0;
}













