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

//this recursion is useful to understand the following iterative code.
/*int joseph(int n,int m)
{
	int now,got;
	if(n==1)
		return 0;
	now=(m-1)%n;
	got=joseph(n-1,m);
	///printf("%d\n",got);
	if(got<(n-now-1))
		return got+now+1;
	else
		return got-(n-now-1);
}*/

int joseph[100005];

int main()
{
	int t,cs,n,m,i,now;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d",&n,&m);
		joseph[1]=0;
		for(i=2;i<=n;i++)
		{
			now=(m-1)%i;
			if(joseph[i-1]<i-now-1)
				joseph[i]=joseph[i-1]+now+1;
			else
				joseph[i]=joseph[i-1]-(i-now-1);
		}
		printf("Case %d: %d\n",cs+1,joseph[n]+1);
	}
	return 0;
}
