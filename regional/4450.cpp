#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define inf 1e14
#define sq(a) ((a)*(a))
#define eps 1e-9
#define mabs(a) ((a)>0?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Min(a,b) (((a)<(b))?(a):(b))
const double pye = 2*acos(0.0);

struct point
{
	int x,y;
}p[20],pp[20],hull[20];

int findstart(int n)
{
	int i,k=0;
	int mny=p[k].y;
	for(i=1;i<n;i++)
		if(p[i].y==mny)
		{
			if(p[i].x<p[k].x)
				k=i;
		}
		else if(p[i].y<mny)
		{
			mny=p[i].y;
			k=i;
		}
	return k;
}

int dist2(point a,point b)
{
	return (sq(a.x-b.x)+sq(a.y-b.y));
}

double dist(point a,point b)
{
	return sqrt((double)(sq(a.x-b.x)+sq(a.y-b.y)));
}

int triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y) - (a.y-b.y)*(b.x-c.x));
}

bool right_turn(point a,point b,point c)
{
	return (triarea(a,b,c)<=0);
}

bool on_line(point a,point b,point c)
{
	return (triarea(a,b,c)==0);
}

point base;
bool operator<(point a,point b)
{
	if(on_line(base,a,b))
		return dist2(base,a)<dist2(base,b);
	return (triarea(base,a,b)>0);
}

double angle_bac(point b,point a,point c)
{
	double ab = dist(a,b), bc = dist(b,c), ca = dist(c,a);
	return acos( (sq(ab)+sq(ca)-sq(bc)) / (2.0*ab*ca) );
}

double mar;
double convex_hull(int n)	
{
	int i=2,ns=2;		//number of points in hull
	if(n==1)
		return 2*pye*mar;

	int idx=findstart(n);
	base=p[idx];
	swap(p[0],p[idx]);
	sort(p+1,p+n);
	hull[0]=p[0];
	hull[1]=p[1];

	for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hull[ns-2],hull[ns-1],p[i]))
				ns--;
			else
				break;
		}
		hull[ns]=p[i];
		ns++;
	}
	double sum=0,ang;
	for(i=0;i<ns;i++)
		sum+=dist(hull[i],hull[(i+1)%ns]);
	if(ns==2)
	{
		sum += 2*pye*mar;
		return sum;
	}
	for(i=0;i<ns;i++)
	{
		ang = angle_bac(hull[(i-1+ns)%ns],hull[i],hull[(i+1)%ns]);
		sum += (pye-ang)*mar;
	}
	return sum;
}

double dp[1<<12];
int pts;
double make(int now)
{
	if(!now)
		return 0.0;
	if(!(dp[now]<0.0))
		return dp[now];
	dp[now] = inf;
	int i,j,cnt;
	double v;
	for(i=now;i;i = now & (i-1))
	{
		cnt = 0;
		for(j=0;j<pts;j++)
			if(i & 1<<j)
				p[cnt++] = pp[j];
		v = convex_hull(cnt) + make(now ^ i);
		dp[now] = Min(dp[now],v);
	}
//	printf("%d %lf\n",now,dp[now]);
	return dp[now];
}

int main()
{
	int n,i,cs=0;
	while(scanf("%d%lf",&n,&mar)==2 && n)
	{
		pts = n;
		for(i=0;i<n;i++)
			scanf("%d%d",&pp[i].x,&pp[i].y);
		for(i=0;i<(1<<n);i++)
			dp[i] = -1.0;
		printf("Case %d: length = %.2lf\n",++cs,make((1<<n)-1));
	}
	return 0;
}
