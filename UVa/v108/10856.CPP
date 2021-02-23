#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1700
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[300],fact[2800000],num,lim,numb[2800000];
prime p[850];
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
int nu(long n)
{
	int count=0,i;
	for(i=0;i<num&&n>1;i++)
	{
		if(pr[i]*pr[i]>n)break;
		if(n%pr[i]==0)
		{
			return (numb[n/pr[i]]+numb[pr[i]]);	
		}
	}
	return 1;
}
long gener(void)
{
	long i;
	numb[2]=1;
	fact[2]=1;
	for(i=3;fact[i-1]<=10000001;i++)
	{
        	numb[i]=nu(i);
		fact[i]=fact[i-1]+numb[i];
	}
        return i;
}
int binsearch(long n)
{
	long low=2,high=lim-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(fact[mid]==n)return mid;
		else if(fact[mid]>n)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
void main()
{
	num=gene(size);
	lim=gener();
        long n,i=1,ans;
	while(scanf("%ld",&n)==1)
	{
		if(n<0)break;
		if(!n)
		{
			printf("Case %ld: 0!\n",i);
                        i++;
			continue;
		}
		ans=binsearch(n);
		if(ans)printf("Case %ld: %ld!\n",i,ans);
		else printf("Case %ld: Not possible.\n",i);
		i++;
        }
}













