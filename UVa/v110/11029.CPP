#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long __int64
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
int fastexp(int n,int k)
{
	int fir;
	double temp=k*log10(n);
	temp-=(int)temp;
	if(temp<0)temp+=1.;
	temp=pow(10,temp);
	fir=(int)(100.*temp);
	return fir;
}
int main()
{
	int t,i,n,k,last;
	char s[25],ans[20];
	int first;
	while(scanf("%d",&t)==1)
	{
		for(i=0;i<t;i++)
		{
			scanf("%d%d",&n,&k);
			first=fastexp(n,k);
			last=bigmod(n,k,1000);
			sprintf(s,"%d",first);
			ans[0]=s[0];
			ans[1]=s[1];
			ans[2]=s[2];
			ans[3]=ans[4]=ans[5]='.';
			sprintf(s,"%d",last);
			if(strlen(s)==1)
			{
				ans[6]=ans[7]='0';
				ans[8]=s[0];
			}
			else if(strlen(s)==2)
			{
				ans[6]='0';
				ans[7]=s[0];
				ans[8]=s[1];
			}
			else
			{
				ans[6]=s[0];
				ans[7]=s[1];
				ans[8]=s[2];
			}
			ans[9]='\0';
			printf("%s\n",ans);
		}
	}
	return 0;
}

/*double  float_mod(Long b,long p)
{
	Long a;
	long div;
	if(p==0)
		return 1;
	if(p%2==0)
	{
		a=float_mod(b,p/2);
		if(a>1000000000)return ((a/100)*(a/100));
		else return a*a;
	}
	else
	{
		a=float_mod(b,p-1);
		if(b>=1000000000 && a>=1000000000)return ((b/100)*(a/100));
		else if(b>=1000000000)return ((b/100)*a);
		else if(a>=1000000000)return ((a/100)*b);
		else return b*a;
	}
}*/
/*
Long square (Long n) 
{ 
   return n * n; 
} 

Long fastexp (Long base, int power) 
{ 
   Long r; 
   char digits[25]; 

   if (power == 0) 
      return 1; 
    
   else if (power % 2 == 0) 
   { 
      r = (square (fastexp (base, power / 2))); 
       
      if (r >= BIG) 
      { 
         sprintf(digits, "%I64d", r); 
       
         digits[9] = NULL; 

         r = atol(digits); 
      } 

      return r; 
   } 
    
   else 
   { 
      r = (base * ( fastexp (base, power - 1))); 

      if (r >= BIG) 
      { 
         sprintf(digits, "%I64d", r); 
          
         digits[9] = NULL; 

         r = atol(digits); 
      } 

      return r; 
   } 
}
*/











