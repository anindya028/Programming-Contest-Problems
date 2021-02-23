#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>

#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#include<utility>
#include<sstream>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define MP make_pair
#define MEM(a,b) memset((a),(b),sizeof(a))
#define inf 1e15

//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

double pye=(2.*acos(0.0));
#define eps 1e-9
#define S(a) ((a)*(a))
#define mabs(a) ((a)>0?(a):-(a))

struct point 
{
	double x,y,z;
	point(){}
	point(double _x,double _y,double _z=0){x=_x,y=_y;z=_z;}
	
	double mag2(){return S(x)+S(y)+S(z);}
	double mag(){return sqrt(mag2());}

};

point operator+(point a,point b) { return point(a.x+b.x,a.y+b.y,a.z+b.z);}
point operator-(point a,point b) { return point(a.x-b.x,a.y-b.y,a.z-b.z);}
double operator*(point a,point b) {return a.x*b.x+a.y*b.y+a.z*b.z;}
point operator^(point a,point b) { return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}

double linePointDist(point A,point B,point C,bool is)
{
	double dist = ((B-A)^(C-A)).mag() / sqrt((B-A)*(B-A));
	if(is)
	{
		double dot1 = (C-B) * (B-A);
		if(dot1>0) return sqrt((B-C)*(B-C));
		double dot2 = (C-A) * (A-B);
		if(dot2>0) return sqrt((A-C)*(A-C));
	}
	return mabs(dist);
}

struct circle
{
	point cen;
	double rad;
}acr[20];

struct square
{
	point a[4];
}asr[20];
int flag[20];

struct line
{
	point a,b;
	line(point _a,point _b){a=_a;b=_b;}
};

double line_line(line AB,line CD)
{
	double d1 = linePointDist(AB.a,AB.b,CD.a,1);
	double d2 = linePointDist(AB.a,AB.b,CD.b,1);
	double d3 = linePointDist(CD.a,CD.b,AB.a,1);
	double d4 = linePointDist(CD.a,CD.b,AB.b,1);
	return Min(Min(d1,d2),Min(d3,d4));
}

double circle_circle(circle a,circle b)
{
	return (a.cen-b.cen).mag() - a.rad - b.rad;
}

double square_square(square b,square c)
{
	int i,j;
	double ret=inf;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			double v=line_line(line(b.a[i],b.a[(i+1)%4]),line(c.a[j],c.a[(j+1)%4]));
			ret = Min(ret,v);
		}
	return ret;
}

double circle_square(circle c,square b)
{
	double ret=inf;
	int i;
	for(i=0;i<4;i++)
	{
		double v=linePointDist(b.a[i],b.a[(i+1)%4],c.cen,1);
		ret = Min(ret,v-c.rad);
	}
	return ret;
}

int n;
double mat[20][20];
char vis[1<<16][16];
double dp[1<<16][16];
double nine[20];

double make(int now,int pos,int cnt)
{
	if(now==((1<<n)-1))
		return 0.0;
	if(vis[now][pos]!=-1)
		return dp[now][pos];
	vis[now][pos]=0;
	dp[now][pos]=inf;
	int i;
	double v;
	for(i=0;i<n;i++)
		if(!(now & 1<<i))
		{
			v=make(now | 1<<i,i,cnt+1);
			v=Max(v,mat[pos][i]/nine[cnt-1]);
			dp[now][pos]=Min(dp[now][pos],v);
		}
	return dp[now][pos];
}

int main(){
	int i,t,j;
	nine[0]=1.0;
	for(i=1;i<=18;i++)
		nine[i]=nine[i-1]*.9;
	scanf("%d",&t);
	char s[5];
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			if(s[0]=='C')
			{
				scanf("%lf%lf%lf",&acr[i].cen.x,&acr[i].cen.y,&acr[i].rad);
				flag[i]=0;
			}
			else
			{
				double d;
				scanf("%lf%lf%lf",&asr[i].a[0].x,&asr[i].a[0].y,&d);
				asr[i].a[1]=point(asr[i].a[0].x,asr[i].a[0].y+d);
				asr[i].a[2]=point(asr[i].a[0].x+d,asr[i].a[0].y+d);
				asr[i].a[3]=point(asr[i].a[0].x+d,asr[i].a[0].y);
				flag[i]=1;
			}
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				double d;
				if(flag[i]==flag[j])
				{
					if(!flag[i])
						d=circle_circle(acr[i],acr[j]);
					else
						d=square_square(asr[i],asr[j]);
				}
				else
				{
					if(flag[i])
						d=circle_square(acr[j],asr[i]);
					else
						d=circle_square(acr[i],asr[j]);
				}
				mat[i][j]=mat[j][i]=d;
			}
		MEM(vis,-1);
		printf("%.6lf\n",make(1,0,1));
	}
	return 0;
}