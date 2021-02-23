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

 

int main()
{
	int v,v0,n,i,mx;
	while(scanf("%d%d",&v,&v0)==2 && v && v0)
	{
     if(v<=v0)
     { 
        printf("0\n");
        continue;
     }
     if(v%(2*v0)==0)
     {
        printf("%d\n",v/(2*v0));
        continue;
     }                                                     
     n=v/(2*v0);
     mx=v*n-v0*n*n;
     if((v*(n+1)-v0*sq(n+1))==mx)
         printf("0\n");
     else if((v*(n+1)-v0*sq(n+1))>mx)
         printf("%d\n",n+1);
     else
         printf("%d\n",n);                                   
  }     
	return 0;
}
