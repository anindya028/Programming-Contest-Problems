#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 300
struct bigint
{
	char num[MAX];
	int len;
}big[3];
void strreverse(char *dest,int len)
{
	int i;
	char tmp;
	for(i=0;i < len/2;i++)
	{
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
	return;
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
			a=num1.num[i]-'0';
		else
			a=0;
		if(i<num2.len)
			b=num2.num[i]-'0';
		else
			b=0;
		sum.num[i]=(a+b+carry) % base +'0';
		carry=(a+b+carry) / base;
	}
	sum.num[i]='\0';
	sum.len=strlen(sum.num);
	return sum;
}
int main()
{
	bigint ans[1001],dif[1001],fib[1001];
	int i,n,t;
	ans[1].num[0]=fib[1].num[0]=fib[2].num[0]='1';
	ans[2].num[0]='3';
	dif[2].num[0]='2';
	ans[1].num[1]=ans[2].num[1]=dif[2].num[1]=fib[1].num[1]=fib[2].num[1]='\0';
	ans[1].len=ans[2].len=dif[2].len=fib[1].len=fib[2].len=1;
	for(i=3;i<1001;i++)
	{
		fib[i]=add(10,fib[i-1],fib[i-2]);
		dif[i]=add(10,dif[i-1],fib[i]);
		ans[i]=add(10,ans[i-1],dif[i]);
	}
	for(i=3;i<1001;i++)
		strreverse(ans[i].num,ans[i].len);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		if(n<1)printf("0\n");
		else printf("%s\n",ans[n].num);
	}
	return 0;
}













