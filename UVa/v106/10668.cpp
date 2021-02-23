//10668 - "Expanding Rods"
//sub - 2(WA,AC)
#include<stdio.h>
#include<math.h>

#define ABS(x) ((x>0)?(x):-(x))

int main(){
	double l,s,theta,LHS,RHS,lm,um,n,c,pi=2.*acos(0.),r,h;
	while(scanf("%lf%lf%lf",&l,&n,&c)==3 && l!=-1){
		s=l*(1+n*c);
		if(s<=l || l<1e-10 || s<1e-10){
			printf("0.000\n");
			continue;
		}
		//BISECTION METHOD:
		lm=0;
		um=pi/2;
		while(1){
			theta=(um+lm)/2;
			LHS=s*sin(theta);
			RHS=l*theta;
			if(ABS(LHS-RHS) <= 1e-12 || um-lm <= 1e-12)
				break;
			else if(LHS > RHS)
				lm=theta;
			else
				um=theta;
		}
		r=l/(2*sin(theta));
		h=r-r*cos(theta);
		printf("%.3lf\n",h);
	}
	return 0;
}