//Number Theory
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

#define size 5000
#define Max 4000005
int pr[2000];
bool p[size];
int gene(int n)
{
	int root=ceil(sqrt(n));
        int i,j;
	for(i=3;i<=root;i+=2)
		if(!p[i/2])
			for(j=i*i;j<n+1;j+=(2*i))
                                  p[j/2]=1;
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
		if(!p[i])
			pr[j]=i*2+1,j++;
    return j;
}

int fact[Max],ans[Max];

int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(ans[mid]<=key)
			low=mid;
		else 
			high=mid-1;
	}
	if(ans[low]<=key)
		return low;
}

int main()
{
	int m=gene(size*2);
	ans[0]=1;
	ans[1]=1;
	ans[2]=1;
	fact[2]=1;
	int cnt,n,temp,t;
	register int i,j;
	for(i=3;ans[i-1]<=10000000;i++)
	{
		cnt=0;
		temp=i;
		for(j=0;pr[j]*pr[j]<=temp && j<m;j++)
			if(temp%pr[j]==0)
			{
				cnt=fact[temp/pr[j]]+1;
				temp=1;
				break;
			}
		if(temp!=1)
			cnt++;
		fact[i]=cnt;
		ans[i]=ans[i-1]+fact[i];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",binsearch(n,i-1)+1);
	}
	return 0;
}
