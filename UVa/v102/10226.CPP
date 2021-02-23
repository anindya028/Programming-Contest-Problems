//Saerching +Map
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;

struct species
{
	char s[80];
}buf;

bool operator==(const species &a,const species &b)
{
	return !strcmp(a.s,b.s);
}

bool operator<(const species &a,const species &b)
{
	return strcmp(a.s,b.s)<0;
}

map<species,int> cnt;

int main()
{
	int tot,t,cs;
	char garb[100];
	scanf("%d",&t);
	gets(garb);
	gets(garb);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
		{
			printf("\n");
			cnt.clear();
		}
		tot=0;
		while(gets(buf.s) && strlen(buf.s)>0)
		{
			cnt[buf]++;
			tot++;
		}
		map<species,int>::iterator i;
		for(i=cnt.begin();i!=cnt.end();*i++)
			printf("%s %.4lf\n",i->first.s,(100. * i->second)/tot);
	}
	return 0;
}

