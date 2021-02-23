#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char s[10000];
	int n,i,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		if(len==1)
		{
			if(s[0]=='1'||s[0]=='4')
			{
				printf("+\n");
				continue;
			}
		}
		if(len==2)
		{
			if(s[0]=='7' && s[1]=='8')
			{
				printf("+\n");
				continue;
			}
		}
		if(s[len-1]=='5'&&s[len-2]=='3')
		{
			printf("-\n");
			continue;
		}
		if(s[0]=='9'&&s[len-1]=='4')
		{
			printf("*\n");
			continue;
		}
		if(s[0]=='1'&&s[1]=='9'&&s[2]=='0')
		{
			printf("?\n");
			continue;
		}
	}
	return 0;
}













