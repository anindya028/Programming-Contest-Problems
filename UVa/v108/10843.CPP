#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long __int64
//#define Long long long
#define mod 2000000011
Long bigmod(Long b,Long p)
{
   Long a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0)
   { 
      a = bigmod(b,p/2); 
      return (a*a) % (Long)mod; 
   }
   else
   { 
      return ((b % (Long)mod) * bigmod(b,p-1)) % (Long)mod; 
   } 
}
int main()
{
	int ans[101];
	int n,i,N;
	ans[1]=1;
	ans[2]=1;
	for(i=3;i<101;i++)
		ans[i]=(int)bigmod(i,i-2);
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",i+1,ans[n]);
	}
	return 0;
}













