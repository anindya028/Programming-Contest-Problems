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
		return scanf("%lf%lf",&x,&y)==2;}

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

double mn;
point g[10005],ans;

void point_to_line(point p,point a,point b,bool is_seg)
{
	point ba=b-a;
	double t=(ba*p - a*ba)/(ba*ba);
	if(is_seg)
	if(t<0 || t>1)
	{
		double got=(p-a).mag();
		if(got<mn)
			mn=got,ans=a;
		got=(p-b).mag();
		if(got<mn)
			mn=got,ans=b;
		return;
	}
	if((p-a-t*ba).mag()<mn)
		mn=(p-a-t*ba).mag(),ans=a+t*ba;
}



int main()
{
	int n,i;
	point m;
	while(m.scan())
	{
		m.z=0;
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			g[i].scan(),g[i].z=0;
		mn=inf;
		for(i=0;i<n;i++)
			point_to_line(m,g[i],g[i+1],1);
		printf("%.4lf\n%.4lf\n",ans.x,ans.y);
	}
	return 0;
}