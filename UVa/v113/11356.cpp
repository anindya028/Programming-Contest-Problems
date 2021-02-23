#include<stdio.h>
#include<string.h>

char month[][20]={"January", "February", "March", "April", "May", "June", "July",
					"August", "September", "October", "November" , "December"};
int lenm[]={31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y)
{
	if(y%400==0)
		return true;
	if(y%100==0)
		return false;
	return (y%4==0);
}

int main()
{
	int i,cs,t,k;
	scanf("%d",&t);
	char s[30],mon[30];
	int y,mm,dd;
	for(cs=0;cs<t;cs++)
	{
		scanf("%s%d",s,&k);
		for(i=0;s[i];i++)
			if(s[i]=='-')
				s[i]=' ';
		sscanf(s,"%d%s%d",&y,mon,&dd);
		for(i=0;i<12;i++)
			if(!strcmp(mon,month[i]))
				mm=i;
		while(k)
		{
			dd++;
			if(dd>lenm[mm] && mm!=1)
			{
				dd=1;
				mm++;
				if(mm>=12)
					mm=0,y++;
			}
			if(mm==1 && dd>lenm[mm]+isleap(y))
			{
				dd=1;
				mm++;
			}
			k--;
		}
		printf("Case %d: %d-%s-%.2d\n",cs+1,y,month[mm],dd);
	}
	return 0;
}