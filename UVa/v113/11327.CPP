//Number Theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
#define size 100000
long pr[100000];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
    long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}
Long sum[200005],phi[200005];
int binsearch(Long key)
{
	int low=0,high=200000,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(sum[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(sum[low]>=key)return low;
	else return -1;
}
int gcd(int m,int n)
{
	if(!n) return m;
	else return gcd(n,m%n);
}
int main()
{
	int m=gene(size*2);
	Long n,i,j,k,freq;
	sum[0]=1;
	sum[1]=2;
	phi[1]=1;
	phi[2]=1;
	for(i=2;i<=200000;i++)
	{
		if(i%2 && !p[(i-1)/2])
		{
			phi[i]=i-1;
			sum[i]=sum[i-1]+phi[i];
		}
		else
		{
			k=i;
			for(j=freq=0;j<m ;j++)
			{
				while(k%pr[j]==0)
				{
					k/=pr[j];
					freq++;
				}
				if(freq)
					break;
			}
			if(freq==1)phi[i]=phi[pr[j]]*phi[i/pr[j]];
			else phi[i]=pr[j]*phi[i/pr[j]];
			sum[i]=sum[i-1]+phi[i];
		}
	}
	while(scanf("%lld",&n)==1)
	{
		if(!n)break;
		if(n==1)
		{
			printf("0/1\n");
			continue;
		}
		else if(n==2)
		{
			printf("1/1\n");
			continue;
		}
		k=binsearch(n);
		for(i=1,j=sum[k-1];i<k;i++)
		{
			if(gcd(i,k)==1)
				j++;
			if(j==n)
			{
				printf("%lld/%lld\n",i,k);
				break;
			}
		}
	}
	return 0;
}













