#include<stdio.h>
#include<math.h>

#define sq(a) ((a)*(a))
#define eps 1e-9
#define inf 1<<30
#define Min(a,b) (((a)<(b))?(a):(b))

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt(sq(x1-x2)+sq(y1-y2));
}

int main()
{
	int n,m,i,pos1,mn1,x1,y1,x2,y2,p,q;
	while(scanf("%d%d",&n,&m)==2 && n>=0 && m>=0)
	{
		if(!n)
		{
			x1=y1=0;
			goto nd;
		}
		p=(int)floor(sqrt((long double)(n/2))-10.00);
		if(p<0)
			q=0;
		else
			q=p;
		mn1=inf;
		for(i=q;2*i*i-i<=n;i++);
		i--;
		if(n-2*i*i+i<mn1)
			mn1=n-2*i*i+i,pos1=1,p=i;
		for(i=q;2*i*i<=n;i++);
		i--;
		if(n-2*i*i<mn1)
			mn1=n-2*i*i,pos1=2,p=i;
		for(i=q;2*i*i+i<=n;i++);
		i--;
		if(n-2*i*i-i<mn1)
			mn1=n-2*i*i-i,pos1=3,p=i;
		for(i=q;2*(i*i+i)<=n;i++);
		i--;
		if(n-2*(i*i+i)<mn1)
			mn1=n-2*(i*i+i),pos1=4,p=i;
		if(pos1==1)
			x1=mn1,y1=p-mn1;
		else if(pos1==2)
			x1=p-mn1,y1=-mn1;
		else if(pos1==3)
			x1=-mn1,y1=-p+mn1;
		else
		{
			if(!mn1)
				x1=-p;
			else
				x1=-p+mn1-1;
			y1=mn1;
		}
		nd:
		if(!m)
		{
			x2=y2=0;
			goto fin;
		}
		p=(int)floor(sqrt((long double)(m/2))-10.00);
		if(p<0)
			q=0;
		else
			q=p;
		mn1=inf;
		for(i=q;2*i*i-i<=m;i++);
		i--;
		if(m-2*i*i+i<mn1)
			mn1=m-2*i*i+i,pos1=1,p=i;
		for(i=q;2*i*i<=m;i++);
		i--;
		if(m-2*i*i<mn1)
			mn1=m-2*i*i,pos1=2,p=i;
		for(i=q;2*i*i+i<=m;i++);
		i--;
		if(m-2*i*i-i<mn1)
			mn1=m-2*i*i-i,pos1=3,p=i;
		for(i=q;2*(i*i+i)<=m;i++);
		i--;
		if(m-2*(i*i+i)<mn1)
			mn1=m-2*(i*i+i),pos1=4,p=i;
		if(pos1==1)
			x2=mn1,y2=p-mn1;
		else if(pos1==2)
			x2=p-mn1,y2=-mn1;
		else if(pos1==3)
			x2=-mn1,y2=-p+mn1;
		else
		{
			if(!mn1)
				x2=-p;
			else
				x2=-p+mn1-1;
			y2=mn1;
		}
		fin:
		printf("%.2lf\n",dis(x1,y1,x2,y2)+eps);
	}
	return 0;
}