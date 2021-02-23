#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
#define eps 1e-12
#define myabs(a) (((a)>0)?(a):-(a))
#define inf 10000000.

struct point 
{
	double x,y;
}p[105];

struct line
{
	double m,c;
}l[10005];

bool operator<(line a,line b)
{
	if(myabs(a.m-b.m)<eps)
		return a.c<b.c;
	return a.m<b.m;
}
int binsearch(int key)
{
	int low=2,high=1000,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if((mid*(mid-1)/2)==key)return mid;
		else if((mid*(mid-1)/2)<key)low=mid+1;
		else high=mid-1;
	}
	return -1;
}
int main()
{
	int n,i,j,cs,t,gnu,flag,k,count,max;
	double px,py;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=gnu=0;i<n;++i)
		{
			scanf("%lf%lf",&px,&py);
			flag=1;
			for(j=0;j<gnu;j++)
				if(myabs(p[j].x-px)<eps && myabs(p[j].y-py)<eps)
					flag=0;
			if(flag)
			{
				p[gnu].x=px;
				p[gnu].y=py;
				gnu++;
			}
		}
		if(gnu==1)
		{
			printf("Data set #%d contains a single gnu.\n",cs+1);
			continue;
		}
		for(i=k=0;i<gnu;i++)
			for(j=i+1;j<gnu;j++)
			{
				if(myabs(p[i].x-p[j].x)<eps)
				{
					l[k].m=inf;
					l[k].c=p[j].x;
				}
				else 
				{
					l[k].m=(p[i].y-p[j].y)/(p[i].x-p[j].x);
					l[k].c=p[j].y-l[k].m*p[j].x;
				}
				k++;
			}
		sort(l,l+k);
		for(i=max=0;i<k;)
		{
			count=1;
			i++;
			while(i<k)
			{
				if(myabs(l[i].m - l[i-1].m)>eps || myabs(l[i].c - l[i-1].c)>eps) break;
				i++;
				count++;
			}
			if(count>max)
				max=count;
		}
		printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",cs+1,gnu,binsearch(max));
	}		
	return 0;
}













