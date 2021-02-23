//Geometry + (Very Nasty)^inf precision
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
#define LMT 1e-14
void main()
{
	char buf[size],*t;
	while(gets(buf))
	{
		double s[2],a,vmax,vmin;
                int i=0;
		t=strtok(buf," \n\r");
		while(t!=NULL)
		{
			sscanf(t,"%lf",&s[i]);
			i++;
			t=strtok(NULL," \r\n");
		}
		if(s[0]< LMT ||s[1]< LMT){
			printf("0.000 0.000\n");
			continue;
		}
		a=sqrt(s[0]*s[0]+s[1]*s[1]-s[0]*s[1]);
		vmax=(s[0]+s[1]-a)/6.0;
		vmin=
		printf("%.3lf 0.000 %.3lf\n",vmax,vmin);
	}
}*/
//this is code of little joey
#include <stdio.h> 
#include <math.h> 

int main(void){ 
    double w,l,x,x1,x2,vol1,vol2;

    while (scanf("%lf %lf",&w,&l)==2) {
      if (w>l) {
         x=w;
         w=l;
         l=x;
      }
      x1=((l+w)-sqrt(l*l+w*w-l*w))/6.0;
      x2=((l+w)+sqrt(l*l+w*w-l*w))/6.0;
      vol1=x1*(w-2.0*x1)*(l-2.0*x1);
      vol2=x2*(w-2.0*x2)*(l-2.0*x2);
      if (vol2<vol1) 
         x=x1;
      else 
           x=x2;
      printf("%.3lf %.3lf %.3lf\n",x+1e-10,0.0,w/2.0+1e-10);
    }
    return 0;
}












