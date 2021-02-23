#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	double ncows,ncars,nshow;
	while(scanf("%lf%lf%lf",&ncows,&ncars,&nshow)==3)printf("%.5lf\n",((ncows*ncars+ncars*(ncars-1))/(ncows+ncars-nshow-1))/(ncows+ncars));
	return 0;
}













