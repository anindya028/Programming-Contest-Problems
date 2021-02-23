#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 500000
long pr[80000];
bool p[size];
struct Count
{
	int n,freq;
}*c;
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
int binsearch(int key,int m)
{ 
	int low=0,high=m-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(pr[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(pr[low]>=key)return low;
	else return 0;
} 
int main()
{
	int m=gene(size*2);
	int i,j,l,u,low,temp[80000],t,k,maxcount,maxnum,flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&l,&u);
		c=(Count *)calloc(1000,sizeof(Count));
		low=binsearch(l,m);
		for(j=0,k=low;(k+1)<m;j++,k++)
		{
			if(pr[k+1]>u)
				break;
			temp[j]=pr[k+1]-pr[k];
		}
		if(!j)
		{
			printf("No jumping champion\n");
			continue;
		}
		sort(temp,temp+j);
		for(k=0,l=0;k<j;l++)
		{
			c[l].n=temp[k];
			while(temp[k]==c[l].n && k<j)
			{
				k++;
				c[l].freq++;
			}
		}
		for(k=maxcount=maxnum=0;k<l;k++)
		{
			if(c[k].freq>maxcount)
			{
				maxcount=c[k].freq;
				maxnum=c[k].n;
			}
		}
		flag=1;
		for(k=0;k<l;k++)
		{
			if(maxcount==c[k].freq && maxnum!=c[k].n)
				flag=0;
		}
		if(!flag)printf("No jumping champion\n");
		else printf("The jumping champion is %d\n",maxnum);
		free(c);
	}
	return 0;
}













