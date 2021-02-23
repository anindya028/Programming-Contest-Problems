#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int f[1000001],finv[1000001],i,j,n,k;
int binsearch(int key,int n)
{
	int low=1,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(finv[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(finv[low]>=key)return low;
	else return 0;
}
int main()
{	
	f[1]=1;
	f[2]=f[3]=2;
	j=4;
	for(i=3;j<1000001;i++)
	{
		for(k=0;k<f[i] && j<1000001;k++,j++)
			f[j]=i;
	}
	finv[1]=1;
	for(i=2;i<1000000 && finv[i-1]<=2000000000;i++)
	{
		finv[i]=finv[i-1]+f[i];
	}
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("%d\n",binsearch(n,i));
	}
	return 0;
}













