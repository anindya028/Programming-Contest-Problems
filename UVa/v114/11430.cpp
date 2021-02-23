#include<stdio.h>
#include<string.h>

#define LL long long
#define mod 100000000
LL ncr[1005][1005];

LL make(int n,int r)
{
	if(n==r || !r) return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=(make(n-1,r)+make(n-1,r-1))%mod;
	return ncr[n][r];
}

int main()
{
	int i,j,n,sum;
	memset(ncr,-1,sizeof(ncr));
	while(scanf("%d",&n)==1 && n)
	{
		sum=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
			{
				if((j*n)%i)
					continue;
				int k=(j*n)/i;
				if(i+k-j>n)
					continue;
				sum=( sum + (( (make(n,j) * make(n-j,i-j))%mod ) * make(n-i,k-j))%mod )%mod;
			}
		printf("%d\n",sum);
	}
	return 0;
}