#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long __int64
#define Long long long

Long memo[70][70],fib[70];

Long make(int n,int s)
{
	int i;
	if(n<s)
		return 0;
	if(s==0)
		return fib[n];
	if(n==s || n==1)
		return 1;
	if(n==2)
	{
		if(s>=1)
			return 1;
		else
			return 2;
	}
	if(memo[n][s])
		return memo[n][s];
	memo[n][s]=make(n-1,s-1);
	for(i=2;i<=(n-s);i++)
		memo[n][s]+=make(n-i,s);
	return memo[n][s];
}

int main()
{
	int i,j,n,s;
	fib[1]=1,fib[2]=2;
	for(i=3;i<67;i++)
		fib[i]=fib[i-1]+fib[i-2];
	for(i=0;i<70;i++)
		for(j=0;j<70;j++)
			memo[i][j]=0;
	while(scanf("%d%d",&n,&s)==2)
	{
		if(n<0 && s<0)
			break;
		printf("%lld\n",make(n,s));
	}
	return 0;
}
