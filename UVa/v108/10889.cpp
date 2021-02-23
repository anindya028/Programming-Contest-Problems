#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL long long

LL binsearch(LL n)
{
	LL lo=0,hi=2000000000,mid;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(mid*mid==n)
			return mid;
		else if(mid*mid<n)
			lo=mid+1;
		else
			hi=mid-1;
	}
	return -1;
}

int main()
{
	LL r,b;
	vector<LL> ans;
	while(scanf("%lld%lld",&r,&b)==2)
	{
		if(!r && !b)
			break;
		ans.clear();
		LL bb=binsearch(8*r+1);
		
		if(bb==-1)
		{
			printf("No. of red balls invalid\n");
			continue;
		}
		LL B1=(2*r+1+bb)/2,B2=(2*r+1-bb)/2;
		if(b*10>=B1*7 && b<=B1)
			ans.push_back(B1-b);
		if(b*10>=B2*7 && b<=B2)
			ans.push_back(B2-b);

		sort(ans.begin(),ans.end());
		if(!ans.size())
			printf("No. of black balls invalid\n");
		else
		{
			printf("%lld",ans[0]);
			if(ans.size()>1)
				printf(" %lld",ans[1]);
			printf("\n");
		}
	}
	return 0;
}