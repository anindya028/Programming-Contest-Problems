//Number Theory,Nasty precision
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 50000
struct prime
{
	unsigned m:1;
};
long pr[9592];
prime p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2].m)
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2].m=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i].m)
                {
			pr[j]=i*2+1;
			j++;
                }
	}
        return j;
}
int bisearch(long key,long m)
{
	long low=0,high=m-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pr[mid]==key)return 1;
		else if(pr[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
void main ()
{
	long m=gene(size*2);
	long j;
	int cum[10001],i=1,k,flag,l,u,num;
        cum[0]=1;
	for(;i<=10000;i++)
	{
		j=i*i+i+41;
		if(j<100000)
		{
			if(bisearch(j,m))cum[i]=cum[i-1]+1;
			else cum[i]=cum[i-1];
		}
		else
		{
			for(k=0,flag=0;k<m;k++)
			{
                        	if(pr[k]*pr[k]>j)break;
				if(j%pr[k]==0)
				{
					flag=1;
					break;
				}
			}
			if(flag)cum[i]=cum[i-1];
			else cum[i]=cum[i-1]+1;
		}
	}
	while(scanf("%d%d",&l,&u)==2)
	{
		if(!l)num=cum[u];
		else num=cum[u]-cum[l-1];
		printf("%.2lf\n",(num*100.00/(u-l+1)+1e-10));
	}
}


