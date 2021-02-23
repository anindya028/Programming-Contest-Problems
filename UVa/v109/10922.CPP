#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
char s[1005],temp[10];
int sum,i,degree;
void strreverse(char *dest){
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++){
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
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

int cutldzero(char *num){	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			//number of zeros been cut
}
void main()
{
	while(scanf("%s",s)==1)
	{
		if(s[0]=='0'&&s[1]=='\0')break;
		cutldzero(s);
                degree=0;
		for(i=0,sum=0;s[i];i++)
		{
			sum+=(s[i]-'0');
		}
		if(sum%9==0)
		{
			degree=1;
			if(strlen(s)==1)
			{
				printf("%s is a multiple of 9 and has 9-degree %d.\n",s,degree);
				continue;
			}
			while(1)
			{
				sprintf(temp,"%d",sum);
				if(strlen(temp)==1)break;
				sum=i=0;
				while(temp[i])
				{
					sum+=(temp[i]-'0');
					i++;
				}
				if(sum%9==0)degree++;
				else break;
				
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n",s,degree);
		}
		else printf("%s is not a multiple of 9.\n",s);
        }
}













