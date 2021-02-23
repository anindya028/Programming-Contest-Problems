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

double pro[100005]; 

int main()
{
	  int n,i,cs;
	  pro[0]=1;
	  for(i=2;i<100003;i+=2)
       pro[i]=(pro[i-2]*(i-1))/i;
    scanf("%d",&cs);
    Foro(i,cs)
    {  
       scanf("%d",&n);
       if(n==2)
           printf("0.0000\n");
       else
           printf("%.4lf\n",1-pro[n-2]);
    }                        
	  return 0;
}
