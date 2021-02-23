#include<stdio.h>

int main()
{
	int t;
	char s[1000];
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
		int sum=0,i;
		
		for(i=0;i<4;i++)
		{
			scanf("%s",s);
			sum+= (s[1]-'0'+s[3]-'0'+((s[0]-'0')*2)%10 + ((s[0]-'0')*2)/10 + ((s[2]-'0')*2)%10 + ((s[2]-'0')*2)/10);
		}
		if(sum%10==0)
			printf("Valid\n");
		else
			printf("Invalid\n");
	}
	return 0;
}