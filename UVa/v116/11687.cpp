#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char s[1000005];

int main()
{
	int i;
	while(scanf("%s",s)==1 && strcmp(s,"END"))
	{
		int len=strlen(s);
		if(len==1)
		{
			if(s[0]=='1')
			{
				printf("1\n");
				continue;
			}
		}
		int now=len;
		i=1;
		while(1)
		{
			i++;
			sprintf(s,"%d",now);
			len=strlen(s);
			if(len==now)
				break;
			now=len;
		}
		printf("%d\n",i);
	}
	return 0;
}