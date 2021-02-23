#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int *taken,len,lev,k;
char s[100],given[100];
void gene(int lev)
{
	int i,flag;
	if(lev==len)
	{
		s[lev]='\0';
		printf("%s\n",s);
		return;
	}
	for(i=flag=0;i<len;i++)
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
	int i,cs;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%s",given);
		len=strlen(given);
		sort(given,given+len);
		taken=(int *)calloc(len,sizeof(int));
		k=0;
		gene(0);
		free(taken);
		printf("\n");
	}
	return 0;
}













