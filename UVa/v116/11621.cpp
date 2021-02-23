#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL long long

int main()
{
	LL i=1,j,lim=100000;
	lim*=lim;
	vector<LL> num;
	while(1)
	{
		if(i>lim)
			break;
		j=1;
		while(i*j<lim)
			num.push_back(i*j),j*=3;
		i*=2;	
	}
	sort(num.begin(),num.end());
	//printf("%d\n",num.size());
	int lo,hi,mid,n;
	while(scanf("%d",&n)==1 && n)
	{
		lo=0,hi=num.size()-1;
		while(lo<hi)
		{
			mid=(lo+hi)/2;
			if(num[mid]>=n)
				hi=mid;
			else
				lo=mid+1;
		}
		printf("%lld\n",num[lo]);
	}
	return 0;
}
