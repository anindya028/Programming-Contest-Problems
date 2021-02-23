#include<stdio.h>
#include<algorithm>

using namespace std;

#define LL unsigned long long

LL mypow(LL b,LL p,LL m)
{
	if(!p)
		return (1%m);
	LL temp;
	if(p%2)
	{
		temp=mypow(b,p-1,m);
		return (temp*b)%m;
	}
	else
	{
		temp=mypow(b,p/2,m);
		return (temp*temp)%m;
	}
}

int main()
{
	LL k,n,t,i,ten[12];
	int cs=0;
	ten[0]=1;
	for(i=1;i<=9;i++)
		ten[i]=ten[i-1]*10;
	while(scanf("%llu%llu%llu",&k,&n,&t)==3 && k && n)
		printf("Case #%d: %llu\n",++cs,mypow(k%ten[t],n,ten[t]));
	return 0;
}