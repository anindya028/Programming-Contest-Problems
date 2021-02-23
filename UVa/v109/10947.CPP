#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define inf 1000000.
#define eps 1e-12
#define myabs(a) (((a)>0)?(a):-(a))
struct Node
{
	double x,y,r;
}node[105];

int main()
{
	int i,j,n,d[105],pos,mn;
	bool visited[105];
	double m,k,dis;
	while(scanf("%lf%lf",&k,&m)==2)
	{
		scanf("%lf%lf%lf",&node[0].x,&node[0].y,&node[0].r);
		scanf("%lf%lf%lf",&node[1].x,&node[1].y,&node[1].r);
		scanf("%d",&n);
		for(i=2;i<n+2;i++)
			scanf("%lf%lf%lf",&node[i].x,&node[i].y,&node[i].r);
		for(i=0;i<n+2;i++)
		{
			visited[i]=false;
			d[i]=inf;
		}
		d[0]=1;
		while(true)
		{
			mn=inf;
			for(i=0;i<n+2;i++)
				if(!visited[i])
					if(d[i]<mn)
					{
						mn=d[i];
						pos=i;
					}
			if(myabs(mn-inf)<eps)
				break;
			visited[pos]=true;
			for(i=0;i<n+2;i++)
			{
				dis=sqrt((node[i].x-node[pos].x)*(node[i].x-node[pos].x)+(node[i].y-node[pos].y)*(node[i].y-node[pos].y));
				dis-=(node[i].r+node[pos].r);
				if(dis<(k*m+eps))
					d[i]=1;
			}
		}
		if(d[1]==1)
			printf("Larry and Ryan will escape!\n");
		else
			printf("Larry and Ryan will be eaten to death.\n");
	}
	return 0;
}













