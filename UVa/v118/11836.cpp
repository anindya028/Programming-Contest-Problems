#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define S(x)		((x)*(x))
#define mabs(a) ((a)>0?(a):-(a))
#define eps 1e-8
#define Z(a) (mabs(a)<eps)
#define E(a,b) Z(a-b)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1e9

double pi = 2.*acos(0.);
double mysqrt(double x){if(x < 0)	return 0;return sqrt(x);}
double myasin(double x){if(x < -1)	return -pi/2;if(x > 1)	return pi/2;return asin(x);}
double myacos(double x){if(x < -1)	return -pi;if(x > 1)	return 0;return acos(x);}

struct point{
	double x,y,z;
	point(){}
	point(double _x,double _y,double _z=0){x=_x;y=_y;z=_z;}

	bool scan(){
		return scanf("%lf%lf%lf",&x,&y,&z)==3;}

	double mag2(){
		return S(x)+S(y)+S(z);	}

	double mag(){
		return mysqrt(mag2());	}

	void norm(){
		double d = mag();x/=d;y/=d;	z/=d;}

	point unit(){
		point ret = *this;	ret.norm();	return ret;	}

	void show(){
		printf("[%.2lf, %.2lf, %.2lf]",x,y,z);}

	void showln(){
		printf("[%.2lf, %.2lf, %.2lf]\n",x,y,z);}
};

bool operator==(point a,point b) {	return E(a.x,b.x) && E(a.y,b.y) && E(a.z,b.z);}
point operator+(point a,point b){	return point(a.x+b.x, a.y+b.y, a.z+b.z);}
point operator-(point a)		{	return point (-a.x, -a.y, -a.z);}
point operator-(point a,point b){	return point(a.x-b.x, a.y-b.y, a.z-b.z);}
point operator*(double a,point b){	return point(a*b.x, a*b.y, a*b.z);}
point operator*(point b,double a){	return point(a*b.x, a*b.y, a*b.z);}
point operator/(point b,double a){	return point(b.x/a, b.y/a, b.z/a);}
double operator*(point a, point b){	return a.x*b.x + a.y*b.y + a.z*b.z;}
point operator^(point a, point b){	return point( a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x );}

double det(double a,double b,double c,double d)
{
	return a*d-b*c;
}

double point_to_line(point p,point a,point b,bool is_seg)
{
	point ba=b-a;
	double t=(ba*p - a*ba)/(ba*ba);
	if(is_seg)
	if(t<0 || t>1)
	{
		double ret=1e12;
		double got=(p-a).mag();
		ret=Min(ret,got);
		got=(p-b).mag();
		ret=Min(ret,got);
		return ret;
	}
	return (p-a-t*ba).mag();
}

double line_to_line(point a,point b,bool is_seg1,point c,point d,bool is_seg2)
{
	point ba=b-a,dc=d-c;
	double a1 = ba*ba, b1 = -dc*ba, c1 = c*ba - a*ba;
	double a2 = b1, b2 = dc*dc, c2 = a*dc - c*dc;
	double s=det(c1,b1,c2,b2)/det(a1,b1,a2,b2);
	double t=det(a1,c1,a2,c2)/det(a1,b1,a2,b2);
	if(is_seg1)
	if(s<0 || s>1)
	{
		double ret = inf;
		double got = point_to_line(a,c,d,is_seg2);
		ret=Min(ret,got);
		got = point_to_line(b,c,d,is_seg2);
		ret=Min(ret,got);
		return ret;
	}
	if(is_seg2)
	if(t<0 || t>1)
	{
		double ret = inf;
		double got = point_to_line(c,a,b,is_seg1);
		ret=Min(ret,got);
		got = point_to_line(d,a,b,is_seg1);
		ret=Min(ret,got);
		return ret;
	}
	return (a + s*ba - c - t*dc).mag();
}

double point_to_plane(point p,point a,point b,point c)
{
	point ba=b-a,ca=c-a;
	double a1=ba*ba,b1=ba*ca,c1=p*ba-a*ba;
	double a2=ca*ba,b2=ca*ca,c2=p*ca-a*ca;
	double s=det(c1,b1,c2,b2)/det(a1,b1,a2,b2);
	double t=det(a1,c1,a2,c2)/det(a1,b1,a2,b2);
	if(s+t>1 || s+t<0 || s<0 || s>1 || t<0 || t>1)
	{
		double ret=1e12;
		double got=point_to_line(p,a,b,1);
		ret=Min(ret,got);
		got=point_to_line(p,b,c,1);
		ret=Min(ret,got);
		got=point_to_line(p,c,a,1);
		ret=Min(ret,got);
		return ret;
	}
	point d = p - s*ba -t*ca -a;
	return d.mag();
}

int main()
{
	int t,i,n,j,k,l;
	point tet1[4],tet2[4];
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		n=4;
		ans=1e12;
		double now;
		for(i=0;i<n;i++)
			tet1[i].scan();
		for(i=0;i<n;i++)
			tet2[i].scan();
		for(i=0;i<n;i++)
		{
			now=point_to_plane(tet2[i],tet1[0],tet1[1],tet1[2]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[0],tet1[1],tet1[3]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[0],tet1[2],tet1[3]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[1],tet1[2],tet1[3]);
			ans=Min(ans,now);
		}
		for(i=0;i<n;i++)
			swap(tet1[i],tet2[i]);
		for(i=0;i<n;i++)
		{
			now=point_to_plane(tet2[i],tet1[0],tet1[1],tet1[2]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[0],tet1[1],tet1[3]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[0],tet1[2],tet1[3]);
			ans=Min(ans,now);
			now=point_to_plane(tet2[i],tet1[1],tet1[2],tet1[3]);
			ans=Min(ans,now);
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=0;k<n;k++)
					for(l=k+1;l<n;l++)
						now = line_to_line(tet1[i],tet1[j],1,tet2[k],tet2[l],1),
						ans=Min(now,ans);
		printf("%.2lf\n",ans);
	}
	return 0;
}