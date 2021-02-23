#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[1000];
	int co[9],i,printed=0;
	while(gets(s))
	{
        	printed=0;
		sscanf(s,"%d%d%d%d%d%d%d%d%d",&co[8],&co[7],&co[6],&co[5],&co[4],&co[3],&co[2],&co[1],&co[0]);
		for(i=8;i>1;i--)
		{
			if(co[i])
			{
				if(printed)
				{
					if(abs(co[i])==1)
					{
						if(co[i]==1)printf(" + x^%d",i);
						else printf(" - x^%d",i);
					}
					else if(co[i]>0)printf(" + %dx^%d",co[i],i);
					else printf(" - %dx^%d",abs(co[i]),i);
				}
				else
				{
					if(abs(co[i])!=1)printf("%dx^%d",co[i],i);
					else if(co[i]==1)printf("x^%d",i);
					else printf("-x^%d",i);
					printed=1;
				}
			}
		}
		if(co[i])
		{
			if(printed)
				{
					if(abs(co[i])==1)
					{
						if(co[i]==1)printf(" + x");
						else printf(" - x");
					}
					else if(co[i]>0)printf(" + %dx",co[i]);
					else printf(" - %dx",abs(co[i]));
				}
				else
				{
					if(abs(co[i])!=1)printf("%dx",co[i]);
					else if(co[i]==1)printf("x");
					else printf("-x");
					printed=1;
				}
		}
		i--;
		if(co[i])
                {
			if(printed)
			{
				if(co[i]>0)printf(" + %d",co[i]);
				else printf(" - %d",abs(co[i]));
			}
			else
			{
				printf("%d",co[i]);
				printed=1;
                        }
                }
		else if(!printed)printf("%d",co[i]);
		printf("\n");
	}
	return 0;
}













