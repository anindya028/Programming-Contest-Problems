#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[]={"`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./"};
	char temp[10000];
        int i,j;
	while(gets(temp))
	{
		for(i=0;temp[i];i++)
		{
			if(temp[i]==' ')
			{
				printf("%c",temp[i]);
				continue;
                        }
			if(temp[i]=='\\')
			{
				printf("]");
				continue;
			}
			for(j=0;s[j];j++)
			{
				if(s[j]==temp[i])
				{
					printf("%c",s[j-1]);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}













