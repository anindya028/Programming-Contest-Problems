#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	


double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
//#define Long __int64
//#define Long long long


int main()
{
	int i,t,a,b,c,d;
	scanf("%d",&t);
	For(i,0,t)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==b && b==c && c==d)
			printf("square\n");
		else if((a==b && c==d) || (a==c && b==d) || (a==d && c==b))
			printf("rectangle\n");
		else if((a+b+c)>d && (a+b+d)>c && (a+d+c)>b && (d+b+c)>a)
			printf("quadrangle\n");
		else
			printf("banana\n");
	}
	return 0;
}
