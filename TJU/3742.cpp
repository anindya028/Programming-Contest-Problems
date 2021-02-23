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

typedef pair<int,int> pii;

#define LL long long

LL fact[22],ncr[25][25];
LL calc(int n,int r)
{
	if(!r || n==r) return 1;
	if(ncr[n][r]!=-1) return ncr[n][r];
	ncr[n][r]= calc(n-1,r) + calc(n-1,r-1);
	return ncr[n][r];
}

LL dp[25][25][2];

LL make(int n,int k,int is)
{
	if(!n)
		return 1;
	if(!k)
		return 0;
	if(dp[n][k][is]!=-1)
		return dp[n][k][is];
	dp[n][k][is]=0;
	int i;
	for(i=is+1;i<=n;i++)
		dp[n][k][is]+= (calc(n-1,i-1)*fact[i-1]*make(n-i,k-1,0));
	return dp[n][k][is];
}

int main()
{
	int t,n,k,i;	
	scanf("%d",&t);
	fact[0]=1;
	for(i=1;i<=20;i++)
		fact[i]=i*fact[i-1];
	mem(ncr,-1);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		mem(dp,-1);
		LL v=make(n,k,1);
		printf("%.4lf\n",v/(fact[n]+0.0));
	}
	return 0;
}