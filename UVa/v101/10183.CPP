#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000
char num[3][MAX];
char fib[500][185];
char a[110],b[110];
int getvalue(char s)
{
	if(s >= '0' && s <= '9')
		return s - '0';
	else if(s >='A' && s <= 'Z')
		return s - 'A' + 10;
	else if(s >='a' && s <= 'z')
		return s - 'a' + 36;
	else
		return NULL;
}

char setvalue(int s)
{
	if(s < 10)
		return s + '0';
	else if(s < 36)
		return s + 'A' - 10;
	else if(s < 62)
		return s + 'a' - 36;
	else
		return NULL;
}

int comparenum(char *num1,char *num2)
{
/*	return values:
		1 : if num1 > num2
		0 : if num1 = num2
	   -1 : if num1 < num2
*/
	int i,len1,len2,a,b;
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1 > len2)
		return 1;
	else if(len1 < len2)
		return -1;
	else{
		for(i=0;num1[i];i++)
		{
			a=getvalue(num1[i]);
			b=getvalue(num2[i]);
			if(a > b)
				return 1;
			else if(a < b)
				return -1;
		}
		return 0;
	}
}
void myset(char *dest,int range,char value)
{
	int i;
	for(i=0;i<range;i++)
		dest[i]=value;
}
void strreverse(char *dest)
{
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++)
	{
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
}
void swapstrs(char *s1,char *s2)
{   //swap two strings
	int i,len1,len2,maxlen;
	char tmp;
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1>len2)
		maxlen=len1;
	else
		maxlen=len2;
	for(i=0;i<maxlen;i++)
	{
		tmp=s1[i];
		s1[i]=s2[i];
		s2[i]=tmp;
	}
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
	return count;			//number of zeros been cut
}
int cutldzero(char *num)
{	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			//number of zeros been cut
}
void add(int base,char *num1,char *num2,char *sum)
{
	int i,a,b,carry=0,len1,len2,maxlen;
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1>len2)	maxlen=len1;
	else			maxlen=len2;
	for(i=0;i<maxlen || carry;i++)
	{
		if(i<len1)	a=getvalue(num1[i]);
		else		a=0;
		if(i<len2)	b=getvalue(num2[i]);
		else		b=0;
		sum[i]=setvalue((a+b+carry) % base);
		carry=(a+b+carry) / base;
	}
	sum[i]='\0';
}
void fibgen(void)
{
	int i;
	fib[0][0]='0';
	fib[0][1]='\0';
	fib[1][0]='1';
	fib[1][1]='\0';
	fib[2][0]='2';
	fib[2][1]='\0';
	for(i=3;i<499;i++)
	{
		strcpy(num[0],fib[i-2]);
		strcpy(num[1],fib[i-1]);
		strreverse(num[0]);
		strreverse(num[1]);
		add(10,num[0],num[1],num[2]);
		strreverse(num[2]);
		strcpy(fib[i],num[2]);
		num[2][0]='\0';
	}
	return;
}
int binsearchlow(void)
{
	int low=0,high=498,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(comparenum(fib[mid],a)<0)low=mid;
		else high=mid-1;
	}
	if(comparenum(fib[low],a)<0)return low;
	else return 0;
}
int binsearchhigh(void)
{
	int low=0,high=498,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(comparenum(fib[mid],b)>0)high=mid;
		else low=mid+1;
	}
	if(comparenum(fib[low],b)>0)return low;
	else return 0;
}
int main()
{
	int low,high;
	char zero[5]="0";
	fibgen();
	while(scanf("%s%s",a,b)==2)
	{
		if(a[0]=='0' && a[1]=='\0' && b[0]=='0' && b[1]=='\0')break;		
		low=binsearchlow();
		high=binsearchhigh();
		printf("%d\n",high-low-1);
	}
	return 0;
}













