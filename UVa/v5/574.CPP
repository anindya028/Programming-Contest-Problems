#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Ans
{
	int a[12];
	int num;
}ans[2000];
bool comp(int a,int b)
{
	return a>b;
}
bool operator<(Ans m,Ans n)
{
	int i;
	for(i=0;i<n.num && i<m.num;i++)
		if(m.a[i]!=n.a[i])
			return m.a[i]>n.a[i];
	return m.a[i-1]>n.a[i-1];
}
int main()
{
	int i,n,t,j,s[12],sum,temp[12],k,l,flag;
	while(scanf("%d%d",&t,&n)==2)
	{
		if(!n && !t)break;
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(l=0,i=1;i<=(1<<n);i++)
		{
			for(j=sum=k=0;j<n;j++)
			{
				if(i & 1<<j)
				{
					sum+=s[j];
					temp[k]=s[j];
					k++;
				}
			}
			if(sum==t)
			{
				ans[l].num=k;
				for(j=0;j<k;j++)
					ans[l].a[j]=temp[j];
				sort(ans[l].a,ans[l].a+k,comp);
				l++;
			}
		}
		sort(ans,ans+l);
		printf("Sums of %d:\n",t);
		if(!l)
		{
			printf("NONE\n");
			continue;
		}
		printf("%d",ans[0].a[0]);
		for(j=1;j<ans[0].num;j++)
			printf("+%d",ans[0].a[j]);
		printf("\n");
		for(i=1;i<l;i++)
		{
			flag=0;
			if(ans[i].num!=ans[i-1].num)
				flag=1;
			else
			{
				for(j=0;j<ans[i].num;j++)
					if(ans[i].a[j]!=ans[i-1].a[j])
						flag=1;
			}
			if(flag)
			{
				printf("%d",ans[i].a[0]);
				for(j=1;j<ans[i].num;j++)
					printf("+%d",ans[i].a[j]);
				printf("\n");
			}
		}
	}
	return 0;
}













