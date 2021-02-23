//Simulation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[20];
	int h,m,sec,speed,speedp=0;
	double dist=0.0,time,ini=0.0;
	while(gets(s))
	{
		if(strlen(s)>9)
		{
			sscanf(s,"%d%*c%d%*c%d%d",&h,&m,&sec,&speed);
			time=(double)h+(double)m/60.0+(double)sec/3600.0;
			dist+=(fabs(time-ini)*speedp);
            speedp=speed;
			ini=time;
		}
		else
		{
			sscanf(s,"%d%*c%d%*c%d",&h,&m,&sec);
			time=(double)h+(double)m/60.0+(double)sec/3600.0;
			printf("%s %.2lf km\n",s,(double)(dist+(time-ini)*speed));
		}
	}
	return 0;
}













