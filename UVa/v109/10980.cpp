#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

struct offer
{
	int no;
	double pr;
}of[105];

int main()
{
	int n,i,j,cs=0,bs,dbs;
	double p1,mn[205];
	char s[1005];
	while(gets(s) && sscanf(s,"%lf%d",&p1,&n)==2)
	{
		Foro(i,n)
			gets(s),sscanf(s,"%d%lf",&of[i].no,&of[i].pr);
		mn[0]=0.;
		For(i,1,202)
			mn[i]=p1+mn[i-1];
		Foro(i,n)
		{
			for(j=0;j<201;j++)
				if(j+of[i].no<201)
					mn[j+of[i].no]=Min(mn[j+of[i].no],mn[j]+of[i].pr);
			for(j=199;j;j--)
				mn[j]=Min(mn[j],mn[j+1]);
		}
		gets(s);
		printf("Case %d:\n",++cs);
		bs=0;	
		while(sscanf(s+bs,"%d%n",&n,&dbs)==1)
			bs+=dbs,printf("Buy %d for $%.2lf\n",n,mn[n]);
	}
	return 0;
}