#include<stdio.h>

#define sq(a) ((a)*(a))
#define Max(a,b) (((a)>(b))?(a):(b))

struct point
{
	int x,y;
}p[30];
int rad[30],n;

int dist(point a,point b)
{
	return (sq(a.x-b.x)+sq(a.y-b.y));
}

int ok(int state)
{
	bool is[20];
	int i,flag=1,j,tot=0;
	for(i=0;i<n;i++)
		if(state & 1<<i)
			is[i]=true,tot+=sq(rad[i]);
		else
			is[i]=false;
	for(i=0;i<n;i++)
		if(is[i])
			for(j=i+1;j<n;j++)
				if(is[j] && dist(p[i],p[j])<=sq(rad[i]+rad[j]))
					return 0;
	return tot;
}

int main()
{
	int i,t,j,ans,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&rad[i]);
		for(i=ans=0;i<(1<<n);i++)
			d=ok(i),
			ans=Max(d,ans);
		printf("%d\n",ans);
	}
	return 0;
}