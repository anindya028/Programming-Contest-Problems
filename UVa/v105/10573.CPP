#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define pi 2*acos(0.0)
//#define Long __int64
//#define Long long long
int main()
{
	long n,i,j;
        double r1,r2,t,a;
	char s[30];
	while(scanf("%ld",&n)==1)
	{
		gets(s);
		for(i=0;i<n;i++)
		{
			gets(s);
			for(j=0;isdigit(s[j]);j++);
			if(s[j]==' ')
			{
				sscanf(s,"%lf%lf",&r1,&r2);
				a=2*pi*r1*r2;
				printf("%.4lf\n",a);
			}
			else
			{
				sscanf(s,"%lf",&t);
				t/=2.0;
				a=pi*t*t/2.0;
                                printf("%.4lf\n",a);
			}
		}
	}
	return 0;
}













