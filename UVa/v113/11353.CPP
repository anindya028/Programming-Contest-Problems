//Number Theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define size 1000
#define siz 2000005
int pr[500];
bool p[size];

struct answer
{
	int num,fact;
}ans[siz];

int gene(int n)
{
	int root=ceil(sqrt(n));
    int i,j;
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

bool operator<(answer a,answer b)
{
	if(a.fact==b.fact)
		return a.num<b.num;
	return a.fact<b.fact;
}

int main()
{
	int m=gene(size*2);
	int n,i,j,cs=0,k;
	for(i=1;i<siz-2;i++)
	{
		ans[i].num=i;
		ans[i].fact=0;
	}
	for(i=2;i<siz-2;i++)
	{
		k=0;
		for(j=0;pr[j]*pr[j]<=i && j<m;j++)
		{
			if(i%pr[j]==0)
			{
				k=pr[j];
				break;
			}
		}
		if(!k)ans[i].fact=1;
		else ans[i].fact=ans[i/k].fact+1;
	}
	sort(ans+1,ans+siz-4);
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("Case %d: %d\n",++cs,ans[n].num);
	}
	return 0;
}

