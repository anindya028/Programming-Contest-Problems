#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int flag=0;
        char c;
	while((c=getchar())!=EOF)
	{
		if(c=='"')
		{
			if(!flag)
			{
				printf("``");
				flag=1;
			}
			else
			{
				printf("''");
				flag=0;
			}
                }
		else printf("%c",c);
	}
	return 0;
}













