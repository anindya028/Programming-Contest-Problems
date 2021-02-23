#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	unsigned long long n,i,lim,temp;
        int printed=0;
        char s[40];
	while(scanf("%llu",&n)==1 && n)
	{
		lim=n*10/9;
		printed=0;
		for(i=lim-10;i<=lim+10;i++)
		{
			sprintf(s,"%llu",i);
			s[strlen(s)-1]='\0';
			sscanf(s,"%llu",&temp);
			if((i-temp)==n)
			{
				if(!printed)printf("%llu",i);
				else printf(" %llu",i);
				printed++;
			}
		}
		printf("\n");
	}
	return 0;
}













