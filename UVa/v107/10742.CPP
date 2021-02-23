#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 500000
typedef unsigned long int myint;
long pr[80000];
bool p[size];
int gene(long n)
{
	int root=ceil(sqrt(n));
    register int i,j;
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
int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(pr[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(pr[low]<=key)return low;
	else return 0;
}
int main()
{
	int n,m=gene(size*2),i,j,count,cs=0;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		count=0;
		for(i=0;2*pr[i]<n;i++)
		{
			j=binsearch(n-pr[i],m);
			j-=i;
			count+=j;
		}
		printf("Case %d: %d\n",++cs,count);
	}
	return 0;
}













