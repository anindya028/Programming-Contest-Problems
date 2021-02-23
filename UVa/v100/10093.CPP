#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>																																																																																																																																																																																																					
//#define Long __int64
//#define Long long long
int getvalue(char s)
{
	if(s >= '0' && s <= '9')
		return s - '0';
	else if(s >='A' && s <= 'Z')
		return s - 'A' + 10;
	else if(s >='a' && s <= 'z')
		return s - 'a' + 36;
	else
		return NULL;
}
int main()
{
	char s[10000];
	int sum;
    int i,max,flag;
	while(scanf("%s",s)==1)
	{
		max=0;
		flag=0;
		for(i=sum=0;s[i];i++)
		{
			sum+=getvalue(s[i]);
			if(getvalue(s[i])>max)
				max=getvalue(s[i]);
		}
		if(max==0)
		{
			printf("2\n");
			continue;
		}
		for(i=max;i<=61;i++)
		{
			if(sum%i==0)
			{
				printf("%d\n",i+1);
				flag=1;
				break;
			}
		}
		if(!flag)printf("such number is impossible!\n");
	}
	return 0;
}


																											










