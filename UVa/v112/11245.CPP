#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
Long fp[100],sp[100],low,high,mid;
Long binsearch(Long key)
{
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(fp[mid]<key)low=mid;
		else high=mid-1;
	}
	if(fp[low]<key)return low;
	else return 0;
}
int main()
{
	Long n,p,k,t,i,j;
	Long sum;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&n,&p);
		fp[0]=sp[0]=1;
		for(j=1;fp[j-1]<n;j++)
		{
			fp[j]=fp[j-1]*(p-1);
			sp[j]=sp[j-1]*p;
		}
		sum=0;
		while(1)
		{
			low=0;
			high=j-1;
			k=binsearch(n);
			if(!k)break;
			sum+=sp[k];
			n-=fp[k];
		}
		sum+=n;
		printf("%lld\n",sum);
	}
	return 0;
}













