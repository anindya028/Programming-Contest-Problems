#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<set>

using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define mabs(a) ((a)>0?(a):-(a))

struct point
{
	int x,y;
	point(int _x=0,int _y=0){x=_x,y=_y;}
};

bool operator<(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

bool operator==(point a,point b)
{
	return a.x==b.x && a.y==b.y;
}

int main()
{
	point g[305];
	int n,i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		set< point > st;
		for(i=0;i<n;i++)
			scanf("%d%d",&g[i].x,&g[i].y),st.insert(g[i]);

		int a=0;
		for(i=0;i<n;i++)
			a+=g[i].x*g[(i+1)%n].y;
		for(i=0;i<n;i++)
			a-=g[i].y*g[(i+1)%n].x;
		if(a<0)
			a*=-1;
		int dif=a;
		point lf,rh,fir,sec;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(g[i].x!=g[j].x && g[i].y!=g[j].y)
				{
					point u(g[i].x,g[j].y),v(g[j].x,g[i].y);
					if(st.find(u)!=st.end() || st.find(v)!=st.end())
					{
						int now=mabs(g[i].x-g[j].x)*mabs(g[i].y-g[j].y);
						lf.x=Min(g[i].x,g[j].x);
						lf.y=Min(g[i].y,g[j].y);
						rh.x=Max(g[i].x,g[j].x);
						rh.y=Max(g[i].y,g[j].y);
						if(mabs(2*now-a)<dif)
						{
							dif=mabs(2*now-a);
				//			printf("->%d %d %d %d\n",lf.x,lf.y,rh.x,rh.y);
							fir=lf,sec=rh;	
						}
						else if(mabs(2*now-a)==dif)
						{
				//			printf("->%d %d %d %d\n",lf.x,lf.y,rh.x,rh.y);
							if(lf<fir)
								fir=lf,sec=rh;
							else if(lf==fir && rh<sec)
								sec=rh;
						}
					}
				}
		printf("%.1lf %d %d %d %d\n",a/2.0,fir.x,fir.y,sec.x,sec.y);	
	}
	return 0;
}