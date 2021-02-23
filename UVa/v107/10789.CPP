#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000
struct prime
{
	unsigned m:1;
};
long pr[500];
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
int main()
{
	long m=gene(size*2);
	long n,*freq,*pri,i,j,count;
        char s[2005];
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		freq=(long *)calloc(127,sizeof(long));
		pri=(long *)calloc(127,sizeof(long));
                count=0;
		for(j=0;s[j];j++)freq[s[j]]++;
		for(j=45;j<127;j++)
		{
			if(freq[j])
			{
				if(bisearch(freq[j],m))
				{
					pri[j]=1;
					count++;
                                }
			}
		}
		printf("Case %ld: ",i+1);
		if(!count)
		{
			printf("empty");
		}
		else
                {
			for(j=45;j<127;j++)
			{
				if(pri[j])printf("%c",j);
			}
                }
		printf("\n");
		free(freq);
		free(pri);
        }
	return 0;
}













