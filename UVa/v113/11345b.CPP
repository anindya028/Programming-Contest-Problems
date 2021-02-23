#include<stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main()
{
	int x1,x2,y1,y2,rx1,rx2,ry1,ry2,t,m;
	register int i,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;++cs)
	{
		scanf("%d",&m);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		rx1=x1;
		rx2=x2;
		ry1=y1;
		ry2=y2;
		for(i=1;i<m;++i)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			rx1=MAX(x1,rx1);
			rx2=MIN(x2,rx2);
			ry1=MAX(y1,ry1);
			ry2=MIN(y2,ry2);
		}
		if(rx2<=rx1 || ry2<=ry1)
			printf("Case %d: 0\n",cs+1);
		else
			printf("Case %d: %d\n",cs+1,(rx2-rx1)*(ry2-ry1));
	}
	return 0;
}

