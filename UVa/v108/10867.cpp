#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 1e12
#define eps 1e-8
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))
#define pye (2*acos(0.0))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

struct point
{
	double x,y;
	point(){x=0,y=0;}
	point(double x0,double y0){x=x0,y=y0;}
}poly[1005];

inline double dist(point a,point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}

inline double dotProduct(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}

point intersect(point a,point b,point c,point d) //AB & CD not parallel
{
	double denom,num,t;
	point n(d.y-c.y,c.x-d.x),ba(b.x-a.x,b.y-a.y),ac(a.x-c.x,a.y-c.y);
	denom=dotProduct(n,ba);
	num=dotProduct(n,ac);
	t=-num/denom;
	point ret(a.x+t*(b.x-a.x),a.y+t*(b.y-a.y));
	return ret;
}

enum{outside=0,inside=1};

inline double triarea(point a,point b,point c)
{
	return 0.5*((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

bool on_line(point a,point b,point c)
{
	if(Z(triarea(a,b,c)))
		return true;
	return false;
}

bool interior(point a,point b,point c)//for determining whether a point is within line segment
{
	if( (c.x<Max(a.x,b.x) || E(c.x,Max(a.x,b.x))) 
	&&  (c.x>Min(a.x,b.x) || E(c.x,Min(a.x,b.x)))
	&&  (c.y<Max(a.y,b.y) || E(c.y,Max(a.y,b.y)))
	&&  (c.y>Min(a.y,b.y) || E(c.y,Min(a.y,b.y))) )
		return true;
	else return false;
}

int inpoly(int n,point p)
{
	int i,counter=0;
	double xinters;
	point p1,p2;
	p1=poly[0];
	for(i=0;i<n;i++)
		if(on_line(poly[i],poly[(i+1)%n],p) && interior(poly[i],poly[(i+1)%n],p))
			return (inside);
	if(n==2)
		return (outside);
	for(i=1;i<=n;i++)
	{
		p2=poly[i%n];
		if(p.y>min(p1.y,p2.y))
		{
			if(E(p.y,Max(p1.y,p2.y)) || p.y<Max(p1.y,p2.y))
			{
				if(p.x<Max(p1.x,p2.x))
				{
					if(!E(p1.y,p2.y))
					{
						xinters=(p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
						if(E(p1.x,p2.x) || p.x<xinters || E(p.x,xinters))
							counter++;
					}
				}
			}
		}
		p1=p2;
	}
	if(counter%2==0)return (outside);
	else  return (inside);
}

bool operator< (point a,point b)
{
	if(E(a.x,b.x))
		return a.y<b.y;
	return a.x<b.x;
}

bool operator== (point a,point b)
{
	return E(a.x,b.x) && E(a.y,b.y);
}

vector< pair<point,point> > seg;
vector<point> now;

int main()
{
//	freopen("10867.out","w",stdout);
	int n,m,i,j;
	point A,B;
	double ans;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m) 
			break;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&poly[i].x,&poly[i].y);
		poly[n]=poly[0];
		while(m--)
		{
			scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
			seg.clear();
			now.clear();
			ans=0.;
			point fir(-100000000,-100000000),sec;		//now unnecessary
			now.push_back(fir);
			for(i=0;i<n;i++)
			{
				if(on_line(A,B,poly[i+1]) && on_line(A,B,poly[i]))
				{
					now.push_back(poly[i]);
					continue;
				}

				double a1=triarea(A,B,poly[i]),a2=triarea(A,B,poly[i+1]);
				if(a2*a1<0 || on_line(A,B,poly[i+1]) || on_line(A,B,poly[i]))
				{
					sec=intersect(A,B,poly[i],poly[i+1]);
					now.push_back(sec);
				}
			}
			
			sort(now.begin(),now.end());
			
			for(i=0;i<now.size()-1;i++)
			{	
				point mid((now[i].x+now[i+1].x)/2,(now[i].y+now[i+1].y)/2);
				if(inpoly(n,mid))
					seg.push_back(make_pair(now[i],now[i+1]));
			}

			for(i=0;i<seg.size();i++)
				ans+=dist(seg[i].first,seg[i].second);

			printf("%.3lf\n",ans);
		}
	}
	return 0;
}