#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 31600
long pr[20000],sumpr[20000];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
    long i,j,temp;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	sumpr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			temp=pr[j];
			while(temp)
			{
				sumpr[j]+=(temp%10);
				temp/=10;
			}
			j++;
        }
	}
    return j;
}
int main()
{
	int n,m=gene(size*2),i,j,l,sum1,sum2,temp,cs;
	scanf("%d",&cs);
	for(l=0;l<cs;l++)
	{
		scanf("%d",&n);
		for(i=n+1;;i++)
		{
			temp=i;
			sum1=0;
			while(temp)
			{
				sum1+=(temp%10);
				temp/=10;
			}
			temp=i;
			for(j=sum2=0;j<m;j++)
			{
				if(pr[j]*pr[j]>temp)
					break;
				while(temp%pr[j]==0)
				{
					sum2+=sumpr[j];
					temp/=pr[j];
				}
			}
			if(temp==i)
				continue;
			if(temp>1)
			{
				while(temp)
				{
					sum2+=(temp%10);
					temp/=10;
				}
			}
			if(sum2==sum1)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}













