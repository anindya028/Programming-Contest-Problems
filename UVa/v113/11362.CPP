//Binary search + simulation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct tele
{
	char s[15];
	int len;
}p[10005];

bool operator<(tele a,tele b)
{
	if(a.len==b.len)
		return strcmp(a.s,b.s)<0;
	return a.len<b.len;
}


int comp(int a,int b)
{
	int i;
	for(i=0;p[a].s[i];i++)
		if(p[a].s[i]!=p[b].s[i])
			return p[a].s[i]-p[b].s[i];
	return 0;
}

bool binsearch(int low,int high,int key)
{
	int mid,k;
	while(low<=high)
	{
		mid=(low+high)/2;
		k=comp(key,mid);
		if(!k)
			return true;
		else if(k>0)
			low=mid+1;
		else
			high=mid-1;
	}
	return false;
}


int main()
{
	int i,j,n,t,st[15],end[15];
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",&p[i].s);
			p[i].len=strlen(p[i].s);
		}
		sort(p,p+n);
		for(i=1;i<=10;i++)
			st[i]=end[i]=-1;
		for(i=0;i<n;i++)
		{
			st[p[i].len]=i;
			while((i+1)<n && p[i].len==p[i+1].len)
				i++;
			end[p[i].len]=i;
		}
		flag=true;
		for(i=0;i<n && flag;i++)
		{
			for(j=1;j<=10 && flag;j++)
				if(st[j]>=0 && j>
					p[i].len)
					if(binsearch(st[j],end[j],i))
						flag=false;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
