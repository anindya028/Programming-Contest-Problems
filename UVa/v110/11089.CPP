//Binary search
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int fib[50];
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
int binsearch(int key)
{
	int low=0,high=43,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(fib[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(fib[low]<=key)return low;
	else return -1;
}
int main()
{
	int i,j,n,t,k;
	char ans[50];
	fib[0]=1,fib[1]=2;
	for(i=2;i<44;i++)
		fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		k=binsearch(n);
		n-=fib[k];
		for(i=0;i<k;i++)
			ans[i]='0';
		ans[i]='1';
		ans[i+1]='\0';
		while(n)
		{
			k=binsearch(n);
			ans[k]='1';
			n-=fib[k];
		}
		rev(ans);
		printf("%s\n",ans);
	}
	return 0;
}













