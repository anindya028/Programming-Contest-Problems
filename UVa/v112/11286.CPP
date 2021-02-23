#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct sub
{
	int a[10];
}s[10009];

bool operator<(sub x,sub y)
{
	if(x.a[0]==y.a[0])
	{
		if(x.a[1]==y.a[1])
		{
			if(x.a[2]==y.a[2])
			{
				if(x.a[3]==y.a[3])
				{
					return x.a[4]<y.a[4];
				}
				return x.a[3]<y.a[3];
			}
			return x.a[2]<y.a[2];
		}
		return x.a[1]<y.a[1];
	}
	return x.a[0]<y.a[0];
}
bool equal(sub x,sub y)
{
	int i;
	for(i=0;i<5;i++)
		if(x.a[i]!=y.a[i])
			return false;
	return true;
}
int main()
{
	int i,j,n,c,m,t;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
				scanf("%d",&s[i].a[j]);
			sort(s[i].a,s[i].a+5);
		}
		sort(s,s+n);
		m=1;
		t=1;
		for(i=1;i<n;i++)
		{
			c=1;
			while(equal(s[i],s[i-1]))
			{
				i++;
				c++;
				if(i==n)break;
			}
			if(c>m)
			{
				m=c;
				t=1;
			}
			else if(c==m)
				t++;
		}
		if(m==1)
			printf("%d\n",n);
		else
			printf("%d\n",m*t);
	}
	return 0;
}













