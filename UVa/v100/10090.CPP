#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define inf 100000000

int gcd(int m,int n)
{
	if(!n)return m;
	else return gcd(n,(m%n));
}

void euclid(int u,int v,int &f,int &g)
{
	int up[4]={0,1,0,0},vp[4]={0,0,1,0};
	int q,t[4],i;
	double ft;

	up[3]=u;
	vp[3]=v;
	while(vp[3])
	{
		ft=(double)up[3]/vp[3];
		ft=floor(ft);
		q=(int)ft;
		for(i=1;i<=3;i++)
		{
			t[i]=up[i]-vp[i]*q;
			up[i]=vp[i];
			vp[i]=t[i];
		}
	}
	f=up[1];
	g=up[2];
	return;
}
int main()
{
	int n,n1,n2,gd,u,v,d,e,f,minx,miny;
	long double total,min,c1,c2,t,x,y,x0,y0,start,end;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		scanf("%Lf%d%Lf%d",&c1,&n1,&c2,&n2);
		gd=gcd(n1,n2);
		if(n%gd)
		{
			printf("failed\n");
			continue;
		}
		d=n1/gd;
		e=n2/gd;
		f=n/gd;
		euclid(d,e,u,v);
		x0=u*((long double)f);/////general solution
		y0=v*((long double)f);/////x=x0-e*t,y=y0+d*t.
		start=ceil((-y0)/((long double)d));////this is the range of
		end=floor((x0)/((long double)e));/////values of t.
		if(end<start)
			printf("failed\n");
		else
		{
			min=inf;
			t=start;
			x=x0-e*t;
			y=y0+d*t;
			min=x*c1+y*c2;
			minx=x;
			miny=y;
			t=end;
			x=x0-e*t;
			y=y0+d*t;
			total=x*c1+y*c2;
			if(total<min)
			{
				minx=x;
				miny=y;
				min=total;
			}
			printf("%d %d\n",minx,miny);
		}
	}
	return 0;
}







