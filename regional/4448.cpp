#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define eps 1e-3
#define mabs(a) ((a)>0?(a):-(a))
#define Z(a) (mabs(a)<eps)
#define E(a,b) (Z((a)-(b)))
const double pye = 2*acos(0.0);

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y){x=_x,y=_y;}
};

double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double angle_ABC(double AB,double BC,double CA)
{
//	if(AB>BC+CA || BC>CA+AB || CA>AB+BC)
//		printf("caught\n");
//	double AB=dist(a,b),BC=dist(b,c),CA=dist(c,a);
	return acos((AB*AB+BC*BC-CA*CA)/(2*AB*BC));
}

double getangle(double dx,double dy)
{
	if(dy<0)
		return 2*pye+atan2(dy,dx);
	return atan2(dy,dx);
}

struct circle
{
	point cen;
	double r;
	circle(){}
	circle(point _cen,double _r){cen=_cen,r=_r;}
}g[5],big;

bool operator<(circle a,circle b)
{
	return a.r>b.r;
}

vector<point> incircle(circle a,circle b)
{
	vector<point> ret;
	double dd = dist(a.cen,b.cen);
	double theta = angle_ABC(a.r,dd,b.r);
	double aplha = getangle(b.cen.x - a.cen.x, b.cen.y - a.cen.y);

	ret.push_back( point( a.cen.x + a.r*cos(aplha+theta), a.cen.y + a.r*sin(aplha+theta) ) );
	ret.push_back( point( a.cen.x + a.r*cos(aplha-theta), a.cen.y + a.r*sin(aplha-theta) ) );
	
	return ret;
}

vector<point> outcircle(circle a,double nowr)
{
	vector<point> ret;
	double theta = angle_ABC(big.r-nowr,big.r-a.r,a.r+nowr);
	double alpha = getangle(a.cen.x,a.cen.y);

	ret.push_back(point( (big.r-nowr)*cos(alpha+theta), (big.r-nowr)*sin(alpha+theta)));
	ret.push_back(point( (big.r-nowr)*cos(alpha-theta), (big.r-nowr)*sin(alpha-theta)));

	return ret;
}

bool is_valid(void)
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=i+1;j<4;j++)
		{
			double dd = dist(g[i].cen,g[j].cen);
			if(dd + 1e-3 < g[i].r+g[j].r)
				return false;
		}

	for(i=0;i<4;i++)
	{
		double dd = dist(g[i].cen,big.cen);
		if(dd + g[i].r - 1e-3 > big.r)
			return false;
	}

	return true;
}

bool fur_check(void)
{
	int i,j;
	//in
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			double dd = dist(g[i].cen,g[j].cen);
			if(!E(dd,g[i].r+g[j].r))
				continue;

			vector<point> vp = incircle( circle(g[i].cen,g[i].r+g[3].r), circle(g[j].cen,g[j].r+g[3].r));
			g[3].cen = vp[0];
			if(is_valid())
				return true;

			g[3].cen = vp[1];
			if(is_valid())
				return true;
		}
	}
	//out
	for(i=0;i<3;i++)
	{
		vector<point> vp = outcircle(g[i],g[3].r);
		g[3].cen = vp[0];
		if(is_valid())
			return true;

		g[3].cen = vp[1];
		if(is_valid())
			return true;
	}
	return false;
}

bool check(void)
{
	g[0].cen.x = big.r - g[0].r, g[0].cen.y = 0;

	double ang = angle_ABC(big.r-g[1].r,big.r-g[0].r,g[0].r+g[1].r);
	g[1].cen.x = cos(ang)*(big.r-g[1].r);
	g[1].cen.y = sin(ang)*(big.r-g[1].r);

	//1st two
	vector<point> vp = incircle( circle(g[0].cen,g[0].r+g[2].r), circle(g[1].cen,g[1].r+g[2].r));
	g[2].cen = vp[0];

	if(fur_check())
		return true;

	g[2].cen = vp[1];
	
	if(fur_check())
		return true;
	
	//outer circle
	int i;
	for(i=0;i<2;i++)
	{
		vp = outcircle(g[i],g[2].r);
		g[2].cen = vp[0];

		if(fur_check())
			return true;

		g[2].cen = vp[1];
	
		if(fur_check())
			return true;
	}
	return false;
}

bool ok(void)
{
	sort(g,g+4);
	do
	{
		if(check())
			return true;
	}while(next_permutation(g,g+4));
	return false;
}

int main()
{
	big.cen.x=big.cen.y=0;
	int cs=0,v,i;
	while(scanf("%d",&v)==1)
	{
		if(!v)
			break;
		cs++;
		
		g[0].r=v/2.0;
		for(i=1;i<4;i++)
			scanf("%lf",&g[i].r),g[i].r/=2.0;

		sort(g,g+4);
		double lo=g[0].r+g[1].r, hi=1000000;
		v=100;
		while(v--)
		{
			big.r = (lo+hi)/2;
			if(ok())
				hi=big.r;
			else
				lo=big.r;
		}
		big.r*=2;
		printf("Case %d: %.0lf\n",cs,big.r);
	}
	return 0;
}
