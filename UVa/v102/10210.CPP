//Euclidean geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define pye 2*acos(0.0)
int main()
{
	double x1,x2,y1,y2,cmd,enf,ab;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&cmd,&enf)==6)
	{
		ab=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		cmd=pye*cmd/180.0;
		enf=pye*enf/180.0;
		printf("%.3lf\n",ab/tan(cmd)+ab/tan(enf));
	}
	return 0;
}













