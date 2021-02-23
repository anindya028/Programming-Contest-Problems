
#include<stdio.h>

char *weekdays[]={"Sun","Mon","Tues","Wednes","Thurs","Fri","Satur"};
char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

int leapdays[12]= {0,31,60,91,121,152,182,213,244,274,305,335};
int nleapdays[12]={0,31,59,90,120,151,181,212,243,273,304,334};

int isGleap(long y)
{
	if(((y%4==0)&&(y%100!=0))||(y%400==0)) return 1;
	return 0;
}

long gdays_from_1(long month,long day,long year)
{
	long ndays;
	ndays=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400;  /*365**/
	if(isGleap(year)) ndays+=leapdays[month-1]+day;
	else ndays+=nleapdays[month-1]+day;
	return ndays;
}

long jdays_from_1(long month,long day,long year)
{
	long ndays;
	ndays=(year-1)+(year-1)/4;  /*365**/
	if(year%4==0) ndays+=leapdays[month-1]+day;
	else ndays+=nleapdays[month-1]+day;
	return ndays;
}

int isvalid(long month,long day,long year)
{
	if(month<=0 || month>12 || year<=0) return 0;
	if(year==1752 && month==9)
	{
		if(day>2 && day<14) return 0;
	}
	if(year>1752)
	{
		if(!isGleap(year) && month==2)
		{
			if(day>28) return 0;
		}
	}
	else if(year%4 && month==2)
	{
		if(day>28) return 0;
	}
	if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
	{
		if(day>31) return 0;
	}
	else if(month==2)
	{
		if(day>29) return 0;
	}
	else if(day>30) return 0;
	return 1;
}

int main()
{
	long month,day,year,ndays;
	int g;
	for(;;)
	{
		scanf("%ld %ld %ld",&month,&day,&year);
		if((month | day | year)==0) break;
		if(isvalid(month,day,year))
		{
			g=0;
			if(year>1752) g=1;
			else if(year==1752)
			{
				if(month>9) g=1;
				else if(month==9)
				{
					if(day>=14) g=1;
				}
			}
			if (g) ndays=gdays_from_1(month,day,year);
			else
			{
				ndays=jdays_from_1(month,day,year);
				ndays-=2;      /*as it became monday based*/
				while(ndays<0) ndays+=7;
			}
			printf("%s %ld, %ld is a %sday\n",months[month-1],day,year,weekdays[ndays%7]);
		}
		else printf("%ld/%ld/%ld is an invalid date.\n",month,day,year);
	}
	return 0;
}
