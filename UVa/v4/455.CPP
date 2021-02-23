#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char s[100];
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
	char temp[10];
	        scanf("%d",&n);
		gets(temp);	
	for(i=0;i<n;i++)
	{
		if(i)printf("\n");
		gets(temp);
		gets(s);
		//scanf("%[^\n]",s);
		len=strlen(s);
		for(j=freq=1;s[j];j++)
			if(s[j]==s[0])freq++;
		if(freq==len)
		{
			printf("1\n");
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
				printf("%d\n",len);
                                break;
			}
                        times=len/freq;
			if(check())
			{
				printf("%d\n",freq);
				break;
			}
		}
	}
	return 0;
}













