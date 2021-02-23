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

Long memo[25][155];

Long gcd(Long m,Long n)
{
	if(!m)return n;
	return gcd((n%m),m);
}

Long make(int n,int x)
{
	int i;
	Long t;
	if(x<=0)
		return 0;
	if(n==1)
	{
		if(x<=6) return 1;
		else return 0;
	}
	if(memo[n][x]>=0)
		return memo[n][x];
	t=0;
	for(i=1;i<=6;i++)
		t+=make(n-1,x-i);
	memo[n][x]=t;
	return memo[n][x];
}

int main()
{
	int i,n,x,j;
	Long six[25],g,num;
	six[0]=1;
	for(i=1;i<25;i++)
		six[i]=six[i-1]*6;
	for(i=0;i<25;i++)
		for(j=1;j<155;j++)
			memo[i][j]=-1;
	while(scanf("%d%d",&n,&x)==2 && n)
	{
		num=0;
		if(x<=n)
		{
			printf("1\n");
			continue;
		}
		if(x>n*6)
		{
			printf("0\n");
			continue;
		}
		for(i=x;i<=6*n;i++)
			num+=make(n,i);
		g=gcd(num,six[n]);
		printf("%lld/%lld\n",(num/g),(six[n]/g));
	}
	return 0;
}
