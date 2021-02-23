#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

#define SIZE 1050

using namespace std;

int a[SIZE];
int b[SIZE];

int main(void)
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		int index=0;
		int sum=0;
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(sum<a[i])
			{
				b[index++]=a[i];
				sum+=a[i];
				cnt++;
			}
			else
			{
				sum-=a[i-1];
				sum+=a[i];
				b[index]=a[i];				
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
