//O(n*T/2*n/2)->TLE,TLE,TLE
//Knapsack
/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define myabs(a) (((a)>0)?(a):-(a))

struct memo
{
	int now[53],tot;
}dp[25005];
int is[25005][55],isd[25005],as[25005];

int main()
{	
	int cs,t,num[105],sum,n,mn,m;
    int i,j,k;
	scanf("%d",&t);
	mem(is,-1),mem(isd,-1);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		
		scanf("%d",&n);
		for(i=sum=0;i<n;i++)
			scanf("%d",&num[i]),sum+=num[i];

		//mem(is,0),mem(isd,0);
		m=1;
		for(i=0;i<=(sum/2);i++)
			dp[i].tot=0;
		dp[0].now[0]=0;
		dp[0].tot=1;
		as[0]=0;
		isd[0]=cs;
		is[0][0]=cs;

		for(i=0;i<n;i++)
		{
			
			for(j=m-1;j>=0;j--)
				for(k=0;k<dp[as[j]].tot;k++)
				{
					int len=dp[as[j]].now[k]+1;
					if(len>(n/2+1))
						continue;
					if(as[j]+num[i]>(sum/2))
						continue;
					if(isd[as[j]+num[i]]!=cs)
					{
						as[m]=(as[j]+num[i]),m++;
						isd[as[j]+num[i]]=cs;
						dp[as[j]+num[i]].now[dp[as[j]+num[i]].tot]=len;
						dp[as[j]+num[i]].tot++;
						is[as[j]+num[i]][len]=cs;
					}
					else if(is[as[j]+num[i]][len]!=cs)
						dp[as[j]+num[i]].now[dp[as[j]+num[i]].tot]=len,
						dp[as[j]+num[i]].tot++,
						is[as[j]+num[i]][len]=cs;
				}
		}
		
		mn=1000000;
		for(i=0;i<=(sum/2);i++)
			if( (is[i][(n+1)/2]==cs || is[i][n/2]==cs) && myabs(i-(sum-i))<mn)
				j=i,mn=myabs(i-(sum-i));
		if(j<sum-j)
			printf("%d %d\n",j,sum-j);
		else
			printf("%d %d\n",sum-j,j);
	}
	return 0;
}

*/
//bitmap-AC
#include<stdio.h>
#include<string.h>

#define LL long long
#define mabs(a) (((a)>0)?(a):-(a))

LL dp[45000],temp;

int main()
{
	int t,cs,i,j,num[105],n,sum,mn;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d",&n);
		for(i=sum=0;i<n;i++)
			scanf("%d",&num[i]),sum+=num[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=0;i<n;i++)
			for(j=sum;j>=0;j--)
				if(dp[j] && j+num[i]<=sum)
					temp=dp[j],dp[j+num[i]]|=(temp<<1);
		mn=sum+100;
		for(i=0;i<=sum;i++)
			if(dp[i] & (LL)(1)<<(n/2))
				if(mabs(2*i-sum)<mn)
					mn=mabs(2*i-sum),j=i;
		if(j>sum-j)
			j=sum-j;
		printf("%d %d\n",j,sum-j);
	}
	return 0;
}