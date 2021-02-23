#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	char ori[]={"qwertyuiop[]asdfghjkl;'zxcvbnm,./`1234567890-="};
	char c;
	int len=strlen(ori),i,flag;
	while(scanf("%c",&c)==1)
	{
		if(isalpha(c))c=tolower(c);
		flag=0;
		for(i=0;i<len;i++)
		{
            
			if(ori[i]==c)
			{
				printf("%c",ori[i-2]);
				flag=1;
			}
		}
		if(!flag)printf("%c",c);
	}
	return 0;
}













