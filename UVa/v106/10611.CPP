#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 50000
long lady[size],n,m,boy[size],height[2],i;
long binsearch1(long a,long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
        {
		mid=(low+high)/2;
	        if(lady[mid]>a)high=mid;
		else low=mid+1;
	}
	if(lady[low]>a)return lady[low];
        else return 0;
}
long binsearch2(long a,long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
        {
		mid=(low+high+1)/2;
	        if(lady[mid]<a)low=mid;
		else high=mid-1;
	}
	if(lady[low]<a)return lady[low];
        else return 0;
}
void main()
{
	scanf("%ld",&n);
	for(;i<n;i++)
	{
		scanf("%ld",&lady[i]);
        }
	scanf("%ld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%ld",&boy[i]);
        }
	for(i=0;i<m;i++)
	{
		height[1]=binsearch1(boy[i],n);
		height[0]=binsearch2(boy[i],n);
		if(height[0])printf("%lu ",height[0]);
		else printf("X ");
		if(height[1])printf("%lu\n",height[1]);
		else printf("X\n");
        }
}













