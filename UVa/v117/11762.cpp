#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))

char p[1000005];
int pr[80000],cum[1000005];
double dp[1000005];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
	{
		dp[i] = -1.0;
		if(!p[i])
			pr[j++]=i,cum[i]=cum[i-1]+1;
		else
			cum[i] = cum[i-1];
	}
	return j;
}

double make(int n)
{
	if(n==1)
		return 0.0;
	if(!(dp[n]<0))
		return dp[n];
	dp[n] = 0.0;
	int i,sum=0,temp=n;
	for(i=0;pr[i]*pr[i]<=temp;i++)
		if(temp%pr[i]==0)
		{
			sum++,dp[n] += make(n/pr[i]);
			while(temp%pr[i]==0)
				temp/=pr[i];
		}
	if(temp!=1)
		sum++,dp[n] += make(n/temp);
	dp[n]/=cum[n];
	dp[n]+=1.0;
	dp[n]*=cum[n];
	dp[n]/=sum;
	return dp[n];
}

int main()
{
	gene(1000002);
	int t,cs,n;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		printf("Case %d: %.10lf\n",cs+1,make(n));
	}
	return 0;
}