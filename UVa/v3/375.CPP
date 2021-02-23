/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define pi (2.0*acos(0.0))
int main()
{
	double h,b,q,r,sum,s;
	while(scanf("%lf%lf",&b,&h)==2)
	{
		sum=0.0;
		q=atan(h/b);
		r=1.0;
		while(r>=0.000001)
		{
			s=h/sin(q)+h/2*tan(q);
			r=(s-h/sin(q))*sqrt(s*(s-h/tan(q)))/s;
			h-=2*r;
			sum+=(2*pi*r);
		}
		printf("    %.6lf\n",sum+1e-10);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<math.h> 

int main() 
{ 
   double r,total; 
   double H,B; 
   int cases; 
   double pi=2.0*acos(0.0); 
   int nl=0,i; 
	//char temp[20];
	//int len,i;
   scanf("%d",&cases); 

   for(i=0;i<cases;i++){       

      //scanf("\n");
	   if(i)printf("\n");
      scanf("%lf %lf",&B,&H); 
       
      r=B/2*tan( 0.5 * atan( 2.0 * H / B ) ); 
      for(total=0;r>=0.000001;r=B/2*tan( 0.5 * atan( 2.0 * H / B ) )){ 
         total+=2*pi*r; 
         H=H-2*r; 
         B=( H/(H+2*r) ) * B ; 
      } 
      printf("%13.6lf\n",total);
   } 

   return 0; 
}

