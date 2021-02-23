#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 400
struct bigint
{
	char num[MAX];
	int len;
}big[3];
bigint fib[1505],cum[1505],ans[1505],one;
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
bigint strreverse(bigint s1)
{
	int i;
	char tmp;
	for(i=0;i < s1.len/2;i++)
	{
		tmp=s1.num[i];
		s1.num[i]=s1.num[s1.len-1-i];
		s1.num[s1.len-1-i]=tmp;
	}
	return s1;
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
bigint add(int base,bigint num1,bigint num2)
{
	bigint sum;
	int i,a,b,carry=0,maxlen;
	if(num1.len>num2.len)
		maxlen=num1.len;
	else
		maxlen=num2.len;
	for(i=0;i<maxlen || carry;i++)
	{
		if(i<num1.len)	
			a=getvalue(num1.num[i]);
		else
			a=0;
		if(i<num2.len)
			b=getvalue(num2.num[i]);
		else
			b=0;
		sum.num[i]=setvalue((a+b+carry) % base);
		carry=(a+b+carry) / base;
	}
	sum.num[i]='\0';
	sum.len=i;
	return sum;
}
bigint divide_by_int(bigint num1,int d)
{
	bigint s1;
	int i,a,b,carry,j;
	num1=strreverse(num1);
	for(i=carry=j=0;i<num1.len;i++)
	{
		a=carry*10+num1.num[i]-'0';
		b=a/d;
		s1.num[j]=b+'0';
		j++;
		carry=a-b*d;
	}
	s1.num[j]='\0';
	s1.len=j;
	s1=strreverse(s1);
	cuttrzero(s1.num);
	s1.len=strlen(s1.num);
	return s1;
}
int main()
{
	int i,n,cs=0;
	one.num[0]='1';
	one.num[1]='\0';
	one.len=1;
	fib[1]=fib[2]=cum[2]=ans[2]=one;
	ans[1].num[0]='0';
	ans[1].num[1]='\0';
	ans[1].len=1;
	for(i=3;i<=1503;i++)
	{
		fib[i]=add(10,fib[i-1],fib[i-2]);
		cum[i]=add(10,cum[i-1],fib[i]);
		big[0]=add(10,fib[i],one);
		big[1]=divide_by_int(big[0],2);
		ans[i]=add(10,cum[i-1],big[1]);
	}
	for(i=2;i<=1503;i++)
		ans[i]=strreverse(ans[i]);
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("Set %d:\n%s\n",++cs,ans[n].num);
	}
	return 0;
}













