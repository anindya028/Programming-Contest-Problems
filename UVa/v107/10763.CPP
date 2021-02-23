#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long __int64
//#define Long long long
#define size 500005

struct par
{
	int f,s;
	bool taken;
}p[size];

bool operator<(par a,par b)
{
	if(a.f==b.f)
		return a.s<b.s;
	return a.f<b.f;
}

int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(p[mid].f<key)low=mid;
		else high=mid-1;
	}
	if(low<5)
		return 0;
	else
		return low-5;
}

int main()
{
	int n,flag,k,found,sum1,sum2;
	register int i,j;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		sum1=sum2=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].f,&p[i].s),p[i].taken=0,sum1+=p[i].f,sum2+=p[i].s;
		if(n%2 || sum1!=sum2)
		{
			printf("NO\n");
			continue;
		}
		sort(p,p+n);
		flag=1;
		for(i=0;i<n;++i)
		{
			if(p[i].taken)
				continue;
			k=binsearch(p[i].s,n);
			found=0;
			for(j=k;j<n && p[j].f<=p[i].s;++j)
				if(p[j].f==p[i].s && p[j].s==p[i].f && !p[i].taken)
				{
					found=1;
					p[j].taken=1;
					break;
				}
			if(!found)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
