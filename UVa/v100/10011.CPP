//10011 - Where Can You Hide?
//sub - 2
//AC
#include<stdio.h>
#include<math.h>
#include<string.h>

#define LMT 1e-6
#define PI (2.*acos(0.0))
#define DIS(x1,y1,x2,y2) (sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ))
#define myabs(x) ((x>0)?(x):-(x))

double getangle(double x,double y){
	if(myabs(y) < LMT){	//i.e. y==0
		if(x > 0.)
			return 0.;
		else
			return PI;
	}
	if(myabs(x) < LMT){	//i.e. x==0
		if(y > 0.)
			return PI/2.;
		else
			return 3.*PI/2.;
	}
	////
	if(x>0&&y>0)    //1st quad
		return atan(y/x);
	if(x<0&&y>0)    //2nd quad
		return PI/2. + atan(-x/y);
	if(x<0&&y<0)    //3rd quad
		return PI + atan(y/x);
	if(x>0&&y<0)    //4th quad
		return 3.*PI/2. + atan(x/-y);
}

int main(){
	int N,ks;
	double x1,y1,r,x2,y2;
	double s,dis01,dis02,dis12,alpha,beta,theta;
	double A1,A2,min,d1,d2,d3;
	scanf("%d",&N);
	for(ks=0;ks<N;ks++){
		scanf("%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2);
		if(r<LMT){
			printf("0.000\n");
			continue;
		}
		dis01=DIS(0,0,x1,y1);
		dis02=DIS(0,0,x2,y2);
		dis12=DIS(x1,y1,x2,y2);

		alpha=getangle(x1,y1);
		beta=asin(r / dis01);
		theta=getangle(x2,y2);

//	printf("%lf %lf %lf\n",alpha*180./PI,beta*180./PI,theta*180./PI);
		s=sqrt(dis01*dis01 - r*r);
		if(dis02 < s){
			printf("0.000\n");
			continue;
		}
		if( (theta < alpha-beta || theta > alpha+beta) &&
			(theta+2.*PI < alpha-beta || theta+2.*PI > alpha+beta) &&
			(theta-2.*PI < alpha-beta || theta-2.*PI > alpha+beta) ){
			printf("0.000\n");
			continue;
		}
		A1=theta-alpha+beta;
		A2=alpha+beta-theta;
		d1=dis02*sin(A1);
		d2=dis02*sin(A2);
		d3=dis12-r;
		min=d1;
		if(d2<min)
			min=d2;
		if(d3<min)
			min=d3;
		printf("%.3lf\n",min);
	}
	return 0;
}