#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-10
int main()
{
	double h,u,d,f,climbed;
	int flag,day;
	while(scanf("%lf%lf%lf%lf",&h,&u,&d,&f)==4)
	{
		if(h==0.0)break;
		day=flag=1;
		climbed=u;
		if(climbed>h)
		{
			printf("success on day %d\n",day);
			continue;
		}
		climbed-=d;
		if(climbed<0)
		{
			printf("failure on day %d\n",day);
			continue;
		}
		f=u*f/100.;
		while(1)
		{
			day++;
			u-=f;
			if(u>0)climbed+=u;
			if(climbed>h)
				break;
			climbed-=d;
			if(climbed<0)
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
	}
	return 0;
}













