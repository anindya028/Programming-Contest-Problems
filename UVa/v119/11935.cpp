#include<stdio.h>
#include<string.h>

struct eve
{
	int dis;
	char ss[100];
	int val;
}e[105];

int n;
bool ok(double x)
{
	int i,d=0;
	double rem = x;
	int leak = 0;
	double rate = 0;
	for(i=0;i<n;i++)
	{
		if( (e[i].dis-d)*(rate+leak) > rem)
			return false;
		rem-=(e[i].dis-d)*(rate+leak);
		d = e[i].dis;
		if(!strcmp(e[i].ss,"Fuel"))
			rate = e[i].val/100.0;
		else if(!strcmp(e[i].ss,"Leak"))
			leak++;
		else if(!strcmp(e[i].ss,"Gas"))
			rem = x;
		else if(!strcmp(e[i].ss,"Mechanic"))
			leak = 0;
	}
	return true;
}

int main()
{
	int i;
	char buf[100];
	while(scanf("%d%s%s%d",&e[n].dis,e[n].ss,buf,&e[n].val)==4 && e[n].val)
	{
		n++;
		while(scanf("%d%s",&e[n].dis,e[n].ss)==2)
		{
			if(!strcmp(e[n].ss,"Goal"))
				break;
			if(!strcmp(e[n].ss,"Fuel"))
				scanf("%s%d",buf,&e[n].val);
			else if(!strcmp(e[n].ss,"Gas"))
				scanf("%s",buf);
			n++;
		}
		n++;

		double lo = 0,hi = 1e14,mid;
		i=100;
		while(i--)
		{
			mid = (lo+hi)/2;
			if(ok(mid))
				hi=mid;
			else
				lo=mid;
		}
		printf("%.3lf\n",mid);
		n = 0;
	}
	return 0;
}