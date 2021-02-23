#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define S(x)		((x)*(x))
#define mabs(a) ((a)>0?(a):-(a))
#define eps 1e-9
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

struct circle
{
	point c;
	double r;
	circle(){}
	circle(point _c,double _r){c=_c; r=_r;}
}cir[20];

vector<double> line_circle(circle v,point a,point b)
{
	vector<double> ret;
	point ca=v.c-a,ba=b-a;
	double A=ba * ba, B= -2 * ba * ca, C= ca * ca - S(v.r) ;
	double D = S(B) - 4*A*C;
	if(D+eps<0)
		return ret;
	double t = (-B - sqrt(D))/(2*A);
	ret.push_back(t);
	if(Z(D))
		return ret;
	t = (-B + sqrt(D))/(2*A);
	ret.push_back(t);
	return ret;
}

int main()
{
	char s[100];
	point a,b;
	int n,i;
	while(scanf("%s",s)==1)
	{
		a.scan();
		b.scan();
		scanf("%d",&n);
		for(i=0;i<n;i++)
			cir[i].c.scan(),scanf("%lf",&cir[i].r);
		double sum=0;
		for(i=0;i<n;i++)
		{
			vector<double> now=line_circle(cir[i],a,b);
			if(now.size()<2)
				continue;
			double t1 = now[0];
			double t2 = now[1];
			
			assert(t1 < t2 + eps);
			
			if(t1 < 0) t1 = 0;
			if(t2 > 1) t2 = 1;
			
			if(t1 < t2)
				sum += t2 - t1;
		}
		assert(sum<1+1e-3);
	
		printf("%s\n%.2lf\n",s, sum*100.);
	}
	return 0;
}
