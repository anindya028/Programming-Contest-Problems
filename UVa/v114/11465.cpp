#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))

int dp[32][32];
int make(int m,int r)
{
	if(!r || m==r)
		return 1;
	if(dp[m][r]!=-1)
		return	dp[m][r];
	dp[m][r]=make(m-1,r)+make(m-1,r-1);
	return dp[m][r];
}

int num[50],ans,n;

LL tot[50],now;

void bktk(int pos,int rem,LL sum)
{
	if(n-pos<rem)
		return;
						
	if(sum>now)
	{
		ans+=make(n-pos,rem);
		return;
	}

	if(now-sum>=(tot[pos+rem-1]-tot[pos-1]))
		return;

	bktk(pos+1,rem,sum);
	if(rem)
		bktk(pos+1,rem-1,sum+num[pos]);
		
}

int main()
{
	int t,cs,i,k,j,l;
	mem(dp,-1);
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		reverse(num,num+n);
		
		tot[0]=num[0];
		for(i=1;i<n;i++)
			tot[i]=tot[i-1]+num[i];
				
		ans=0;
		for(i=0;i<n;i++)
		{
			now=num[i];
			bktk(i+1,k-1,0);
		}
		
		printf("Case %d: %d\n",cs+1,ans);
	}
	
	return 0;
}
