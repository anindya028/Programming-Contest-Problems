#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
char num[]={"0123456789ABCDEF"};
unsigned long long ans;
char s[100],c[100];
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
void  cutldzero(char *num){	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return ;			//number of zeros been cut
}
int legal(int base)
{
	cutldzero(s);
	int i=0,len=strlen(s);
	for(;s[i];i++)
		if(isalpha(s[i]))
		{
			if((s[i]-'A'+10)>=base)return 0;
			ans+=((unsigned long long)(s[i]-'A'+10)*(unsigned long long)pow(base,len-i-1));
		}
		else
		{
			if((s[i]-'0')>=base)return 0;
			ans+=((unsigned long long)(s[i]-'0')*(unsigned long long)pow(base,len-i-1));
		}
	return 1;
}
void convert(int base)
{
	int i=0;
	while(ans)
	{
		c[i]=num[ans%base];
		ans/=base;
		i++;
	}
	for(;i<7;i++)c[i]=' ';
	c[i]='\0';
	rev(c);
	return;
}
int main()
{
	int n1,n2;
	while(scanf("%s%d%d",s,&n1,&n2)==3)
	{
        	ans=0;
		if(legal(n1))
		{
			if(!ans)
			{
				printf("%7llu\n",ans);
				continue;
			}
			if(n2==10)
			{
				if(ans<10000000)printf("%7llu\n",ans);
				else printf("  ERROR\n");
			}
			else
			{
				convert(n2);
				if(strlen(c)>7)printf("  ERROR\n");
				else printf("%s\n",c);
			}
                }
	}
	return 0;
}













