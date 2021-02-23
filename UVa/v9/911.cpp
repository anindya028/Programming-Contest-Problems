#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

int memo[105][105],n,k,num[102];

int make(int n,int r)
{
	if(n==r || !r)
		return 1;
	if(memo[n][r])
		return memo[n][r];
	memo[n][r]=make(n-1,r)+make(n-1,r-1);
	return memo[n][r];
}

int poly(int pos,int sum)
{
	if(pos==k)
		return 1;
	int ret=make(n-sum,num[pos])*poly(pos+1,sum+num[pos]);
	return ret;
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&k)==2)
	{
		for(i=0;i<k;i++)
			scanf("%d",&num[i]);
		printf("%d\n",poly(0,0));
	}
	return 0;
}