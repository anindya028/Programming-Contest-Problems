#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define S(a) ((a)*(a))
#define eps 1e-8
#define mabs(a) (((a)>0)?(a):-(a))
#define Z(a) (mabs(a)<eps)
#define E(a,b) (Z((a)-(b)))
#define pi 2.*acos(0.0)

struct point 
{
	double x,y;
};

double D1(point a,point b)
{
	return sqrt(S(a.x-b.x)+S(a.y-b.y));
}

double D2(point a,point b)
{
	return (S(a.x-b.x)+S(a.y-b.y));
}

struct Circle
{
	point cen;
	double rad;
}giv[105];

bool area_and(Circle p,Circle q){
	double d;

	if( p.rad > q.rad )swap(p,q);
	//Now p.rad < q.rad
	d = D1(p.cen,q.cen);

	if( d > p.rad + q.rad || E(d,p.rad + q.rad) || d < q.rad - p.rad )
		return 0;
	return 1;
}

int parent[105],rank[105];

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
	int n,i,j;
	while(scanf("%d",&n)==1 && n>=0)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&giv[i].cen.x,&giv[i].cen.y,&giv[i].rad);
	
		for(i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				int u=find_set(i);
				int v=find_set(j);
				if(u!=v)
				{
					bool a=area_and(giv[i],giv[j]);
					if(a)
						link(u,v);
				}
			}
		int cnt[105]={0};
		for(i=0;i<n;i++)
			cnt[find_set(i)]++;
		int res=0;
		for(i=0;i<n;i++)
			if(res<cnt[i])
				res=cnt[i];
		if(res==1)
			printf("The largest component contains %d ring.\n",res);
		else
			printf("The largest component contains %d rings.\n",res);
	}
	return 0;
}