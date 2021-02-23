#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

map<string,int> mp;

int main()
{
	int p,g,i,v;
	char s[50];
	double d; 
	string ss;
	while(scanf("%d%d",&p,&g)==2)
	{
		mp.clear();
		for(i=0;i<p;i++)
		{
			scanf("%s%lf",s,&d);
			v=(int)((d+1e-4)*10);
			ss=s;
			mp[ss]=v;
		}
		for(i=0;i<g;i++)
		{
			int sum=0,tot,ok;
			while(1)
			{
				scanf("%s",s);
				if(s[0]=='<' || s[0]=='>' || s[0]=='=')
					break;
				if(s[0]=='+')
					continue;
				ss=s;
				sum+=mp[ss];
			}
			scanf("%d",&tot);
			if(strlen(s)==1)
			{
				if(s[0]=='>')
					ok=(sum>tot*10);
				else if(s[0]=='<')
					ok=(sum<tot*10);
				else
					ok=(sum==tot*10);
			}
			else
			{
				if(s[0]=='>')
					ok=(sum>=tot*10);
				else
					ok=(sum<=tot*10);
			}
			if(ok)
				printf("Guess #%d was correct.\n",i+1);
			else
				printf("Guess #%d was incorrect.\n",i+1);
		}
	}
	return 0;
}
