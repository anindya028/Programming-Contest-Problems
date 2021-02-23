#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-12
struct point
{
	char s;
	double x,y;
}p[20];
double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*fabs((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}
bool tria(double x,double y,double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a1,a2,a3,a4;
	a1=triarea(x,y,x1,y1,x2,y2);
	a2=triarea(x,y,x2,y2,x3,y3);
	a3=triarea(x,y,x3,y3,x1,y1);
	a4=triarea(x2,y2,x3,y3,x1,y1);
	return (a1+a2+a3-eps)<=a4;
}
int  main()
{
	int n,i,j,k,l,flag;
	double max;
	char ans[5];
	while(scanf("%d\n",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			scanf("%c %lf %lf\n",&p[i].s,&p[i].x,&p[i].y);
		for(i=max=0;i<(n-2);i++)
			for(j=i+1;j<(n-1);j++)
				for(k=j+1;k<n;k++)
				{
					for(l=flag=0;l<n;l++)
					{
						if(l!=i&&l!=j&&l!=k)
						{
							if(tria(p[l].x,p[l].y,p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y))
								flag=1;
						}
					}
					if(!flag)
					{
						if(triarea(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y)+eps>max)
						{
							max=triarea(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
							ans[0]=p[i].s;
							ans[1]=p[j].s;
							ans[2]=p[k].s;
						}
					}
				}
		ans[3]='\0';
		printf("%s\n",ans);
	}
	return 0;
}













