#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 1e12
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))

struct point
{
	double x,y;
	point(){x=0,y=0;}
	point(double x0,double y0){x=x0,y=y0;}
};

struct line
{
	double m,c;		//y=mx+c.
	line(){m=1,c=0;}
	line(double m0,double c0){m=m0,c=c0;};
};

struct circle
{
	double cx,cy,rad;	//(x-cx)^2 + (y-cy)^2 = rad^2.
}br[505];

inline double dist(point a,point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}

vector<line> tangent(circle O,point p)
{
	vector<line> ret;
	point q(O.cx,O.cy);
	if(dist(p,q)<O.rad || E(dist(p,q),O.rad))	//point is inside or on circle
		return ret;								//no tangent

	double dx=p.x-O.cx,dy=O.cy-p.y,
		A=sq(dx)-sq(O.rad),
		B=2*dx*dy,C=sq(dy)-sq(O.rad),
		D=sq(B)-4*A*C;
	
	if(Z(A))
	{
		line l1(inf,-p.x),l2(-C/B,p.y + (C/B)*p.x);
		ret.push_back(l1),ret.push_back(l2);
		return ret;
	}

	line l1,l2;
	l1.m=(-B+sqrt(D))/(2*A),l1.c=p.y-l1.m*p.x;
	l2.m=(-B-sqrt(D))/(2*A),l2.c=p.y-l2.m*p.x;
	ret.push_back(l1),ret.push_back(l2);
	return ret;
}

vector< pair<double,double> > seg,ans;

int main()
{
	int n,i;
	point p;
	while(scanf("%d",&n)==1 && n)
	{
		seg.clear(),ans.clear();
		scanf("%lf%lf",&p.x,&p.y);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&br[i].cx,&br[i].cy,&br[i].rad);
		
		for(i=0;i<n;i++)
		{
			vector<line> now=tangent(br[i],p);
			double st,nd; 
			if(E(now[0].m,inf))
				st=-now[0].c;
			else
				st=-now[0].c/now[0].m;	//there should not be any
			nd=-now[1].c/now[1].m;		//line with 0 slope.
			if(nd<st)
				swap(st,nd);
			seg.push_back(make_pair(st,nd));
		}
		sort(seg.begin(),seg.end());
		ans.push_back(seg[0]);
		int j=0;
		for(i=1;i<seg.size();i++)
		{
			if(seg[i].second<ans[j].second || E(seg[i].second,ans[j].second))
				continue;
			if(seg[i].first<ans[j].second || E(seg[i].first,ans[j].second))
				ans[j].second=seg[i].second;
			else
				j++,ans.push_back(seg[i]);
		}
		for(i=0;i<ans.size();i++)
			printf("%.2lf %.2lf\n",ans[i].first,ans[i].second);
		printf("\n");
	}	
	return 0;
}