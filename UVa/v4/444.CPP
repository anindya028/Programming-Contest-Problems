#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
	        temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
int main()
{
	char s[1000],temp[20],*ans;
	int  i,j,tem;
	while(gets(s))
	{
		ans=(char *)calloc(1000,sizeof(1000));
		if(isdigit(s[0]))
		{
			for(i=j=0;s[i];)
            {
				if(s[i+2]=='1'&& s[i+1]<='2')
				{
					tem=(s[i+2]-'0')*100+(s[i+1]-'0')*10+s[i]-'0';
					ans[j]=(char)tem;
					j++;
                                        i+=3;
				}
				else
				{
					tem=(s[i+1]-'0')*10+s[i]-'0';
					ans[j]=(char)tem;
					j++;
					i+=2;
                }
			}
            rev(ans);
		}
		else
		{
			rev(s);
                        ans[0]='\0';
			for(i=0;s[i];i++)
			{
				sprintf(temp,"%d",s[i]);
				rev(temp);
				strcat(ans,temp);
			}
		}
		printf("%s\n",ans);
		free(ans);
	}
	return 0;
}













