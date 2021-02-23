#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define MAX 200
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
	bigint atp[16][151],ans,tmp;
	int i,j,n,a;
	for(i=1;i<=15;i++)
	{
        sprintf(atp[i][1].num,"%d",i);
		atp[i][1].len=strlen(atp[i][1].num);
		strreverse(atp[i][1].num);
		big[1]=atp[i][1];
        for(j=2;j<=150;j++)
	    {
			big[0]=atp[i][j-1];
			atp[i][j]=multiply(10,big[0],big[1]);
		}
	}
	while(scanf("%d%d",&n,&a)==2)
	{
		if(!a)
		{
			printf("0\n");
			continue;
		}
		ans.num[0]='0';
		ans.num[1]='\0';
		ans.len=1;
		for(i=1;i<=n;i++)
		{
			sprintf(tmp.num,"%d",i);
			tmp.len=strlen(tmp.num);
			strreverse(tmp.num);
			big[2]=multiply(10,atp[a][i],tmp);
			big[1]=add(10,ans,big[2]);
			ans=big[1];
		}
		strreverse(ans.num);
		printf("%s\n",ans.num);
	}
	return 0;
}













