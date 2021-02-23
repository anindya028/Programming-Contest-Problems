#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
/*long long mod(long long a,long long b,long long c)
{
	long long x;
	if(b==1)return (a%c);
	x=mod(a,b/2,c);
	x=(x*x)%c;
	if(b%2)x=(x*a)%c;
	return x;
}**/
int bigmod(int b, int p, int m){
   int a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0){ 
      a = bigmod(b,p/2,m); 
      return (a*a) % m; 
   }else{ 
      return ((b % m) * bigmod(b,p-1,m)) % m; 
   } 
}
int main()
{
	long a,b,c;
	while(scanf("%ld%ld%ld",&a,&b,&c)==3)
	{
		/*if(a<2)
		{
			printf("%ld\n",a%c);
			continue;
		}
		if(!b)
		{
			printf("%ld",1%c);
			continue;
		}*/
		printf("%d\n",bigmod(a,b,c));
	}
	return 0;
}













