#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define mod 200003
int ncr[500000][15];
int modu(int a,int b)
{
	if(a>=0) return a%b;
	else return b-(abs(a)%b);
}

int main()
{
	int t,i,j,n,low[15],high[15],s,sum,temp,cnt;
	for(i=1;i<500000;i++)
		ncr[i][0]=1;
	ncr[0][0]=ncr[1][1]=1;
	for(i=2;i<500000;i++)
		for(j=1;j<14;j++)
		{
			if(j==i)ncr[i][j]=1;
			else if(j>i)ncr[i][j]=0;
			else ncr[i][j]=(modu(ncr[i-1][j],mod)+modu(ncr[i-1][j-1],mod))%mod;
		}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&s);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&low[i],&high[i]);
			s-=low[i];
			high[i]-=low[i];
		}
		sum=0;
		for(i=1;i<(1<<n);i++)
		{
			for(j=temp=cnt=0;j<n;j++)
			{
				if(i & 1<<j)
				{
					temp+=(high[j]+1);
					cnt++;
				}
			}
			if(temp>s)
				continue;
			if(cnt%2)
				sum=modu((sum+ncr[s-temp+n-1][n-1]),mod);
			else
				sum=modu((sum-ncr[s-temp+n-1][n-1]),mod);
		}
		printf("%d\n",modu((ncr[s+n-1][n-1]-sum),mod));
	}
	return 0;
}

