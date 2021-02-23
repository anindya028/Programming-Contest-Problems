#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[10];
	double h,m,c;
	while(gets(s))
	{
		if(s[0]=='0')break;
		if(s[1]!=':')
		{
			h=(double)((s[0]-'0')*10+s[1]-'0');
			m=(double)((s[3]-'0')*10+s[4]-'0');
                }
		else
		{
			h=(double)(s[0]-'0');
			m=(double)((s[2]-'0')*10+s[3]-'0');
                }
		if((h*30+m/2)>=(m*6))
			c=h*30+m/2-m*6;
		else
			c=m*6-h*30-m/2;
		if(c<180)printf("%.03lf\n",c);
		else printf("%.03lf\n",360-c);
	}
	return 0;
}













