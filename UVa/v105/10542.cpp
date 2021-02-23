#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define mabs(a) (((a)>0)?(a):-(a))

LL gcd(LL m,LL n)
{
	if(!n)return m;
	return gcd(n,(m%n));
}

LL calc(vector<LL> now)
{
	LL ret=now[0];
	for(int i=1;i<now.size();i++)
		ret=gcd(ret,now[i]);
	return ret;
}

int main()
{
	int t,cs,i,d;
	LL a[15],b[15],ans;
	vector<LL> num;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&d);
		num.clear();
		for(i=0;i<d;i++)
			scanf("%lld",&a[i]);
		
		ans=0;
		for(i=0;i<d;i++)
		{
			scanf("%lld",&b[i]),num.push_back(mabs(a[i]-b[i]));
			if(!num[i])
				ans=1;
		}
		
		if(ans)
		{
			printf("Case %d: 0\n",cs+1);
			continue;
		}
		
		for(i=1;i<(1<<d);i++)
		{
			vector<LL> temp;
			for(int j=0;j<d;j++)
				if(i & 1<<j)
					temp.push_back(num[j]);
			if(temp.size()%2)
				ans+=calc(temp);
			else
				ans-=calc(temp);
		}
		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}