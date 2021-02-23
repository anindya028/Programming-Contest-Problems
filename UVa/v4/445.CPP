#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	char c;
	int i,count,flag=1;
	while((c=getchar())!=EOF)
	{
		if(c=='\n' || c=='!')printf("\n");
		else
		{
			count=0;
                        if(isdigit(c))count+=(c-'0');
			while(c=getchar())
			{
				if(isdigit(c))count+=(c-'0');
				else break;
			}
			if(c=='b')
                        {
				for(i=0;i<count;i++)
					printf(" ");
			}
			else
			{
				for(i=0;i<count;i++)
					printf("%c",c);
			}
		}
	}
	return 0;
}













