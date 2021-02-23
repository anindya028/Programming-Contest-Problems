#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[78498];
prime p[500000];
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
long binsearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pr[mid]==key)return 1;
		else if(pr[mid]>key) high=mid-1;
		else low=mid+1;
	}
	return 0;
}
long binsearch1(long key,long s[],long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(s[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(s[low]<=key)return low;
        else return 0;
}
long binsearch2(long key,long s[],long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(s[mid]<key)low=mid;
		else high=mid-1;
	}
	if(s[low]<key)return low;
        else return 0;
}
void main()
{
	long m=gene(size);
	long *s,temp,i,j,n,t1,t2;
        s=(long *)calloc(m,sizeof(long));
	for(i=0,j=0;i<m;i++)
	{
        	temp=pr[i];
		while(temp)
		{
			s[j]+=(temp%10);
			temp/=10;
		}
		if(binsearch(s[j],m))
		{
                	s[j]=pr[i];
			j++;
                }
                else s[j]=0;
	}
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
        	scanf("%ld%ld",&t1,&t2);
		if(t1==1&&t2==1)printf("0\n");
		else if(t1<=2)printf("%ld\n",binsearch1(t2,s,j)+1);
		else printf("%ld\n",binsearch1(t2,s,j)-binsearch2(t1,s,j));
	}
	free(s);
}













