#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Length
{
	int low,high;
}length[11];
struct dict
{
	char a[100];
	int len;
}d[100005];
struct hand
{
	char c;
	int cost;
}*h;
bool operator<(dict x,dict y)
{
	int g=strcmp(x.a,y.a);
	if(x.len==y.len)
		return g<0;
	return x.len<y.len;
}
bool operator<(hand x,hand y)
{
	return x.cost<y.cost;
}
bool binsearch(dict w)
{
	int low=length[w.len].low,high=length[w.len].high-1,mid,b;
	while(low<=high)
	{
		mid=(low+high)/2;
		b=strcmp(d[mid].a,w.a);
		if(!b)return true;
		else if(b>0)high=mid-1;
		else low=mid+1;
	}
	return false;
}
int main()
{
	int n,m,p,v,i,j,k,two[11],maxcost,cos;
	two[0]=1;
	for(i=1;i<=10;i++)
		two[i]=two[i-1]*2;
	dict w;
	char s[100];
	scanf("%d",&n);
	for(i=0,j=0;i<n;i++)
	{
		scanf("%s",s);
		m=strlen(s);
		if(m<=10 && m)
		{
			sort(s,s+m);
			strcpy(d[j].a,s);
			d[j].len=m;
			j++;
		}
	}
	sort(d,d+j);
	n=j;
	for(i=1,j=0;i<=10;i++)
	{
		length[i].low=j;
		while(d[j].len==i && j<n)
			j++;
		length[i].high=j;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&p);
		h=(hand *)calloc(p,sizeof(hand));
		for(j=0;j<p;j++)
		{
			scanf("%s%d",s,&v);
			h[j].c=s[0];
			h[j].cost=v;
		}
		sort(h,h+p);
		maxcost=0;
		for(k=two[p]-1;k;k--)
		{
			for(j=v=cos=0;j<p;j++)
			{
				if(k&(1<<j))
				{
					w.a[v]=h[j].c;
					cos+=h[j].cost;
					v++;
				}
			}
			w.a[v]='\0';
			sort(w.a,w.a+v);
			w.len=v;
			if(binsearch(w) && cos>maxcost)
			{
				maxcost=cos;
			}
		}
		printf("%d\n",maxcost);
		free(h);
	}
	return 0;
}













