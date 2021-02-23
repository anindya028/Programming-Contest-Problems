#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//Input
//First line of the input file contains an integer (N<=100), which indicates how many sets of inputs are there. Each of the next N lines contains two integers D(0<=D<=1000) and L(D<L<=1500). The first integer D denotes the distance in feet between the two pillars and the second integer L denotes the length of the rope in feet.
//Output
//Your program should produce N lines of output. Each line contains a single floating-point number, which has three digits after the decimal point. This floating-point number indicates the area of the field which the cow can reach and eat grass.
#define pye 2*acos(0.0)
int main()
{
	int n,i;
	double d,l,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&d,&l);
		a=l/2;
		b=sqrt((l/2)*(l/2)-(d/2)*(d/2));
		printf("%.3lf\n",pye*a*b);
	}
	return 0;
}













