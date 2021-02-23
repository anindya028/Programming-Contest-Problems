//Line of symmetry of a polygon
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
#define Max 105
#define PREC 1e-10
#define myabs(a) (((a)>0)?(a):-(a))
struct point
{
	int x,y;
}p[Max];

int N,cnt;

inline int equals(double x,double y,double prec)
{
	return myabs(x-y)<prec;
}

bool isSymline(double x1,double y1,double x2,double y2,int prev,int next,point p[],int n)
{
	double a,b,c,mx,my;
	register int k;
	int j,l;
	a=y1-y2;
	b=x2-x1;
	c=y1*(x1-x2) - x1*(y1-y2);
	for(k=0;k<n/2;k++)
	{
		j=(next+k)%n;
		l=(prev-k+n)%n;
		//Now find mirror of alpha=p[j].x and beta =p[j].y;
		mx=-(p[j].x *(a*a-b*b) + 2*a*(c+b*p[j].y))/(a*a+b*b);
		my=(p[j].y*(a*a-b*b) - 2*b*(c+a*p[j].x))/(a*a+b*b);
		if(!equals(mx,p[l].x,PREC) || !equals(my,p[l].y,PREC))
			return false;
	}
	return true;
}

void oddcase(void)
{
	register int i;
	int j,k;
	double x1,y1,x2,y2;
	for(i=0;i<N;i++)
	{
		x1=p[i].x;
		y1=p[i].y;
		j=(i+N/2)%N;
		k=(j+1)%N;
		x2=(p[j].x + p[k].x)/2.;
		y2=(p[j].y + p[k].y)/2.;
		if(isSymline(x1,y1,x2,y2,(i-1+N)%N,(i+1)%N,p,N))
			cnt++;
	}
	return;
}

void evencase(void)
{
	register int i;
	int j,k,l;
	double x1,y1,x2,y2;
	for(i=0;i<N/2;i++)
	{
		j=(i+1)%N;
		k=(i+N/2)%N;
		l=(k+1)%N;
		x1=(p[i].x+p[j].x)/2.;
		y1=(p[i].y+p[j].y)/2.;
		x2=(p[k].x+p[l].x)/2.;
		y2=(p[k].y+p[l].y)/2.;
		if(isSymline(x1,y1,x2,y2,i,j,p,N))
			cnt++;
	}
	for(i=0;i<N/2;i++)
	{
		x1=p[i].x;
		y1=p[i].y;
		j=(i+N/2)%N;
		x2=p[j].x;
		y2=p[j].y;
		if(isSymline(x1,y1,x2,y2,i,i,p,N))
			cnt++;
	}
	return;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		for(i=cnt=0;i<N;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		if(N%2)
			oddcase();
		else
			evencase();
		if(cnt)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

