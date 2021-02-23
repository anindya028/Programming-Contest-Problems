//Searching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char s[1000005];
int len,freq,times;
int give(int k)
{
	int j;
	for(j=k;s[j];j++)
	{
		if(s[j]==s[0])
		{
			if(len%j==0)return j;
		}
	}
        return 0;
}
int check(void)
{
	int i,j,k=freq;
	for(i=0;i<(times-1);i++)
	{
		for(j=0;j<freq;j++,k++)
			if(s[j]!=s[k])
			{
				freq++;
				return 0;
			}
	}
	return 1;
}
int main()
{
	
	int i,j,n;
	while(gets(s))
	{
        	if(s[0]=='.'&&s[1]=='\0')break;
		//scanf("%[^\n]",s);
		len=strlen(s);
		for(j=freq=1;s[j];j++)
			if(s[j]==s[0])freq++;
		if(freq==len)
		{
			printf("%d\n",freq);
			continue;
		}
		/*for(j=1;s[j];j++)
		{
			if(s[j]==s[0])
			{
				if(len%j==0)
				{
					freq=j;
                                        times=len/j;
					break;
				}
			}
		}*/
		freq=1;
		while(s[freq])
		{
			freq=give(freq);
			if(!freq)
			{
				printf("1\n");
                                break;
			}
                        times=len/freq;
			if(check())
			{
				printf("%d\n",times);
				break;
			}
		}
	}
	return 0;
}













