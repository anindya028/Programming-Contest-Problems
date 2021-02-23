#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct stri
{
	char s[1000];
}sti[1000];
bool operator<(stri a,stri b)
{
	return (strcmp(b.s,a.s)>0);
}
int main()
{
	char start[10],end[10],time[10],tem[]={"10:00"},endtemp[10];
	int st,en,dif,n,i,h,m,max,cs=0;
	while(scanf("%d\n",&n)==1)
	{
        	strcpy(time,tem);
		for(i=0;i<n;i++)
		{
			gets(sti[i].s);
		}
		sort(sti,sti+n);
		for(i=0;i<n;i++)
		{
			sscanf(sti[i].s,"%s%s",&start,&end);
			h=(start[0]-'0')*10+(start[1]-'0');
			m=(start[3]-'0')*10+(start[4]-'0');
			st=h*60+m;
			if(!i)
			{
				max=st-60*10;
				strcpy(time,tem);
			}
			else
			{
				dif=st-en;
				if(dif>max)
				{
					max=dif;
					strcpy(time,endtemp);
				}
			}
			h=(end[0]-'0')*10+(end[1]-'0');
			m=(end[3]-'0')*10+(end[4]-'0');
			en=h*60+m;
			strcpy(endtemp,end);
		}
		dif=18*60-en;
		if(dif>max)
		{
			max=dif;
			strcpy(time,end);
		}
		if(!(max/60))printf("Day #%d: the longest nap starts at %s and will last for %d minutes.\n",++cs,time,max);
		else printf("Day #%d: the longest nap starts at %s and will last for %d hours and %d minutes.\n",++cs,time,max/60,max%60);
    }
	return 0;
}













