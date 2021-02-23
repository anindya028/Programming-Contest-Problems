#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int *taken,len,lev,k,length;
char s[100],given[100];
void gene(int lev)
{
	int i=0,flag;
	if(lev==len)
	{
		s[lev]='\0';
		printf("%s\n",s);
		return;
	}
	if(lev)
		for(;given[i]<s[lev-1];i++);
	for(flag=0;i<length;i++)
	{
		if(!taken[i] && !flag)
		{
			s[lev]=given[i];
			lev++;
			taken[i]=1;
			if(given[i]==given[i+1])flag=1;
			gene(lev);
			lev--;
			taken[i]=0;
		}
		else if(given[i]!=given[i+1])
			flag=0;
	}
	return;
}
int main()
{
	while(scanf("%s%d",given,&len)==2)
	{
		length=strlen(given);
		taken=(int *)calloc(length,sizeof(int));
		sort(given,given+length);
		gene(0);
		free(taken);
	}
	return 0;
}



























