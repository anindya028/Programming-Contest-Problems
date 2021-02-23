#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char m[1100],n[1100];
int lenm,lenn;
int four(void)
{
	int temp;
	if(lenn==1)
	{
		return ((n[0]-'0')%4);
	}
	else
	{
		temp=(n[lenn-1]-'0')+(n[lenn-2]-'0')*10;
		return temp%4;
	}
}
int two(void)
{
	return ((n[lenn-1]-'0')%2);
}
int main()
{
	int f2[]={6,2,4,8};
	int f3[]={1,3,9,7};
	int f4[]={6,4};
	int f7[]={1,7,9,3};
        int f8[]={6,8,4,2};
	int f9[]={1,9};
        char temp;
	while(scanf("%s%s",m,n)==2)
	{
		if(m[0]=='0'&&m[1]=='\0'&&n[0]=='0'&&n[1]=='\0')break;
		lenm=strlen(m);
		lenn=strlen(n);
                temp=m[lenm-1];
		if(temp=='0'||temp=='1'||temp=='5'||temp=='6')
		{
                        if(n[0]=='0' && lenn==1)
                              printf("1\n");
		        else printf("%c\n",temp);
			continue;
		}
		if(lenn==1)
		{
			if(n[0]=='1')printf("%c\n",temp);
			else if(n[0]=='0')printf("1\n");
		}
		if(temp=='2'||temp=='3'||temp=='7'||temp=='8')
		{
                	if(temp=='2')printf("%d\n",f2[four()]);
			else if(temp=='3')printf("%d\n",f3[four()]);
			else if(temp=='7')printf("%d\n",f7[four()]);
			else printf("%d\n",f8[four()]);
		}
		else
		{
			if(temp=='4')printf("%d\n",f4[two()]);
			else printf("%d\n",f9[two()]);
                }
	}
	return 0;
}













