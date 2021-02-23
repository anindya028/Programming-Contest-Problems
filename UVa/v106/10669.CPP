#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long unsigned __int64
//#define Long unsigned long long
#define MAX 1000
struct bigint
{
	char num[MAX];
	int len;
}big[3];
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
int comparenum(bigint num1,bigint num2)
{
/*	return values:
		1 : if num1 > num2
		0 : if num1 = num2
	   -1 : if num1 < num2
*/
	int i,a,b;
	if(num1.len > num2.len)
		return 1;
	else if(num1.len < num2.len)
		return -1;
	else
	{
		for(i=num1.len-1;i>=0;i--)
		{
			a=getvalue(num1.num[i]);
			b=getvalue(num2.num[i]);
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
	return;
}
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
void swapstrs(bigint s1,bigint s2)
{   //swap two strings
	bigint tmp;
	tmp=s1;
	s1=s2;
	s2=tmp;
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
bigint multiply(int base,bigint num1,bigint num2)
{
	bigint ans;
	int i,j,a,b,carry,tot,gar;
	myset(ans.num,MAX,'\0');
	ans.num[0]='0';
	for(i=0;i<num1.len;i++)
	{
		a=getvalue(num1.num[i]);
		carry=0;
		for(j=0;j<num2.len || carry;j++)
		{
			if(j<num2.len)
				b=getvalue(num2.num[j]);
			else
				b=0;
			tot=a*b+carry;
			if(ans.num[i+j])
				tot+=getvalue(ans.num[i+j]);
			ans.num[i+j]=setvalue(tot%base);
			carry=tot/base;
		}
	}
	ans.num[i+j-1]='\0';
	gar=cuttrzero(ans.num);
	ans.len=strlen(ans.num);
	return ans;
}
int main()
{
	Long n;
	char s[100];
	int i;
	big[0].num[0]='3';
	bigint three[70];
	three[0].num[0]='1';
	three[0].num[1]=big[0].num[1]='\0';
	three[0].len=big[0].len=1;
	for(i=1;i<65;i++)
		three[i]=multiply(10,big[0],three[i-1]);
	for(i=1;i<65;i++)
		strreverse(three[i].num);
	while(scanf("%I64u",&n)==1)
	{
		if(!n)break;
		n=n-1;
		i=0;
		if(!n)
		{
			printf("{ }\n");
			continue;
		}
		while(n)
		{
			if(n%2)s[i]='1';
			else s[i]='0';
			i++;
			n/=2;
		}
		s[i]='\0';
		//strreverse(s);
		for(i=0;s[i];i++)
			if(s[i]=='1')
			{
				printf("{ %s",three[i].num);
				break;
			}
		for(i++;s[i];i++)
			if(s[i]=='1')
				printf(", %s",three[i].num);
		printf(" }\n");
	}
	return 0;
}













