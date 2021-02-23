#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 1e12
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs((a)-(b))<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

struct point
{
	double x,y;
	point(){x=0,y=0;}
	point(double x0,double y0){x=x0,y=y0;}
};

bool operator<(point a,point b)
{
	if(E(a.x,b.x))
		return a.y<b.y;
	return a.x<b.x;
}

bool operator==(point a,point b)
{
	return E(a.x,b.x) && E(a.y,b.y);
}

inline double triarea(point a,point b,point c)
{
	return 0.5*((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
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

bool on_line(point a,point b,point c)
{
	if(Z(triarea(a,b,c)))
		return true;
	return false;
}

bool interdivide(point a,point b,point c)//for determining whether a point is within line segment
{
	if( (c.x<Max(a.x,b.x) || E(c.x,Max(a.x,b.x))) 
	&&  (c.x>Min(a.x,b.x) || E(c.x,Min(a.x,b.x)))
	&&  (c.y<Max(a.y,b.y) || E(c.y,Max(a.y,b.y)))
	&&  (c.y>Min(a.y,b.y) || E(c.y,Min(a.y,b.y))) )
		return true;
	else return false;
}

inline bool right_turn(point a,point b,point c)
{
	if(triarea(a,b,c)>0.)
		return false;
	else return true;
}

bool lineseg_lineseg(point a,point b,point c,point d)//checks whether AB & CD intersects or not
{
	if(a==c || a==d || b==c || b==d)
		return true;
	if((on_line(a,b,c) && interdivide(a,b,c)) || (on_line(a,b,d) && interdivide(a,b,d))
		|| (on_line(c,d,a) && interdivide(c,d,a)) || (on_line(c,d,b) && interdivide(c,d,b)))
		return true;
	if((right_turn(a,b,c) ^ right_turn(a,b,d)) && (right_turn(c,d,a) ^ right_turn(c,d,b)))
		return true;
	return false;
}

struct segment
{
	point a,b;
	double c;
	int ok;
}line;

bool operator<(segment A,segment B)
{
	if(E(A.c,B.c))
	{
		if(A.a==B.a)
			return A.b<B.b;
		return A.a<B.a;
	}
	return A.c<B.c;
}

vector<segment> hor,ver,pls,mns;

bool istri(segment p,segment q,segment r)
{
	if(!lineseg_lineseg(p.a,p.b,q.a,q.b) || !lineseg_lineseg(p.a,p.b,r.a,r.b) || !lineseg_lineseg(r.a,r.b,q.a,q.b))
		return false;
	point i=intersect(p.a,p.b,q.a,q.b);
	point j=intersect(p.a,p.b,r.a,r.b);
	point k=intersect(r.a,r.b,q.a,q.b);
	return !Z(triarea(i,j,k));
}

int make(vector<segment> p,vector<segment> q,vector<segment> r)
{
	int i,j,k,ret=0;
	for(i=0;i<p.size();i++)
		if(p[i].ok)
			for(j=0;j<q.size();j++)
				if(q[j].ok)
					for(k=0;k<r.size();k++)
						if(r[k].ok)
							ret+=istri(p[i],q[j],r[k]);
	return ret;
}

int main()
{
	int n,i,j,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		hor.clear(),ver.clear(),pls.clear(),mns.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&line.a.x,&line.a.y,&line.b.x,&line.b.y);
			line.ok=1;
			if(line.a.x>line.b.x || (E(line.a.x,line.b.x) && line.a.y>line.b.y))
				swap(line.a,line.b);
			if(E(line.a.x,line.b.x))
				line.c=line.a.x,ver.push_back(line);
			else if(E(line.a.y,line.b.y))
				line.c=line.a.y,hor.push_back(line);
			else if(E(line.a.y-line.b.y,line.a.x-line.b.x))
				line.c=line.a.y-line.a.x,pls.push_back(line);
			else
				line.c=line.a.y+line.a.x,mns.push_back(line);
		}
		sort(ver.begin(),ver.end());
		sort(hor.begin(),hor.end());
		sort(pls.begin(),pls.end());
		sort(mns.begin(),mns.end());
		for(i=0;i<ver.size();)
		{
			j=i+1;
			while(j<ver.size() && E(ver[i].c,ver[j].c) && (ver[j].a<ver[i].b || ver[j].a==ver[i].b))
			{
				ver[j].ok=0;
				if(ver[i].b<ver[j].b)
					ver[i].b=ver[j].b;
				j++;
			}
			i=j;
		}
		for(i=0;i<hor.size();)
		{
			j=i+1;
			while(j<hor.size() && E(hor[i].c,hor[j].c) && (hor[j].a<hor[i].b || hor[j].a==hor[i].b))
			{
				hor[j].ok=0;
				if(hor[i].b<hor[j].b)
					hor[i].b=hor[j].b;
				j++;
			}
			i=j;
		}
		for(i=0;i<pls.size();)
		{
			j=i+1;
			while(j<pls.size() && E(pls[i].c,pls[j].c) && (pls[j].a<pls[i].b || pls[j].a==pls[i].b))
			{
				pls[j].ok=0;
				if(pls[i].b<pls[j].b)
					pls[i].b=pls[j].b;
				j++;
			}
			i=j;
		}
		for(i=0;i<mns.size();)
		{
			j=i+1;
			while(j<mns.size() && E(mns[i].c,mns[j].c) && (mns[j].a<mns[i].b || mns[j].a==mns[i].b))
			{
				mns[j].ok=0;
				if(mns[i].b<mns[j].b)
					mns[i].b=mns[j].b;
				j++;
			}
			i=j;
		}

		int ans=0;
		ans+=make(hor,ver,pls);
		ans+=make(hor,ver,mns);
		ans+=make(hor,pls,mns);
		ans+=make(ver,pls,mns);
		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}