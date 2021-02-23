#include<stdio.h>
#include<math.h>

double x1,y1,r1,x2,y2,r2,Px[2],Py[2];

double myabs(double num){
	if(num<0.) return -num;
	else return num;
}

double round(double n){
	return (floor(n*1000+0.5))/1000;
}

void main(){
	double tmp,d,h,a;
	while(scanf("%lf%lf%lf",&x1,&y1,&r1)==3){
		scanf("%lf%lf%lf",&x2,&y2,&r2);
		if(r2>r1){
			tmp=r1;r1=r2;r2=tmp;
			tmp=x1;x1=x2;x2=tmp;
			tmp=y1;y1=y2;y2=tmp;
		}
		if(r1==0.&&r2==0.){
			if(x1==x2&&y1==y2) printf("(%.3lf,%.3lf)\n",round(x1),round(y1));
			else puts("NO INTERSECTION");
		}
		else if(x1==x2&&y1==y2){
			if(r1==r2) puts("THE CIRCLES ARE THE SAME");
			else puts("NO INTERSECTION");
		}
		else{
			d=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			if(myabs(d-r1+r2)<1e-8||myabs(d-r1-r2)<1e-8){
				Px[0]=x1+r1*(x2-x1)/d;
				Py[0]=y1+r1*(y2-y1)/d;
				printf("(%.3lf,%.3lf)\n",round(Px[0]),round(Py[0]));
			}
			else if(d<(r1-r2)||d>(r1+r2)) puts("NO INTERSECTION");
			else{ // d>(r1-r2) && d<(r1+r2)
				a=(r1*r1+d*d-r2*r2)/(2.*d);
				h=sqrt(r1*r1 - a*a);
				Px[0]=x1 + (a*(x2-x1) - h*(y2-y1))/d;
				Py[0]=y1 + (a*(y2-y1) + h*(x2-x1))/d;
				Px[1]=x1 + (a*(x2-x1) + h*(y2-y1))/d;
				Py[1]=y1 + (a*(y2-y1) - h*(x2-x1))/d;
				if(Px[0]>Px[1]||(Px[0]==Px[1]&&Py[0]>Py[1]))
					 printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n",round(Px[1]),round(Py[1]),round(Px[0]),round(Py[0]));
				else printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n",round(Px[0]),round(Py[0]),round(Px[1]),round(Py[1]));
			}
		}
	}
}