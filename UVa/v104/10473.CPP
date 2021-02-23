//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[20];
	long dec;
	while(scanf("%s",s)==1)
	{
		if(s[0]=='-')break;
		if(s[0]=='0'&&s[1]=='x')
		{
			/*len=strlen(s);
			for(i=2;i<len;i++)dec+=(s[i]-'0')*six[len-i-1];*/
			sscanf(s,"%x",&dec);
			printf("%ld\n",dec);
		}
		else
		{
			sscanf(s,"%ld",&dec);
			sprintf(s,"%X",dec);
			printf("0x%s\n",s);
		}
	}
	return 0;
}













