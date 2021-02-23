#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int fib[45];
int  binsearch(int key)
{
	int low=1,high=41,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(fib[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(fib[low]<=key) return low;
}
int main()
{
	int i,j,*bin,n,cs,ind;
	fib[0]=fib[1]=1;
	for(i=2;i<45;i++)
		fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d",&n);
		printf("%d = ",n);
		bin=(int *)calloc(41,sizeof(int));
		while(n)
		{
			ind=binsearch(n);
			bin[ind]=1;
			n-=fib[ind];
		}
		for(j=40;!bin[j];j--);
		for(;j;j--)printf("%d",bin[j]);
		printf(" (fib)\n");
		free(bin);
	}
	return 0;
}













