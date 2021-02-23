#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
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
	sum.len=strlen(sum.num);
	return sum;
}
bigint substract(int base,bigint num1,bigint num2)
{
	bigint ans;
	int i,a,b,take=0,maxlen,flag=0,lzr;
	if(comparenum(num1,num2)==-1)
	{
		swapstrs(num1,num2);
		flag=1;
	}
	if(num1.len>num2.len)
		maxlen=num1.len;
	else
		maxlen=num2.len;
	for(i=0;i<maxlen;i++)
	{
		if(i<num1.len)
			a=getvalue(num1.num[i]);
		else
			a=0;
		if(i<num2.len)
			b=getvalue(num2.num[i]);
		else
			b=0;
		b+=take;
		if(b==base)
		{
			b=0;
			take=1;
		}
		else if(a < b)
		{
			a+=base;
			take=1;
		}
		else
			take=0;
		ans.num[i]=setvalue((a-b) % base);
	}
	ans.num[i]='\0';
	lzr=cuttrzero(ans.num);
	if(flag==1)
		ans.num[i-lzr]='-';
	ans.num[i-lzr+flag]='\0';
	ans.len=strlen(ans.num);
	return ans;
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
bigint divide(int base,bigint num1,bigint num2)
{
	bigint ans;
	int i,j,garb;
	bigint tmp,s,gunfall;
	s.num[0]='\0';
	s.len=strlen(s.num);
	for(i=0;i<num1.len;i++)
	{
		tmp.num[0]=num1.num[num1.len-1-i];
		tmp.num[1]='\0';
		tmp.len=strlen(tmp.num);
		strreverse(s.num);
		strcat(s.num,tmp.num);
		strreverse(s.num);
		cuttrzero(s.num);
		s.len=strlen(s.num);
		for(j=base-1;j>=0;j--)
		{
			tmp.num[0]=setvalue(j);
			tmp.num[1]='\0';
			tmp.len=strlen(tmp.num);
			//myset(gunfall.num,MAX,'\0');
			gunfall=multiply(base,tmp,num2);
			if(comparenum(s,gunfall) >= 0)
			{
				s=substract(base,s,gunfall);
				break;
			}
		}
		ans.num[i]=setvalue(j);
	}
	ans.num[i]='\0';
	strreverse(ans.num);
	garb=cuttrzero(ans.num);
	ans.len=strlen(ans.num);
	return ans;
}
bigint mod(int base,bigint num1,bigint num2)
{
	bigint s1,s2,remainder;
	myset(s1.num,MAX,'\0');
	myset(s2.num,MAX,'\0');
	s1=divide(base,num1,num2);
	s2=multiply(base,num2,s1);
	remainder=substract(base,num1,s2);
	remainder.len=strlen(remainder.num);
	return remainder;
}
bigint getGCD(int base,bigint num1,bigint num2)
{
	int garb;
	bigint x1,x2,gcd;
	gcd.num[0]='\0';
	x1=num1;
	x2=num2;
	while(1)
	{
		gcd=mod(base,x1,x2);
		garb=cuttrzero(gcd.num);
		if(strcmp(gcd.num,"0")==0)
			break;
		x1=x2;
		x2=gcd;
	}
	gcd=x2;
	return gcd;
}
int main()
{
	int n,i; 
	char op[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%s",big[0].num,op,big[1].num);
		strreverse(big[0].num);
		strreverse(big[1].num);
		big[0].len=strlen(big[0].num);
		big[1].len=strlen(big[1].num);
		big[2]=getGCD(10,big[0],big[1]);
		big[0]=divide(10,big[0],big[2]);
		big[1]=divide(10,big[1],big[2]);
		strreverse(big[0].num);
		strreverse(big[1].num);
		printf("%s / %s\n",big[0].num,big[1].num);
	}
	return 0;
}













