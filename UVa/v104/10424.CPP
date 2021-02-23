//Number theory + Adhoc
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char b[26],g[26];
long i,k,countb,countg;
void main()
{
	while(gets(b)!=NULL)
	{
		gets(g);
		i,countb=0,countg=0;
        	for(i=0;b[i];i++)
        	{
			if(isalpha(b[i]))
                	{
				 if(islower(b[i]))countb+=(b[i]-'a'+1);
                        	 else countb+=(b[i]-'A'+1);
			}
		}
		for(i=0;g[i];i++)
		{
			if(isalpha(g[i]))
                	{
				 if(islower(g[i]))countg+=(g[i]-'a'+1);
				 else countg+=(g[i]-'A'+1);
			}
		}
		countb%=9;
		countg%=9;
		if(!countb)countb=9;
		if(!countg)countg=9;
		if (countb<=countg)printf("%.2lf %%\n",countb*100/(countg+0.0));
		else printf("%.2lf %%\n",countg*100/(countb+0.0));
        }

}


