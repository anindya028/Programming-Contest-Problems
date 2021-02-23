#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,j,k,bs,dbs;
	char buf[10000],s[30];
	gets(s);
	sscanf(s,"%d",&t);
	gets(buf);
	for(i=0;i<t;i++)
	{
		if(i)
			printf("\n");
		printf("Case #%d:\n",i+1);
		while(gets(buf) && strlen(buf))
		{
			j=bs=dbs=0;
			while(sscanf(buf+bs,"%s%n",s,&dbs)==1)
			{
				bs+=dbs;
				if(strlen(s)<(j+1))
					continue;
				printf("%c",s[j]);
				j++;
			}
			printf("\n");
		}
	}
	return 0;
}













