#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
char s[size],ans[size];
int i;
void main()
{
	while(scanf("%s",s)==1)
	{
		for(i=0;s[i];i++)
		{
			if(s[i]=='1'||s[i]=='0'||s[i]=='-')ans[i]=s[i];
			else
			{
				if(s[i]>='A'&&s[i]<='C')ans[i]='2';
				else if(s[i]>='D'&&s[i]<='F')ans[i]='3';
				else if(s[i]>='G'&&s[i]<='I')ans[i]='4';
				else if(s[i]>='J'&&s[i]<='L')ans[i]='5';
				else if(s[i]>='M'&&s[i]<='O')ans[i]='6';
				else if(s[i]>='P'&&s[i]<='S')ans[i]='7';
				else if(s[i]>='T'&&s[i]<='V')ans[i]='8';
				else ans[i]='9';
			}
		}
		ans[i]='\0';
		printf("%s\n",ans);
        }
}













