#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[1001];
int i,sum1,sum2,length,dif;
void main()
{
	while(scanf("%s",s)==1)
	{
		if(s[0]=='0'&&s[1]=='\0')break;
                length=strlen(s);
		for(i=sum1=0;i<length;i+=2)
		{
			sum1+=(s[i]-'0');
		}
		for(i=1,sum2=0;i<length;i+=2)
		{
			sum2+=(s[i]-'0');
		}
		dif=abs(sum1-sum2);
		if(dif%11==0)printf("%s is a multiple of 11.\n",s);
		else printf("%s is not a multiple of 11.\n",s);
        }
}                    













