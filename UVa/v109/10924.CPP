#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define size 520
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[200];
prime p[size];
long gene(long n)
{
        long i,j;
	for(i=3;(i*i)<=n;i+=2)
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
int bisearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pr[mid]==key)return 1;
		else if(pr[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
void main()
{
	long m=gene(size*2);
        long sum,i;
	char s[21];
	while(gets(s))
	{
		if(s[0]==EOF&&s[1]==NULL)break;
		for(i=0,sum=0;s[i];i++)
		{
			if(islower(s[i]))sum+=(s[i]-'a'+1);
			else if(isupper(s[i]))sum+=(s[i]-'A'+27);
		}
                if(sum==1)printf("It is a prime word.\n");
		else if(bisearch(sum,m))printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
        }
}













