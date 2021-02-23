#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define LL long long

vector<LL> lucky,vl;
LL mx;
LL a,b;
map<LL,int> mp;

void bktk1(LL now)
{
	if(now*10>mx)
		return;
	lucky.push_back(now*10+4);
	bktk1(now*10+4);
	lucky.push_back(now*10+7);
	bktk1(now*10+7);
}

void bktk2(LL now,int pos)
{
	if(pos==lucky.size())
		return;
	if(now>1000000 && lucky[pos]>1000000)
		return;
	if(now*lucky[pos]>mx)
		return;
	bktk2(now,pos+1);
	LL k=now;
	if(lucky[pos]>1000000)
	{
		k*=lucky[pos];
		if(mp.find(k)==mp.end())
		{
			mp[k]=1;
			vl.push_back(k);
		}
		return;
	}
	
	while(k*lucky[pos]<=mx)
	{
		k*=lucky[pos];
		if(mp.find(k)==mp.end())
		{
			mp[k]=1;
			vl.push_back(k);
			bktk2(k,pos+1);
		}
	}
}

int binsearch(LL key)
{
	int lo=0,hi=vl.size()-1,mid;
	if(key<4)
		return 0;
	while(lo<hi)
	{
		mid=(lo+hi+1)/2;
		if(vl[mid]<=key)
			lo=mid;
		else
			hi=mid-1;
	}
	return lo+1;
}

int main()
{
	mx=1;
	int i;
	for(i=1;i<=12;i++)
		mx*=10;
	lucky.clear();
	vl.clear();
	mp.clear();
	bktk1(0);
	sort(lucky.begin(),lucky.end());
	bktk2(1,0);
	sort(vl.begin(),vl.end());
	//printf("%d\n",vl.size());
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%d\n",binsearch(b)-binsearch(a-1));		
	}
	return 0;
}