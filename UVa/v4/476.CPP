#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define eps 1e-6
struct figure
{
	char c;
	double cord[10];
}f[100];
double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return fabs((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}
bool rect(double x,double y,double x1,double y1,double x2,double y2)
{
	return ((x+eps)>x1 && (x+eps)<x2) && ((y+eps)<y1 && (y+eps)>y2);
}
bool cir(double x,double y,double x1,double y1,double r)
{
	return ((x-x1)*(x-x1)+(y-y1)*(y-y1)+eps)<(r*r);
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
int main()
{
	char s;
	int k=0,i,cs=0,flag;
        double x,y;
	while(scanf("%c",&s)==1)
	{
		if(s=='*')break;
                else if(s=='\n')continue;
		f[k].c=s;
		if(s=='r')scanf("%lf%lf%lf%lf",&f[k].cord[0],&f[k].cord[1],&f[k].cord[2],&f[k].cord[3]);
		else if(s=='c')scanf("%lf%lf%lf",&f[k].cord[0],&f[k].cord[1],&f[k].cord[2]);
		else scanf("%lf%lf%lf%lf%lf%lf",&f[k].cord[0],&f[k].cord[1],&f[k].cord[2],&f[k].cord[3],&f[k].cord[4],&f[k].cord[5]);
                k++;
	}
	while(scanf("%lf%lf",&x,&y)==2)
	{
		if(x==9999.9 && y==9999.9)break; 
		cs++;
		for(i=flag=0;i<k;i++)
		{
			if(f[i].c=='r')
			{
				if(rect(x,y,f[i].cord[0],f[i].cord[1],f[i].cord[2],f[i].cord[3]))
				{
					printf("Point %d is contained in figure %d\n",cs,i+1);
					flag=1;
				}
			}
			else if(f[i].c=='c')
			{
				if(cir(x,y,f[i].cord[0],f[i].cord[1],f[i].cord[2]))
				{
					printf("Point %d is contained in figure %d\n",cs,i+1);
					flag=1;
				}
			}
			else
			{
				if(tria(x,y,f[i].cord[0],f[i].cord[1],f[i].cord[2],f[i].cord[3],f[i].cord[4],f[i].cord[5]))
		                {
					printf("Point %d is contained in figure %d\n",cs,i+1);
					flag=1;
				}
			}
		}
		if(!flag)printf("Point %d is not contained in any figure\n",cs);
        }
	return 0;
}













