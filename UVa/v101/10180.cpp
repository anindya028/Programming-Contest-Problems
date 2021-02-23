//10180 - "Rope Crisis in Ropeland"
//sub - 3(WA,WA,AC)
#include<stdio.h>
#include<math.h>

#define LMT 1e-8
#define MYABS(x) ((x>0)?(x):-(x))

double myrope(double a,double b,double c,double R){
	double alpha,beta,gamma,theta;
	alpha=acos((b*b+c*c-a*a)/(2.*b*c));
	beta=acos(R/b);
	gamma=acos(R/c);
	theta=alpha-(beta+gamma);
	return b*sin(beta) + c*sin(gamma) + R*theta;
}

void main(){
	int t,i;
	double p,q,r,q1,r1,s,h,bs1,bs2;
	double x1,y1,x2,y2,radius,Rope;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&radius);
		if(MYABS(x1-x2) < LMT && MYABS(y1-y2) < LMT)
			Rope=0.;
		else{
			p=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			q1=x1*x1 + y1*y1;
			q=sqrt(q1);
			r1=x2*x2 + y2*y2;
			r=sqrt(r1);
			if(MYABS(q+r-p) < LMT)
				Rope=myrope(p,q,r,radius);
			else{
				s=(p+q+r)/2.;
				h=2.*sqrt(s*(s-p))*sqrt((s-q)*(s-r))/p;
				bs1=q1 - h*h;
				bs2=r1 - h*h;
				if(radius > h && MYABS(p - (sqrt(bs1)+sqrt(bs2)) )  < LMT)
					Rope=myrope(p,q,r,radius);
				else
					Rope=p;
			}
		}
		printf("%.3lf\n",Rope);
	}
}