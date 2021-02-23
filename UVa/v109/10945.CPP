#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	char temp[]={"DONE"};
        int i,j,flag;
	char s[1000];
	while(gets(s))
	{
		if(!strcmp(s,temp))break;
		i=0;
		j=strlen(s)-1;
                flag=1;
		while(i<=j)
		{
			if(!isalpha(s[i]))
			{
				i++;
				continue;
			}
			if(!isalpha(s[j]))
			{
				j--;
				continue;
			}
			if(tolower(s[i])!=tolower(s[j]))
			{
				flag=0;
				break;
			}
			i++;
			j--;
		}
		if(flag)printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}
	return 0;
}













