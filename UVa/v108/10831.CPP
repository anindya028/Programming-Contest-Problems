#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long  __int64
//#define Long long long
Long bigmod(Long b,Long p,Long m)
{
   Long a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0)
   { 
      a = bigmod(b,p/2,m); 
      return (a*a) % m; 
   }
   else
   { 
      return ((b % m) * bigmod(b,p-1,m)) % m; 
   } 
}
int main()
{
	int a,p;
	while(scanf("%d%d",&a,&p)==2)
	{
		if(a<0 && p<0)break;
		if(!a)
		{
			printf("Yes\n");
			continue;
		}
		if(p==2)
		{
			printf("Yes\n");
			continue;
		}
		//printf("%I64u\n",bigmod(a,((p-1)/2),p));
		if(bigmod(a,(p-1)/2,p)<=1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}













