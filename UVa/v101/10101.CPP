#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
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
int cuttrzero(char *num){   //clear trailing zeros
	int i,count=0,len;
	len=strlen(num);
	for(i=len-1;i>0;i--){
		if(num[i]=='0'){
			num[i]='\0';
			count++;
		}
		else
			break;
	}
	return count;			//number of zeros been cut
}

int main()
{
	char s[20],num[100];
	int i,cs=0,len,j,freq;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		freq=0;
		for(i=0;s[i];i++)
			if(!(s[i]-'0'))freq++;
		if(len==freq)
		{
			printf("%4d. 0\n",++cs);
			continue;
		}
       	rev(s);
		cuttrzero(s);
		rev(s);
		len=strlen(s);
		for(i=len-1,j=0;i>=0;i--)
		{
			if((len-i)==10&&(s[i+1]=='0'&&s[i+2]=='0'))
			{
				if(num[j-1]!=' ')num[j]=' ';
				j++;
				num[j]='i';
				num[j+1]='t';
				num[j+2]='u';
				num[j+3]='k';
				num[j+4]=' ';
				j+=5;
			}
			if(i==(len-1))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				num[j]=s[i];
				j++;
                        }
			else if(i==(len-2))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-3))
			{
				if(s[i]=='0')continue;
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='a';
					num[j+2]='t';
					num[j+3]='a';
					num[j+4]='h';
					num[j+5]='s';
					num[j+6]=' ';
					num[j+7]=s[i];
					j+=8;
				}
				else
				{
					num[j]='a';
					num[j+1]='t';
					num[j+2]='a';
					num[j+3]='h';
					num[j+4]='s';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
			}
			else if(i==(len-4))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='r';
					num[j+2]='a';
					num[j+3]='j';
					num[j+4]='a';
					num[j+5]='h';
					num[j+6]=' ';
					num[j+7]=s[i];
					j+=8;
				}
				else
				{
					num[j]='r';
					num[j+1]='a';
					num[j+2]='j';
					num[j+3]='a';
					num[j+4]='h';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
			}
			else if(i==(len-5))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-6))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='h';
					num[j+2]='k';
					num[j+3]='a';
					num[j+4]='l';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
				else
				{
					num[j]='h';
					num[j+1]='k';
					num[j+2]='a';
					num[j+3]='l';
					num[j+4]=' ';
					num[j+5]=s[i];
					j+=6;
				}
			}
			else if(i==(len-7))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-8))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='i';
					num[j+2]='t';
					num[j+3]='u';
					num[j+4]='k';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
				else
				{
					num[j]='i';
					num[j+1]='t';
					num[j+2]='u';
					num[j+3]='k';
					num[j+4]=' ';
					num[j+5]=s[i];
					j+=6;
				}
			}
			else if(i==(len-9))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-10))
			{
				if(s[i]=='0')continue;
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='a';
					num[j+2]='t';
					num[j+3]='a';
					num[j+4]='h';
					num[j+5]='s';
					num[j+6]=' ';
					num[j+7]=s[i];
					j+=8;
				}
				else
				{
					num[j]='a';
					num[j+1]='t';
					num[j+2]='a';
					num[j+3]='h';
					num[j+4]='s';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
			}
			else if(i==(len-11))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='r';
					num[j+2]='a';
					num[j+3]='j';
					num[j+4]='a';
					num[j+5]='h';
					num[j+6]=' ';
					num[j+7]=s[i];
					j+=8;
				}
				else
				{
					num[j]='r';
					num[j+1]='a';
					num[j+2]='j';
					num[j+3]='a';
					num[j+4]='h';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
			}
			else if(i==(len-12))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-13))
			{
				if(s[i]=='0')
				{
					if((i-1)>=0)
					{
						if(s[i-1]=='0')continue;
					}
				}
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='h';
					num[j+2]='k';
					num[j+3]='a';
					num[j+4]='l';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
				else
				{
					num[j]='h';
					num[j+1]='k';
					num[j+2]='a';
					num[j+3]='l';
					num[j+4]=' ';
					num[j+5]=s[i];
					j+=6;
				}
			}
			else if(i==(len-14))
			{
				if(s[i]=='0')continue;
				num[j]=s[i];
				j++;
			}
			else if(i==(len-15))
			{
				if(s[i]=='0')continue;
				if(num[j-1]!=' ')
				{
					num[j]=' ';
					num[j+1]='i';
					num[j+2]='t';
					num[j+3]='u';
					num[j+4]='k';
					num[j+5]=' ';
					num[j+6]=s[i];
					j+=7;
				}
				else
				{
					num[j]='i';
					num[j+1]='t';
					num[j+2]='u';
					num[j+3]='k';
					num[j+4]=' ';
					num[j+5]=s[i];
					j+=6;
				}
			}
		}
		num[j]='\0';
		rev(num);
		if(num[strlen(num)-1]==' ')num[strlen(num)-1]='\0';
		printf("%4d. %s\n",++cs,num);
		num[0]='\0';
        }
	return 0;
}
