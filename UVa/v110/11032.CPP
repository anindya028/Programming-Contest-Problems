#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
#include<string>
using namespace std;	

#define size 10000001
bool flag[size+80];
int self[1000000];

int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(self[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(self[low]<=key)
		return low;
	else
		return 0;
}

int binsearch1(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(self[mid]<key)low=mid;
		else high=mid-1;
	}
	if(self[low]<key)
		return low;
	else
		return 0;
}

int calc(int n)
{
	int i,sum,temp;
	for(i=(n>81?(n-81):1);i<=n;i++)
	{
		temp=i;
		sum=0;
		while(temp)
		{
			sum+=(temp%10);
			temp/=10;
		}
		if((sum+i)==n)
			return i;
	}
	return -1;
}

int main()
{
	int t,a,b,temp,j,sum,cs=0;
	register int i;
	char s[1005];
	j=0;
	for(i=1;i<size;i++)
	{
		temp=i;
		sum=0;
		while(temp)
			sum+=temp%10,temp/=10;
		flag[i+sum]=1;
		if(!flag[i])
			self[j]=i,j++;
	}
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
		gets(s);
		printf("Case %d: ",++cs);
		if(sscanf(s,"%d%d",&a,&b)==2)
		{
			if(a==1)
				printf("%d\n",binsearch(b,j)+1);
			else
				printf("%d\n",binsearch(b,j)-binsearch1(a,j));
		}
		else
			sscanf(s,"%d",&a),printf("%d\n",calc(a));
	}
	return 0;
}
