#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define S(a) ((a)*(a))
#define inf 1e12
#define eps 1e-9
#define mabs(a) ((a)>0?(a):-(a))
#define Z(a) (mabs(a)<eps)
#define E(a,b) (Z((a)-(b)))
#define Max(a,b) ((a)>(b)?(a):(b))

struct position
{
	double x;
	position(double _x){x=_x;}
};

bool operator<(position a,position b)
{
	return a.x<b.x;
}

bool operator==(position a,position b)
{
	return E(a.x,b.x);
}

struct point 
{
	double x,y;
	point(){}
	point(double _x,double _y){x=_x,y=_y;}
};

double dist(point a,point b)
{
	return sqrt(S(a.x-b.x) + S(a.y-b.y));
}

struct triangle
{
	point left,right,top;
	triangle(){}
	triangle(point _left,point _right,point _top){left=_left,right=_right,top=_top;}
}tri[105];

double dotProduct(point a,point b)
{
  return a.x*b.x+a.y*b.y;
}

/* intersection of b-a and d-c : t of b-a */
double intersect(point a,point b,point c,point d)
{
  double denom,num,t;
  point n(d.y-c.y,c.x-d.x),ba(b.x-a.x,b.y-a.y),ac(a.x-c.x,a.y-c.y);
  
  denom=dotProduct(n,ba);
  if(Z(denom))
    return inf;
  
  num=dotProduct(n,ac);
  t=-num/denom;
  if(t<0 || t>1)
	  return inf;
  return t;
}

int main()
{
	int i,n,j,cs=0;
	double b,xx,h,mxy;
	set<position> allx;
	while(scanf("%d",&n)==1 && n)
	{
		mxy = 0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&xx,&h,&b);
			tri[i].left.x = xx-b/2;
			tri[i].left.y = 0;

			tri[i].right.x = xx+b/2;
			tri[i].right.y = 0;

			tri[i].top.x = xx;
			tri[i].top.y = h;
			if(h>mxy) mxy = h;
		}
		
		allx.clear();
		double t;
		for(i=0;i<n;i++)
		{
			allx.insert(position(tri[i].left.x));
			allx.insert(position(tri[i].right.x));
			allx.insert(position(tri[i].top.x));
			for(j=i+1;j<n;j++)
			{
				t = intersect(tri[i].left,tri[i].top,tri[j].left,tri[j].top);
				if(!E(t,inf))
					allx.insert( position( tri[i].left.x + t *(tri[i].top.x - tri[i].left.x) ));

				t = intersect(tri[i].left,tri[i].top,tri[j].right,tri[j].top);
				if(!E(t,inf))
					allx.insert( position( tri[i].left.x + t *(tri[i].top.x - tri[i].left.x) ));

				t = intersect(tri[i].right,tri[i].top,tri[j].left,tri[j].top);
				if(!E(t,inf))
					allx.insert( position( tri[i].right.x + t *(tri[i].top.x - tri[i].right.x) ));

				t = intersect(tri[i].right,tri[i].top,tri[j].right,tri[j].top);
				if(!E(t,inf))
					allx.insert( position( tri[i].right.x + t *(tri[i].top.x - tri[i].right.x) ));
			}
		}

		vector<position> vx(allx.begin(),allx.end());
		double sum=0.0,nowy;
		point prev(vx[0].x,0);
		for(i=1;i<vx.size();i++)
		{
			nowy = 0.0;
			for(j=0;j<n;j++)
			{
				t = intersect(tri[j].left,tri[j].top,point(vx[i].x,0),point(vx[i].x,mxy+10));
				if(!E(t,inf))
					nowy = Max(nowy, tri[j].left.y + t*(tri[j].top.y - tri[j].left.y));
				
				t = intersect(tri[j].right,tri[j].top,point(vx[i].x,0),point(vx[i].x,mxy+10));
				if(!E(t,inf))
					nowy = Max(nowy, tri[j].right.y + t*(tri[j].top.y - tri[j].right.y));
			}
			if( !Z(prev.y) || !Z(nowy))
				sum += dist(prev,point(vx[i].x,nowy));
			
			prev.x = vx[i].x;
			prev.y = nowy;
		}
		printf("Case %d: %.0lf\n\n",++cs,sum);
	}
	return 0;
}