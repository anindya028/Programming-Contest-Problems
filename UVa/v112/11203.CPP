#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,flag,begin,end,middle;
	char s[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag=1;
		scanf("%s",&s);
		j=0;
		while(s[j]=='?')
			j++;
		begin=j;
		if(!begin)flag=0;
		if(s[j]!='M')flag=0;
		if(!flag)
		{
			printf("no-theorem\n");
			continue;
		}
		j++;
		middle=0;
		while(s[j]=='?')
		{
			j++;
			middle++;
		}
		if(!middle)flag=0;
		if(s[j]!='E')flag=0;
		if(!flag)
		{
			printf("no-theorem\n");
			continue;
		}
		j++;
		end=0;
		while(s[j]=='?')
		{
			j++;
			end++;
		}
		end-=begin;
		if(end!=middle || s[j]!='\0')flag=0;
		if(flag)printf("theorem\n");
		else printf("no-theorem\n");
	}
	return 0;
}













