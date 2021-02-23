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

int got[1000005];

int main()
{
	int n,t,z,now;
	register int i;
	while(scanf("%d",&n)==1)
	{
		Foro(i,n+1)
			got[i]=0;
		t=0;
		z=0;
		now=0;
		while(1)
		{
			if(!(now%n) && t)
				break;
			now=(now*10+3)%n;
			t++;
			if(got[now])
			{
				z=got[now];
				t=t-z;
				break;
			}
			else
				got[now]=t;
		}
		printf("%d %d %d\n",t+z,t,z);
	}
	return 0;
}
