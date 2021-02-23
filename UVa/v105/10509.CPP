#include<stdio.h>
#include<math.h>

double n,a,y,z,x;

void main(){
	while(scanf("%lf",&n)==1 && n){
		a=floor(pow(n,(1./3.)));
		if(a*a*a==n){
			printf("%.4lf\n",a);
			continue;
		}
		if((a+1)*(a+1)*(a+1)==n){
			printf("%.4lf\n",a+1);
			continue;
		}
		y=2*(pow(a,3.));
		z=3*(pow(a,2.));
		x=(y+n)/z;
		printf("%.4lf\n",x);
	}
}















