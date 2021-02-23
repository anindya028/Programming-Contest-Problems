#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 500
long pr[170];
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
int main()
{
	int m=gene(size*2);
	int i,j,k,sum[500002],freq,temp,low,high,len[500002];
	for(i=2;i<=500000;i++)
	{
		temp=i;
		for(j=0;j<m && pr[j]*pr[j]<=temp;j++)
		{
			if(temp%pr[j]==0)
			{
				sum[temp]=pr[j]+sum[temp/pr[j]];
				temp/=pr[j];
				break;
			}
		}
		if(temp==i)
		{
			sum[temp]=temp;
			len[temp]=1;
		}
		else len[i]=len[sum[i]]+1;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&low,&high);
		if(high<low)
		{
			temp=high;
			high=low;
			low=temp;
		}
		for(j=low,freq=0;j<=high;j++)
		{
			if(len[j]>freq)
				freq=len[j];
		}
		printf("Case #%d:\n%d\n",i+1,freq);
	}
	return 0;
}













