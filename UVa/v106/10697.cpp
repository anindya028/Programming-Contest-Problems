#include<stdio.h>
#include<string.h>
#include<math.h>

#define S(a) ((a)*(a))
#define eps 1e-7
#define mabs(a) ((a)>0?(a):-(a))
#define E(a,b) (mabs((a)-(b))<eps)

struct point 
{
	double x,y;
};

bool operator==(point a,point b)
{
	return E(a.x,b.x) && E(a.y,b.y);
}

double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}

bool on_line(point a,point b,point c)
{
	if(mabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}

struct circle
{
	point c;
	double r;
};

circle circle_3point(point a,point b,point c)
{
	double k1 = S(a.x) - S(b.x) + S(a.y) - S(b.y);
	double k2 = S(a.x) - S(c.x) + S(a.y) - S(c.y);
	double k3 = a.x*c.y + b.x*a.y + c.x*b.y - (a.y*c.x + b.y*a.x + c.y*b.x);
	circle ret;
	ret.c.x = (k2*(a.y-b.y) - k1*(a.y-c.y)) / (2*k3);
	ret.c.y = (k1*(a.x-c.x) - k2*(a.x-b.x)) / (2*k3);
	return ret;
}

int main()
{
	int t;
	point a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		if(a==b || b==c || c==a)
		{
			printf("There is an infinity of possible locations.\n");
			continue;
		}
		if(on_line(a,b,c))
		{
			printf("There is no possible location.\n");
			continue;
		}

		circle got=circle_3point(a,b,c);
		
		if(got.c.x+eps<0 && got.c.x+eps>-0.1)
			got.c.x-=0.05;
	//	else
	//		got.c.x+=0.05;

		if(got.c.y+eps<0 && got.c.y+eps>-0.1)
			got.c.y-=0.05;
	//	else
	//		got.c.y+=0.05;
		
		if(mabs(got.c.x)+eps<0.1)
			got.c.x=0;
		if(mabs(got.c.y)+eps<0.1)
			got.c.y=0; 

		printf("The equidistant location is (%.1lf, %.1lf).\n",got.c.x+eps,got.c.y+eps);
	}
	return 0;
}