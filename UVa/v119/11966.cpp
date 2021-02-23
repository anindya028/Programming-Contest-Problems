#include<stdio.h>
#include<math.h>

#define Max 1005

struct point            /////////////////node
{
	double x,y;
}p[Max];

int parent[Max],rank[Max];

double Dist(point a,point b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
///path-compression
void link(int a,int b)
{
	if(rank[a]>rank[b])
		parent[b]=a;
	else
	{
		parent[a]=b;
		if(rank[a]==rank[b])
			rank[b]=rank[b]+1;
	}
	return;
}
////finding the root of set
int find_set(int a)
{
	if(a!=parent[a])
		parent[a]=find_set(parent[a]);
	return parent[a];
}

int main()
{
	int i,n,t,cs,j;
	double d;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%lf",&n,&d);
		d*=d;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			rank[i] = 0;
			parent[i] = i;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				double va = Dist(p[i],p[j]);
				if(va>d)
					continue;
				int u = find_set(i);
				int v = find_set(j);
				if(u!=v)
					link(u,v);
			}
		int cnt = 0;
		for(i=0;i<n;i++)
			if(find_set(i)==i)
				cnt++;
		printf("Case %d: %d\n",cs+1,cnt);
	}
	return 0;
}