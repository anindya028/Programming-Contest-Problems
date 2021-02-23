#include<stdio.h>
#include<math.h>

#define pye (2*acos(0.0))
#define mabs(a) ((a)>0?(a):-(a))
#define eps 1e-8
#define E(a,b) (mabs((a)-(b))<eps)

int main()
{
	double l,w,x,y,r,a,v,s;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l,&w,&x,&y,&r,&a,&v,&s)==8)
	{
		if(l<eps)
			break;
		double lx=r,ly=r,rx=l-r,ry=w-r;
		a= (a/180.)*pye;
		double dx=v*cos(a),dy=v*sin(a),t,t1,t2;
		while(s>0)
		{
			if(dx>0)
				t1=(rx-x)/dx;
			else
				t1=(lx-x)/dx;
			if(dy>0)
				t2=(ry-y)/dy;
			else
				t2=(ly-y)/dy;
			if(E(t1,t2))
			{
				t=t1;
				if(t>s)
					t=s;
				x+=(t*dx);
				y+=(t*dy);
				s-=t;
				dx*=-1;
				dy*=-1;
			}
			else if(t1<t2)
			{
				t=t1;
				if(t>s)
					t=s;
				x+=(t*dx);
				y+=(t*dy);
				s-=t;
				dx*=-1;
			}
			else
			{
				t=t2;
				if(t>s)
					t=s;
				x+=(t*dx);
				y+=(t*dy);
				s-=t;
				dy*=-1;
			}
		}
		printf("%.2lf %.2lf\n",x,y);
	}
	return 0;
}
