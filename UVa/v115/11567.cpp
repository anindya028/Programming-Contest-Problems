#include<stdio.h>
#include<map>
using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))

map<long long,int> mp;

int make(long long n)
{
	if(n==1)
		return 1;
	if(mp.find(n)!=mp.end())
		return mp[n];
	if(n%2)
	{
		int a=make(n+1),b=make(n-1);
		mp[n]=1+Min(a,b);
	}
	else
		mp[n]=1+make(n/2);
	return mp[n];
}

int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		mp.clear();
		if(!n)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",make(n));
	}
	return 0;
}