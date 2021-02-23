#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

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
};
bool operator==(point a,point b) {	return E(a.x,b.x) && E(a.y,b.y) && E(a.z,b.z);}
point operator+(point a,point b){	return point(a.x+b.x, a.y+b.y, a.z+b.z);}
point operator-(point a,point b){	return point(a.x-b.x, a.y-b.y, a.z-b.z);}
double operator*(point a, point b){	return a.x*b.x + a.y*b.y + a.z*b.z;}
point operator*(double a,point b){	return point(a*b.x, a*b.y, a*b.z);}

int main()
{
	int t,ti,cs;
	point a,b,c,d;
	double s;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&ti);
		a.scan();
		b.scan();
		c.scan();
		d.scan();
		point ba=b-a,dc=d-c,ca=c-a;
		point v=ba-dc;
		if(ba==dc)
			s=0;
		else
			s=(ca * v)/(v*v);
		if(s<0)
			s=0;
		point e=a + s*ba;
		point f=c + s*dc;
		printf("Case %d: %.4lf\n",cs+1,(e-f).mag());
	}
	return 0;
}