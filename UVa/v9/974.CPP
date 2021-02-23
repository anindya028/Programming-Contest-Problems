#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int kap[1000];
int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(kap[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(kap[low]>=key)return low;
	else return -1;
}
int main()
{
	int i,j,count=0,k,a,b,t;
	for(i=9;i<=40000;i++)
	{
		for(j=1;j<8;j++)
		{
			k=(int)pow(10,j);
			a=(i*i)%k;
			b=(i*i)/k;
			if(i==(a+b) && a && b)
			{
				kap[count]=i;
				count++;
			}
		}
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		if(i)printf("\n");
		k=binsearch(a,count);
		printf("case #%d\n",i+1);
		if(k==-1)
		{
			printf("no kaprekar numbers\n");
			continue;
		}
		for(j=k;kap[j]<=b && j<count;j++)
			printf("%d\n",kap[j]);
		if(j==k)
			printf("no kaprekar numbers\n");
	}
	return 0;
}













