#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long unsigned __int64
#define Long unsigned long long
Long c[30],t,cs,i,j,ans,p,k,d,n;
Long binsearch(void)
{
	Long low=1,high=1000000,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(((mid*(mid+1)/2)*d)>=k)high=mid;
		else low= mid+1;
	}
	if(((low*(low+1)/2)*d)>=k)
		return low;
	else return 0;
}
int main()
{
	
	scanf("%llu",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%llu",&p);
		for(i=0;i<=p;i++)
			scanf("%llu",&c[i]);
		ans=0;
		scanf("%llu%llu",&d,&k);
		n=binsearch();
		j=1;
		for(i=0;i<=p;i++)
		{
			ans+=c[i]*j;
			j*=n;
		}
		printf("%llu\n",ans);
	}
	return 0;
}













