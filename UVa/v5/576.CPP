#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	char line[1000];
	int i,count;
	char s[]={"e/o/i"};
	while(gets(line))
	{
		if(!strcmp(line,s))
			break;
		for(i=count=0;line[i]!='/';)
		{
			if(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
			{
				count++;
				while(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
					i++;
			}
			else i++;
		}
		if(count!=5)
		{
			printf("1\n");
			continue;
		}
		for(i++,count=0;line[i]!='/';)
		{
			if(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
			{
				count++;
				while(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
					i++;
			}
			else i++;
		}
		if(count!=7)
		{
			printf("2\n");
			continue;
		}
		for(i++,count=0;line[i];)
		{
			if(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
			{
				count++;
				while(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y')
					i++;
			}
			else i++;
		}
		if(count!=5)
		{
			printf("3\n");
			continue;
		}
		else printf("Y\n");
	}
	return 0;
}













