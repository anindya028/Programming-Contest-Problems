//Number Theory + searching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define size 500000
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
		temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
long pr[80000];
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
long bisearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pr[mid]==key)return pr[mid];
		else if(pr[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
int main()
{
	long m=gene(size*2);
	long n,na;
        char temp1[10],temp2[10];
	while(scanf("%ld",&n)==1)
	{
		if(n<2)
		{
			printf("%ld is prime.\n",n);
			continue;
		}
		if(bisearch(n,m))
		{
			sprintf(temp1,"%ld",n);
			strcpy(temp2,temp1);
			rev(temp2);
			if(!strcmp(temp2,temp1))printf("%ld is prime.\n",n);
			else
			{
				sscanf(temp2,"%ld",&na);
				if(bisearch(na,m))printf("%ld is emirp.\n",n);
				else printf("%ld is prime.\n",n);
			}
		}
		else printf("%ld is not prime.\n",n);
	}
	return 0;
}













