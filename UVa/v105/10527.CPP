#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define MAX 2000
struct bigint
{
	char num[MAX];
	int len;
}big[3];
void strreverse(char *dest)
{
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++){
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
	return;
}
int cuttrzero(char *num)
{   //clear trailing zeros
	int i,count=0,len;
	len=strlen(num);
	for(i=len-1;i>0;i--)
	{
		if(num[i]=='0')
		{
			num[i]='\0';
			count++;
		}
		else
			break;
	}
	return count;			
}
int cutldzero(char *num)
{	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			
}
int singlemod(bigint num1,int d)
{
	bigint s1;
	int i,a,b,carry,j;
	for(i=carry=j=0;i<num1.len;i++)
	{
		a=carry*10+num1.num[i]-'0';
		b=a/d;
		s1.num[j]=b+'0';
		j++;
		carry=a-b*d;
	}
	s1.num[j]='\0';
	cutldzero(s1.num);
	s1.len=strlen(s1.num);
	if(!carry)
		big[0]=s1;
	return carry;
}
int main()
{
	char s[MAX];
	char zero[]={"0"};
    char one[]={"1"};
    int *freq,i;
	while(scanf("%s",s)==1)
	{
		if(s[0]=='-'&&s[1]=='1')break;
		if(strlen(s)==1)
		{
			sscanf(s,"%d",&i);
			printf("%d\n",10+i);
			continue;
        }
		strcpy(big[0].num,s);
		big[0].len=strlen(big[0].num);
		big[1].len=1;
		freq=(int *)calloc(10,sizeof(int));
		for(i=9;i>1;i--)
		{
			while(!singlemod(big[0],i))
				freq[i]++;
		}
		if(strcmp(one,big[0].num))printf("There is no such number.\n");
		else
		{
			for(i=2;i<=9;i++)
			{
                while(freq[i])
				{
					printf("%d",i);
					freq[i]--;
				}
			}
            printf("\n");
		}
		free(freq);
    }
	return 0;
}













