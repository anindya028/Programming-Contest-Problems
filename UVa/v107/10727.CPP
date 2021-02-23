#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int n[105],w[105],t;
double a,b,delta,p,q;

double like(double a, double b)
{
   int i;
   double r = 1;
   for (i=0;i<t;i++) 
   {
      double odds = exp(a + b * n[i]);
      double p = odds / (1 + odds);
      if (w[i]) r *= p; 
	  else r *= (1-p);
   }
   return r;
}

double alike(double a)
{
	double p,q,delta;
   b = p = 0;
   for (delta=1;delta > 1e-9;) 
   {
      if ((q=like(a,b+delta)) > p) 
	  {
         b += delta;
         p = q;
      } 
	  else if ((q = like(a,b-delta)) > p) 
	  {
         b -= delta;
         p = q;
      } 
	  else delta *= .5;
   }
   return p;
}


int main()
{
	int i;
	while(scanf("%d",&t)==1)
	{
		if(!t)break;
		for(i=0;i<t;i++)
			scanf("%d%d",&n[i],&w[i]);
		a=p=0;
		for(delta=1;delta>1e-9;)
		{
			if((q=alike(a+delta))>p)
			{
				a+=delta;
				p=q;
			}
			else if((q=alike(a-delta))>p)
			{
				a-=delta;
				p=q;
			}
			else delta*=0.5;
		}
		printf("%.4lf %.4lf\n",a,b);
	}
	return 0;
}













