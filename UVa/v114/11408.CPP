//Number Theory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define SIZE 2500001
int pr[348600];
bool p[SIZE];
int gene(int n)
{
        int i,j;
	for(i=3;i*i<=n;i+=2)
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

int cum[5000001];
bool deprime[5000001];

int main()
{
	int m=gene(SIZE*2);
	int n,cnt,sum,k,a,b,flag;
	register int i,j;
	for(i=2;i<5000001;i++)
	{
		n=i;
		cnt=sum=flag=0;
		if(!p[(i-1)/2] && i%2)
		{
			deprime[i]=true;
			cum[i]=cum[i-1]+1;
			continue;
		}
		for(j=0;pr[j]*pr[j]<=n && j<m;j++)
		{
			if(n%2 && !p[(n-1)/2])
				break;
			k=0;
			while(n%pr[j]==0)
			{
				n/=pr[j];
				k++;
			}
			if(k>1)
			{
				if(deprime[i/pr[j]])
					flag=1;
				else
					flag=2;
				break;
			}
			else if(k==1)
			{
				cnt++;
				sum+=pr[j];
			}
		}
		if(n!=1)
		{
			cnt++;
			sum+=n;
		}
		if(n==i || flag==1 || (!p[(sum-1)/2] && !flag && sum%2))
		{
			deprime[i]=true;
			cum[i]=cum[i-1]+1;
		}
		else
		{
			deprime[i]=false;
			cum[i]=cum[i-1];
		}
	}
	while(scanf("%d%d",&a,&b)==2 && a>=2 && b>=a)
		printf("%d\n",cum[b]-cum[a-1]);
	return 0;
}
